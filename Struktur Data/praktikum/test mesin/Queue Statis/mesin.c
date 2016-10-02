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
	if(Q.last == 2) hasil = 1;

	return hasil;
}

void add(char huruf,queue *Q){
	
	if(isEmpty(*Q) == 1){
		/*jika queue kosong*/
		(*Q).first = 0;
		(*Q).last = 0;
		(*Q).data[0].elmt.huruf=huruf;
	}else{
		if(isFull(*Q) != 1){
			(*Q).last++;
			(*Q).data[(*Q).last].elmt.huruf=huruf;
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
		printf("-----------------\n");
		for(i=Q.first;i<=Q.last;i++){
			printf("%c",Q.data[i].elmt.huruf);
			if(i!=Q.last) printf(" ");
		}
		printf("\n");
		printf("-----------------\n");
		
	}else{
		/*proses jika queue kosong*/
		printf("Queue Kosong\n");
	}
	
	
	
}

void add_prioritas(char huruf,int prioritas,queue *Q){
	
	if(isEmpty(*Q)==1){
		/*jika queue kosong*/
		(*Q).first = 0;
		(*Q).last = 0;
		(*Q).data[0].elmt.huruf = huruf;
	}else{
		if(isFull(*Q) != 1){
			if((*Q).last<prioritas-1){
				(*Q).last++;
				(*Q).data[(*Q).last].elmt.huruf = huruf;
			}else{
				(*Q).last++;
				int i;
				for(i=(*Q).last;i>(prioritas-1);i--){
					(*Q).data[i] = (*Q).data[i-1];
				}
				
				(*Q).data[prioritas-1].elmt.huruf = huruf;
			}
			
		}else{
			printf("queue penuh\n");
		}
	}
	
}