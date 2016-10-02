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

void addFirst(char barang[],int stok,list *L){
	
	elemen *baru;
	baru = (elemen *) malloc (sizeof (elemen));
	strcpy(baru->elmt.barang, barang);
	baru->elmt.stok = stok;
	
	if((*L).first == NULL) baru->next = NULL;
	else baru->next = (*L).first; 
	
	(*L).first = baru;
	baru = NULL;
	
}

void addAfter(elemen *prev,char barang[],int stok,list *L){
	
	elemen *baru = (elemen *) malloc (sizeof (elemen));
	strcpy(baru->elmt.barang, barang);
	baru->elmt.stok = stok;
	
	if(prev->next == NULL) baru->next = NULL;
	else baru->next = prev->next;
	
	prev->next = baru;
	baru = NULL;

}

void addLast(char barang[],int stok,list *L){
	
	//jika list adalah list kosong
	if((*L).first == NULL) addFirst(barang,stok,L);
	else{	
		//jika list tidak kosong
		//mencari elemen terakhir list
		
		elemen *prev = (*L).first;
		//mencari elemen terakhir list
		while(prev->next != NULL) prev = prev->next; //iterasi
		
		addAfter(prev, barang, stok, L);
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
			printf("%s %d\n",elmt->elmt.barang,elmt->elmt.stok);
			
			
			//iterasi
			elmt = elmt->next;
			i++;
		}
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

void hapus_barang(int jumlah_stok,list *L){
	
	if((*L).first != NULL){
		
		if((*L).first->elmt.stok < jumlah_stok) delFirst(L);
		else{
			elemen *awal = (*L).first;
			elemen *prev;
			int status = 0;
			
			while(awal->next!=NULL){
				if(awal->next->elmt.stok < jumlah_stok){
					prev = awal;
					status = 1; 
				}
				
				
				awal = awal->next;
			}
			if(status==1) delAfter(prev,L);
		}
	}
	
}