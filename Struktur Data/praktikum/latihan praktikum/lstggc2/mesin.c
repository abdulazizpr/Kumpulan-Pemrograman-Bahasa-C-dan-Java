#include "header.h"

void createList(list *L){ (*L).first = NULL;}

int countElment(list L){
	
	int hasil = 0;
	
	if(L.first != NULL){		//list tidak kosong
		
		elemen *elmt;
		
		elmt = L.first;         //inisialisasi
		
		while(elmt != NULL){	//proses
			hasil++;
			elmt = elmt->next;	//iterasi
		}
	}
	
	return hasil;
}

void addFirst(int angka,list *L){
	
	elemen *baru;
	baru = (elemen *) malloc (sizeof (elemen));
	baru->elmt.angka = angka;
	
	if((*L).first == NULL) baru->next = NULL;
	else baru->next = (*L).first; 
	
	(*L).first = baru;
	baru = NULL;
	
}

void addAfter(elemen *prev,int angka,list *L){
	
	elemen *baru = (elemen *) malloc (sizeof (elemen));
	baru->elmt.angka = angka;
	
	if(prev->next == NULL) baru->next = NULL;
	else baru->next = prev->next;
	
	prev->next = baru;
	baru = NULL;

}

void addLast(int angka,list *L){
	
	//jika list adalah list kosong
	if((*L).first == NULL) addFirst(angka,L);
	else{	
		//jika list tidak kosong
		//mencari elemen terakhir list
		
		elemen *prev = (*L).first;
		//mencari elemen terakhir list
		while(prev->next != NULL) prev = prev->next; //iterasi
		
		addAfter(prev, angka, L);
	}
	
}

void delFirst(list *L){
	
	if((*L).first != NULL){			//jika bukan list kosong
		elemen *hapus = (*L).first;
		
		if(countElment(*L)==1) (*L).first = NULL;
		else {
			(*L).first = (*L).first->next; 
			hapus->next = NULL;
		}
		
		free(hapus);
	}
	
}

void delAfter(elemen *prev,list *L){
	
	elemen *hapus = prev->next;
	if(hapus != NULL){
		if(hapus->next == NULL) prev->next = NULL;
		else{ 
			prev->next = hapus->next;
			hapus->next = NULL;
		}	
		free(hapus);
	}
	
}

void delLast(list *L){			
	
	if((*L).first != NULL){
		//jika list tidak list kosong
		if(countElment(*L) == 1) delFirst(L);	//list hanya satu elemen
		else{
			//mencari elemen terakhir
			elemen *last = (*L).first;
			elemen *prev;
			
			while(last->next != NULL){
				//iterasi
				prev = last;
				last = last->next;
			}
			
			delAfter(prev, L);
		}
	}
	
}


void printElement(list L){
	
	if(L.first != NULL){			//jika list tidak kosong
		elemen *elmt = L.first;		//inisialisasi
		
		int i = 1;
		while(elmt != NULL){
			//proses
			printf("%d",elmt->elmt.angka);
			
			if(elmt->next!=NULL){
				printf(", ");
			}
			
			//iterasi
			elmt = elmt->next;
			i++;
		}
		printf("\n");
	}
	//proses jika list kosong
	else printf("List Kosong\n");
}

void delAll(list *L){
	
	if(countElment(*L) != 0){
		int i;
		for(i=countElment(*L);i>=1;i--) delLast(L);
	}
	
}
