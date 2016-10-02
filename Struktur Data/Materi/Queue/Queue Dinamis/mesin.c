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

void add(char nim[],char nama[],float nilai,queue *Q){
	
	elemen *elmt = (elemen *) malloc (sizeof (elemen));
	strcpy(elmt->elmt.nim, nim);
	strcpy(elmt->elmt.nama, nama);
	elmt->elmt.nilai = nilai;
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
		printf("------isi queue------\n");
		
		elemen *elmt = Q.first;
		int i = 1;
		while(elmt != NULL){
			printf("====================\n");
			printf("elemen ke : %d\n",i);
			printf("nim : %s\n",elmt->elmt.nim);
			printf("nama : %s\n",elmt->elmt.nama);
			printf("nilai : %.2f\n",elmt->elmt.nilai);
			printf("prioritas : %d\n",elmt->prioritas);
			elmt = elmt->next;
			i++;
		}
		
		printf("---------------------\n");
	}else{
		/*proses jika queue kosong*/
		printf("queue kosong\n");
	}
	
}

void add_prioritas(char nim[],char nama[],float nilai,int prioritas,queue *Q){
	
	elemen *elmt = (elemen *) malloc (sizeof (elemen));
	strcpy(elmt->elmt.nim, nim);
	strcpy(elmt->elmt.nama, nama);
	elmt->elmt.nilai = nilai;
	elmt->prioritas = prioritas;
	
	if(isEmpty(*Q)==1){
		(*Q).first = elmt;
		(*Q).last = elmt;
		elmt->next = NULL;
	}else{
		
		elemen *posisi = (*Q).first;
		int ketemu = 0;
		
		//mencari tempat untuk elemen baru
		while(posisi != NULL && ketemu==0){
			if(posisi->prioritas >= prioritas && posisi==(*Q).last){
				//elemen baru menjadi elemen terakhir
				(*Q).last->next = elmt;
				(*Q).last = elmt;
				elmt->next = NULL;
				ketemu = 1;
			}else{
				if(posisi->prioritas >= prioritas && posisi->next->prioritas < prioritas){
					//elemen baru menjadi elemen di tengah queue
					elmt->next = posisi->next;
					posisi->next = elmt;
					ketemu = 1;
				}else{
					if(posisi->prioritas < prioritas && posisi==(*Q).first){
						//elemen baru menjadi elemen pertama queue
						elmt->next = (*Q).first;
						(*Q).first = elmt;
						ketemu = 1;
					}else{
						posisi = posisi->next;
					}
				}
			}
		}
		
	}
	
}
