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

void addFirst(char kode_barang[],char jenis_barang[],int jumlah,list *L){
	
	elemen *baru;
	baru = (elemen *) malloc (sizeof (elemen));
	strcpy(baru->elmt.kode_barang, kode_barang);
	strcpy(baru->elmt.jenis_barang, jenis_barang);
	baru->elmt.jumlah = jumlah;
	
	if((*L).first == NULL) baru->next = NULL;
	else baru->next = (*L).first; 
	
	(*L).first = baru;
	baru = NULL;
	
}

void addAfter(elemen *prev,char kode_barang[],char jenis_barang[],int jumlah,list *L){
	
	elemen *baru;
	baru = (elemen *) malloc (sizeof (elemen));
	strcpy(baru->elmt.kode_barang, kode_barang);
	strcpy(baru->elmt.jenis_barang, jenis_barang);
	baru->elmt.jumlah = jumlah;
	
	if(prev->next == NULL) baru->next = NULL;
	else baru->next = prev->next;
	
	prev->next = baru;
	baru = NULL;

}

void addLast(char kode_barang[],char jenis_barang[],int jumlah,list *L){
	
	//jika list adalah list kosong
	if((*L).first == NULL) addFirst(kode_barang,jenis_barang,jumlah,L);
	else{	
		//jika list tidak kosong
		//mencari elemen terakhir list
		
		elemen *prev = (*L).first;
		//mencari elemen terakhir list
		while(prev->next != NULL) prev = prev->next; //iterasi
		
		addAfter(prev, kode_barang, jenis_barang, jumlah, L);
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
	
			printf("%s %s %d\n",elmt->elmt.kode_barang,elmt->elmt.jenis_barang,elmt->elmt.jumlah);
			//iterasi
			elmt = elmt->next;
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