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

int countElementK(eBaris L){
	
	int hasil = 0;
	if(L.col != NULL){			//list tidak kosong
		
		eKolom *elmt;
		elmt = L.col; //inisialisasi
		
		while(elmt != NULL){
			hasil++;
			elmt = elmt ->next;	//iterasi
		}
		
	}
	
	return hasil;
}

void addFirstB(int angka,list *L){
	
	eBaris *elmt = (eBaris *) malloc (sizeof (eBaris));
	elmt->elmt.angka = angka;
	
	elmt->next = (*L).first;
	elmt->col = NULL;
	(*L).first = elmt;
	elmt = NULL;
	
}

void addAfterB(eBaris *prev,int angka){
	
	eBaris *elmt = (eBaris *) malloc (sizeof (eBaris));
	elmt->elmt.angka = angka;
	
	elmt->next = prev->next;
	elmt->col = NULL;
	prev->next = elmt;
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


void addFirstK(char kata[],eBaris *L){
	
	eKolom *elmt;
	elmt = (eKolom *) malloc (sizeof (eKolom));
	strcpy(elmt->elmt.kata, kata);
	
	elmt->next = (*L).col;
	(*L).col = elmt;
	elmt = NULL;
	
}


void addAfterK(eKolom *prev,char kata[]){
	
	eKolom *elmt;
	elmt = (eKolom *) malloc (sizeof (eBaris));
	strcpy(elmt->elmt.kata,kata);
	
	elmt->next = prev->next;
	prev->next = elmt;
	elmt = NULL;
	
}

void addLastK(char kata[],eBaris *L){
	
	if((*L).col == NULL) addFirstK(kata, L);	//jika list kosong
	else{		//jika list tidak kosong
		eKolom *elmt;
		elmt = (eKolom *) malloc (sizeof (eKolom));
		strcpy(elmt->elmt.kata, kata);
		elmt->next = NULL;
		
		eKolom *last = (*L).col;
		while(last->next != NULL) last = last->next;  //iterasi
		
		last->next = elmt;
		elmt = NULL;
	}

}

void delFirstB(list *L){
	
	if((*L).first != NULL){
		eBaris *elmt = (*L).first;
		(*L).first = (*L).first->next;
		elmt->next = NULL;
		free(elmt);
	}
	
}

void delFirstK(eBaris *L){
	
	if((*L).col != NULL){
		
		eKolom *elmt = (*L).col;
		(*L).col = (*L).col->next;
		elmt->next = NULL;
		free(elmt);
		
	}
	
}

void delAfterB(eBaris *prev){
	
	eBaris *elmt = prev->next;
	prev->next = elmt->next;
	elmt->next = NULL;
	free(elmt);
	
}

void delAfterK(eKolom *prev){
	
	eKolom *elmt = prev->next;
	prev->next = elmt->next;
	elmt->next = NULL;
	free(elmt);
	
}

void delLastB(list *L){
	
	if((*L).first != NULL){
		
		if(countElementB(*L) == 1) delFirstB(L);
		else{
			
			eBaris *last = (*L).first;
			eBaris *before_last;
			
			while(last->next != NULL){
				//iterasi
				before_last = last;
				last = last->next;
			}
			
			before_last->next = NULL;
			free(last);
		}
	}
	
}

void delLastK(eBaris *L){
	
	if((*L).col != NULL){
		
		if(countElementK(*L) == 1) delFirstK(L);
		else{
			
			eKolom *last = (*L).col;
			eKolom *before_last;
			
			while(last->next != NULL){
				//iterasi
				before_last = last;
				last = last->next;
			}
			
			before_last->next = NULL;
			free(last);
		}
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
				printf("-%s\n",eCol->elmt.kata);
				eCol = eCol->next;
			}
			
			elmt = elmt->next;
			i++;
		}
		
	}
	else printf("list kosong\n");
	
}

void delAllB(list *L){
	
	int i;
	if(countElementB(*L) != 0){
		for(i=countElementB(*L);i>=1;i--) delLastB(L);
	}
	
}

void delAllK(eBaris *L){
	
	int i;
	if(countElementK(*L) != 0){
		for(i=countElementK(*L);i>=1;i--) delLastK(L);
	}
	
}

int hitungA(char kata[100]){
	int i,hasil = 0;
	for(i=0;i<strlen(kata);i++) if(kata[i]=='a') hasil++;
	return hasil;
}

eBaris *tambahCariB(int angka,list *L){
	eBaris *baris = NULL;
	if((*L).first==NULL){
		addFirstB(angka,L);
		baris = (*L).first;
	}else{
		
		baris = (*L).first;

		int status = 0;
		
		while(baris->next!=NULL && status==0){
			if(baris->elmt.angka == angka){
				status = 1;
			}else{
				baris = baris->next;
			}
		}
		
		if(baris->elmt.angka==angka){
			status = 1; 
		}
		
		if(status==0){
			addAfterB(baris,angka);
			baris = baris->next;
		}
	}

	return baris;
}