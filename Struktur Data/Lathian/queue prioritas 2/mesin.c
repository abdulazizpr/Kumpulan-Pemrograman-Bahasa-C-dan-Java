#include "header.h"

void createEmpty(queue *Q){
	(*Q).first = NULL;
	(*Q).last = NULL;
}

int isEmpty(queue Q){
	int hasil = 0;
	
	if(Q.first == NULL) hasil = 1;
	
	return hasil;
}

int countElement(queue Q){
	
	int hasil = 0;
	if(Q.first != NULL){
		/*queue tidak kosong*/
		
		elemen *elmt = Q.first;
		while(elmt != NULL){
			/*proses*/
			hasil++;
			
			/*iterasi*/
			elmt = elmt->next;
		}
	}
	
	return hasil;
}

void add(char huruf,queue *Q){
	
	elemen *elmt = (elemen *) malloc (sizeof (elemen));
	elmt->elmt.huruf = huruf;
	elmt->next = NULL;
	if((*Q).first == NULL) (*Q).first = elmt;
	else (*Q).last->next = elmt;
	
	(*Q).last = elmt;
	elmt = NULL;
}

void del(queue *Q){
	if((*Q).first != NULL){
		/*jika queue tidak kosong*/
		
		elemen *hapus = (*Q).first;
		
		if(countElement(*Q)==1) createEmpty(Q);
		else{
			(*Q).first = (*Q).first->next;
			hapus->next = NULL;
		}
		
		free(hapus);
	}
}

void printQueue(queue Q){
	
	if(Q.first != NULL){
		
		elemen *elmt = Q.first;
		int i = 1;
		while(elmt != NULL){
			printf("%c",elmt->elmt.huruf);
			if(elmt->next!=NULL){
				printf(" ");
			}
			
			elmt = elmt->next;
		}
		printf("\n");
		
	}else{
		/*proses jika queue kosong*/
		printf("QUEUE KOSONG\n");
	}
	
}

void add_prioritas(char huruf,int prioritas,queue *Q){
	
	elemen *elmt = (elemen *) malloc (sizeof (elemen));
	elmt->elmt.huruf = huruf;
	
	if(isEmpty(*Q)==1){
		(*Q).first = elmt;
		(*Q).last = elmt;
		elmt->next = NULL;
	}else{
		if(countElement(*Q) < prioritas){
			(*Q).last->next = elmt;
			(*Q).last = elmt;
			elmt = NULL;
		}else{
			if(prioritas == 1){
				elmt->next = (*Q).first;
				(*Q).first = elmt;
				elmt = NULL;
			}else{
				int i;
				elemen *maju = (*Q).first;
				for(i=2;i<prioritas;i++){
					maju = maju->next;
				}
				
				elmt->next = maju->next;
				maju->next = elmt;
				elmt = NULL;
			}
			
		}		
	}
	
}

void cekkapasitas(int kapasitas,char huruf,int prioritas,queue *Q){
	
	if(countElement(*Q)==kapasitas){
		printf("tidak masuk\n");
	}else{
		add_prioritas(huruf,prioritas,Q);
		printQueue(*Q);
	}
	
}
