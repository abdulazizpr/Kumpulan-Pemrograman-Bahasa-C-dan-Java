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

void add(int waktu,char nama[],queue *Q){
	
	elemen *elmt;
	elmt = (elemen *) malloc (sizeof (elemen));
	elmt->elmt.waktu = waktu;
	strcpy(elmt->elmt.nama, nama);
	
	elmt->next = NULL;
	if((*Q).first == NULL) (*Q).first = elmt;
	else (*Q).last->next = elmt;
	
	(*Q).last = elmt;
	elmt = NULL;
}

void del(queue *Q){
	if((*Q).first != NULL){
		/*jika queue tidak kosong*/
		
		elemen* hapus = (*Q).first;
        (*Q).first = (*Q).first -> next;
        hapus -> next = NULL;
        free(hapus);
	}else{
		 elemen* hapus = (*Q).first;
        (*Q).first = NULL;
        (*Q).last = NULL;
        free(hapus);
	}
}

void printQueue(queue Q){
	
	if(Q.first != NULL){
		
		elemen *elmt = Q.first;
		int i = 1;
		while(elmt != NULL){
			printf("%s\n",elmt->elmt.nama);
			elmt = elmt->next;
			i++;
		}
		
	}else{
		/*proses jika queue kosong*/
		printf("queue kosong\n");
	}
	
}

void cekwaktu(queue *Q,int waktu){
	
	if((*Q).first != NULL){
		
        int status = 0;
		while(isEmpty(*Q)!=1 && status==0){
			if(waktu<=0){
				status = 1;
			}else{
				waktu=waktu-(*Q).first->elmt.waktu;
				del(Q);
			}
        }
		
		if(isEmpty(*Q)!=1)
			printQueue(*Q);
		else
			printf("end\n");
	
	}
	
}

