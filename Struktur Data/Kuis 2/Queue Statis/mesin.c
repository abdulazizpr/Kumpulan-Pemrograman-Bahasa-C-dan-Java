#include "header.h"

void createEmpty(queue *Q){
	(*Q).first = -1;
	(*Q).last = -1;
}

int isEmpty(queue Q){
	int hasil = 0;
	
	if(Q.first == -1) hasil = 1;
	
	return hasil;
}

int isFull(queue Q){
	
	int hasil = 0;
	if(Q.last == 49) hasil = 1;

	return hasil;
}

void add(char nama[],int waktu,queue *Q){
	
	if(isEmpty(*Q) == 1){
		/*jika queue kosong*/
		(*Q).first = 0;
		(*Q).last = 0;
		strcpy((*Q).data[0].elmt.nama,nama);
		(*Q).data[0].elmt.waktu=waktu;
	}else{
		if(isFull(*Q) != 1){
			(*Q).last++;
			strcpy((*Q).data[(*Q).last].elmt.nama,nama);
			(*Q).data[(*Q).last].elmt.waktu=waktu;
		}else{
			printf("antrian penuh!\n");
		}
	}
	
}

void del(queue *Q){
	if((*Q).last == 0){
		createEmpty(Q);
	}else{
		/*menggeser elemen kedepan*/
		int i;
		for(i=(*Q).first+1;i<=(*Q).last;i++){
			(*Q).data[i-1]=(*Q).data[i];
		}
		//queue berkurang
		(*Q).last--;
	}
}

void printQueue(queue Q){
	
	if(Q.first != -1){
		int i;
		int total_waktu=0;
		for(i=Q.first;i<=Q.last;i++){
			printf("%s %d\n",Q.data[i].elmt.nama,Q.data[i].elmt.waktu);//tampilkan
			total_waktu+=Q.data[i].elmt.waktu;//lalu totalkan total waktu yang didapat
		}
		
		//lalu print hasil waktunya
		printf("%d\n",total_waktu);
		
	}else{
		/*proses jika queue kosong*/
		printf("Queue Kosong\n");
	}
	
	
	
}

void add_prioritas(char nama[],int waktu,int prioritas,queue *Q){
	
	if(isEmpty(*Q)==1){
		/*jika queue kosong*/
		(*Q).first = 0;
		(*Q).last = 0;
		strcpy((*Q).data[0].elmt.nama, nama);
		(*Q).data[0].elmt.waktu = waktu;
	}else{
		if(isFull(*Q) != 1){
			if((*Q).last<prioritas-1){
				(*Q).last++;
				strcpy((*Q).data[(*Q).last].elmt.nama , nama);
				(*Q).data[(*Q).last].elmt.waktu = waktu;
			}else{
				(*Q).last++;
				int i;
				for(i=(*Q).last;i>(prioritas-1);i--){
					(*Q).data[i] = (*Q).data[i-1];
				}
				
				strcpy((*Q).data[prioritas-1].elmt.nama , nama);
				(*Q).data[prioritas-1].elmt.waktu = waktu;
			}
			
		}else{
			printf("queue penuh\n");
		}
	}
	
}