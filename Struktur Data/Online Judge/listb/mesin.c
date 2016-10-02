#include "header.h"

void createList(list *L){ 
	(*L).first = NULL;
	(*L).tail = NULL;
}

int countElement(list L){
	
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

void addFirst(char kata[],list *L){
	
	elemen *baru;
	baru = (elemen *) malloc (sizeof (elemen));
	strcpy(baru->elmt.kata, kata);

	baru->next = NULL;
    baru->prev =  NULL;
	
	if((*L).first == NULL) {		//jika list kosong
		(*L).tail = baru;		
	}else {							//jika list tidak kosong
		(*L).first->prev = baru;
		baru->next = (*L).first;
	} 
	
	(*L).first = baru;
	baru = NULL;
	
}

void addAfter(elemen *prev,char kata[],list *L){
	
	elemen *baru;
	baru = (elemen *) malloc (sizeof (elemen));
	strcpy(baru->elmt.kata, kata);
	
	baru->prev = NULL;
	baru->next = NULL;
	
	if(prev->next != NULL){		//jika baru bukan elemen terakhir
		baru->prev = prev;
		baru->next = prev->next;
		baru->next->prev = baru;
	}else{
		baru->prev = prev;
		baru->next = NULL;
		(*L).tail = baru;
	} 
	
	prev->next = baru;
	baru = NULL;
}

void addLast(char kata[],list *L){
	
	//jika list adalah list kosong
	if((*L).first == NULL) addFirst(kata,L);
	else{	
		//jika list tidak kosong
		elemen *prev = (*L).tail;		
		addAfter(prev, kata, L);
	}
	
}

void delFirst(list *L){
	
	if((*L).first != NULL){			//jika bukan list kosong
		elemen *hapus = (*L).first;
		
		if(countElement(*L)==1){
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
		if(countElement(*L) == 1) delFirst(L);	//list hanya satu elemen
		else{
			elemen *prev = (*L).tail->prev;		
			delAfter(prev, L);
		}
	}
	
}

int panjang_kata(list L){
	
	elemen *awal = L.first;
	
	int hasil = 0;
	while(awal != NULL){
		hasil+=strlen(awal->elmt.kata);
		awal = awal->next;
	}
	
	return hasil;
}

void printElement(list L){
	
	if(L.first != NULL){			//jika list tidak kosong
		elemen *depan = L.first;		//inisialisasi
		elemen *belakang = L.tail;
		
		int i;
		int spasiakhir = panjang_kata(L);
		int spasiakhir2 = panjang_kata(L);
		int spasi_awal = 0;
		while(depan != NULL){
		
			for(i=0;i<spasi_awal;i++) printf(" ");
			printf("%s",depan->elmt.kata);
			
			
			spasiakhir-=strlen(depan->elmt.kata);
			spasiakhir2-=strlen(belakang->elmt.kata);
			
			for(i=0;i<spasiakhir;i++) printf(" ");
			for(i=0;i<spasiakhir2;i++) printf(" ");
			
			printf("%s",belakang->elmt.kata);
			
			
			spasi_awal+=strlen(depan->elmt.kata);
			depan = depan->next;
			belakang = belakang->prev;
			printf("\n");
		}
	}
	//proses jika list kosong
	else printf("List Kosong\n");
}

void delAll(list *L){
	
	if(countElement(*L) != 0){
		int i;
		for(i=countElement(*L);i>=1;i--) delLast(L);
	}
	
}