#include "list.h"

void createList(list *L){ (*L).first = NULL;}

int countElment(list L){
	
	int hasil = 0;
	
	if(L.first != NULL){		//list tidak kosong
		
		elemen *elmt;
		elmt = L.first;
		
		while(elmt != NULL){	//proses
			hasil++;
			elmt = elmt->next;
		}
	}
	
	return hasil;
}

void addFirst(float angka,list *L){
	
	elemen *elmt;
	elmt = (elemen *) malloc (sizeof (elemen));
	elmt->elmt.angka=angka;
	elmt->next = (*L).first;
	(*L).first = elmt;
	elmt = NULL;
	
}

void printElement(list L){
	
	if(L.first != NULL){			//jika list tidak kosong
		elemen *elmt = L.first;		//inisialisasi
		
		int i = 1;
		while(elmt != NULL){
			printf("%.2f\n",elmt->elmt.angka);			
			//iterasi
			elmt = elmt->next;
			i++;
		}
	}
	//proses jika list kosong
	//else printf("list kosong\n");
}