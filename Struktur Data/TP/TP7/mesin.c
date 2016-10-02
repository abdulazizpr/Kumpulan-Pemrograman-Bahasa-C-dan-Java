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

void add(char raptor[],int waktu_mulai,int lama_waktu,queue *Q){
	
	elemen *elmt = (elemen *) malloc (sizeof (elemen));
	strcpy(elmt->elmt.raptor , raptor);
	elmt->elmt.waktu_mulai = waktu_mulai;
	elmt->elmt.lama_waktu = lama_waktu;
	
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
			printf("%s ",elmt->elmt.raptor);
			printf("%d ",elmt->elmt.waktu_mulai);
			printf("%d\n",elmt->elmt.lama_waktu);
			
			elmt = elmt->next;
		}
	
	}else{
		/*proses jika queue kosong*/
		printf("QUEUE KOSONG\n");
	}
	
}

void add_prioritas(char raptor[],int waktu_mulai,int lama_waktu,int prioritas,queue *Q){
	
	elemen *elmt = (elemen *) malloc (sizeof (elemen));
	strcpy(elmt->elmt.raptor , raptor);
	elmt->elmt.waktu_mulai = waktu_mulai;
	elmt->elmt.lama_waktu = lama_waktu;
	
	if(isEmpty(*Q)==1){
		(*Q).first = elmt;
		(*Q).last = elmt;
		elmt->next = NULL;
	}else{
		if(countElement(*Q) < prioritas){
			(*Q).last->next = elmt;
			(*Q).last = elmt;
		}else{
			if(prioritas == 1){
				elmt->next = (*Q).first;
				(*Q).first = elmt;
			}else{
				int i;
				elemen *maju = (*Q).first;
				for(i=2;i<prioritas;i++){
					maju = maju->next;
				}
				
				elmt->next = maju->next;
				maju->next = elmt;
			}
		}
		elmt = NULL;
	}
	
}
