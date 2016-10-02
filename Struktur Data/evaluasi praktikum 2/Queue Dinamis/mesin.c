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

void add(char namab[],int waktu,int ongkos,queue *Q){
	
	elemen *elmt = (elemen *) malloc (sizeof (elemen));
	strcpy(elmt->elmt.namab,namab);
	elmt->elmt.waktu = waktu;
	elmt->elmt.ongkos = ongkos;
	
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

void printQueue(int waktu,queue Q){
	
	if(Q.first != NULL){
		
		elemen *elmt = Q.first;
		int status=0;
		int total_ongkos = 0;
		while(elmt != NULL && status==0){
			if(waktu-elmt->elmt.waktu <=0){//jika waktu sekarang kosong
				status = 1;//maka berhenti
			}else{//jika tidak
				waktu -= elmt->elmt.waktu;//kurangi waktu sebanyak antrian
				printf("%s\n",elmt->elmt.namab);
				total_ongkos += elmt->elmt.ongkos;//jumlahkan total ongkos
				elmt = elmt->next;
			}
		}
		//print total ongkos
		printf("%d\n",total_ongkos);
		
	}else{
		/*proses jika queue kosong*/
		printf("QUEUE KOSONG\n");
	}
	
}

void add_prioritas(char namab[],int waktu,int ongkos,int prioritas,queue *Q){
	
	elemen *elmt = (elemen *) malloc (sizeof (elemen));
	strcpy(elmt->elmt.namab,namab);
	elmt->elmt.waktu = waktu;
	elmt->elmt.ongkos = ongkos;
	
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
