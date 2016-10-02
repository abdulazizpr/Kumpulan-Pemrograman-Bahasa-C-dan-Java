#include "header.h"

void createList(list *L){ 
	(*L).first = NULL;
	(*L).tail = NULL;
}

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

void addFirst(int angka,char kata[],list *L){
	
	elemen *baru;
	baru = (elemen *) malloc (sizeof (elemen));
	baru->elmt.angka = angka;
	strcpy(baru->elmt.kata, kata);
	
	if((*L).first == NULL) {		//jika list kosong
		baru->prev =  NULL;
		baru->next = NULL;
		(*L).tail = baru;		
	}else {							//jika list tidak kosong
		(*L).first->prev = baru;
		baru->prev =  NULL;
		baru->next = (*L).first;
	} 
	
	(*L).first = baru;
	baru = NULL;
	
}

void addAfter(elemen *prev,int angka,char kata[],list *L){
	
	elemen *baru;
	baru = (elemen *) malloc (sizeof (elemen));
	baru->elmt.angka = angka;
	strcpy(baru->elmt.kata, kata);
	
	if(prev->next != NULL){		//jika baru bukan elemen terakhir
		baru->next = prev->next;
		baru->next->prev = baru;
	}else{
		baru->next = NULL;
		(*L).tail = baru;
	} 
	
	baru->prev = prev;
	prev->next = baru;
	baru = NULL;
}

void addLast(int angka,char kata[],list *L){
	
	//jika list adalah list kosong
	if((*L).first == NULL) addFirst(angka,kata,L);
	else{	
		//jika list tidak kosong
		elemen *prev = (*L).tail;		
		addAfter(prev, angka,kata, L);
	}
	
}

void delFirst(list *L){
	
	if((*L).first != NULL){			//jika bukan list kosong
		elemen *hapus = (*L).first;
		
		if(countElment(*L)==1){
			(*L).first = NULL;
			(*L).tail = NULL;
		}else{
			(*L).first = (*L).first->next; 
			hapus->next = NULL;
		}
		
		free(hapus);
	}
	
}

void delAfter(elemen *prev,list *L){
	
	elemen *hapus = prev->next;
	if(hapus != NULL){
		if(hapus->next == NULL){
			(*L).tail = prev;
			prev->next = NULL;
		}else{ 
			prev->next = hapus->next;
			hapus->next->prev = prev;
			hapus->prev = NULL;
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
			elemen *prev = (*L).tail->prev;		
			delAfter(prev, L);
		}
	}
	
}


void printElement(list L){
	
	if(L.first != NULL){			//jika list tidak kosong
		elemen *elmt = L.first;		//inisialisasi
		
		int i = 1;
		while(elmt != NULL){
			printf("%d ",elmt->elmt.angka);
			printf("%s\n",elmt->elmt.kata);
			
			//iterasi
			elmt = elmt->next;
			i++;
		}
	}
	//proses jika list kosong
	else printf("list kosong\n");
}

void printelementohead(list L){
	
	if(L.first != NULL){			//jika list tidak kosong
		elemen *elmt = L.tail;		//inisialisasi
		
		int i = 1;
		while(elmt != NULL){
			printf("%d ",elmt->elmt.angka);
			printf("%s\n",elmt->elmt.kata);
			
			//iterasi
			elmt = elmt->prev;
			i++;
		}
	}
	//proses jika list kosong
	else printf("list kosong\n");
}

void delAll(list *L){
	
	if(countElment(*L) != 0){
		int i;
		for(i=countElment(*L);i>=1;i--) delLast(L);
	}
	
}