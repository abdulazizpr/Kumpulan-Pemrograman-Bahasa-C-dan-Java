#include "header.h"

void createList(list *L){ (*L).first = NULL; }

int countElementB(list L){
	
	int hasil = 0;
	if(L.first != NULL){		//list tidak kosong
		
		eBaris *elmt;
		elmt = L.first; //inisialisasi
		
		while(elmt != NULL){
			hasil++;
			elmt = elmt->next;	//iterasi
		}
	}	
	
	return hasil;
}

void addFirstB(int angka,list *L){
	
	eBaris *elmt;
	elmt = (eBaris *) malloc (sizeof (eBaris));
	elmt->elmt.angka = angka;
	elmt->next = (*L).first;
	elmt->col = NULL;
	(*L).first = elmt;
	elmt = NULL;
	
}

void addFirstK(char angka,eBaris *L){
	
	eKolom *elmt;
	elmt = (eKolom *) malloc (sizeof (eKolom));
	elmt->elmt.angka = angka;
	elmt->next = (*L).col;
	(*L).col = elmt;
	elmt = NULL;
	
}

void addLastB(int angka,list *L){
	
	if((*L).first == NULL) addFirstB(angka, L);	//jika list kosong
	else{		//jika list tidak kosong
		eBaris *elmt;
		elmt = (eBaris *) malloc (sizeof (eBaris));
		elmt->elmt.angka = angka;
		elmt->next = NULL;
		elmt->col = NULL;
		
		eBaris *last = (*L).first;
		while(last->next != NULL) last = last->next;  //iterasi
		
		last->next = elmt;
		elmt = NULL;
	}

}

void addLastK(int angka,eBaris *L){
	
	if((*L).col == NULL) addFirstK(angka, L);	//jika list kosong
	else{		//jika list tidak kosong
		eKolom *elmt;
		elmt = (eKolom *) malloc (sizeof (eKolom));
		elmt->elmt.angka = angka;
		elmt->next = NULL;
		
		eKolom *last = (*L).col;
		while(last->next != NULL) last = last->next;  //iterasi
		
		last->next = elmt;
		elmt = NULL;
	}

}

void printElement(list L){
	
	if(L.first != NULL){
		
		eBaris *elmt = L.first;
		
		int i = 1;
		
		while(elmt != NULL){
			
			printf("%d\n",elmt->elmt.angka);
			
			eKolom *eCol = elmt->col;
			while(eCol != NULL){
				printf("-%d\n",eCol->elmt.angka);
				
				eCol = eCol->next;
			}
		
			elmt = elmt->next;
			i++;
		}
		
	}
	else printf("list kosong\n");
	
}