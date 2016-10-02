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
	if(Q.last == 9) hasil = 1;

	return hasil;
}

void add(char nim[],char nama[],float nilai,queue *Q){
	
	if(isEmpty(*Q) == 1){
		/*jika queue kosong*/
		(*Q).first = 0;
		(*Q).last = 0;
		strcpy((*Q).data[0].elmt.nim, nim);
		strcpy((*Q).data[0].elmt.nama, nama);
		(*Q).data[0].elmt.nilai = nilai;
	}else{
		if(isFull(*Q) != 1){
			(*Q).last++;
			strcpy((*Q).data[(*Q).last].elmt.nim, nim);
			strcpy((*Q).data[(*Q).last].elmt.nama, nama);
			(*Q).data[(*Q).last].elmt.nilai = nilai;
		}else{
			printf("queue penuh\n");
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
		printf("------isi queue------\n");
		int i;
		for(i=Q.last;i>=Q.first;i--){
			printf("====================\n");
			printf("elemen ke : %d\n",i);
			printf("nim : %s\n",Q.data[i].elmt.nim);
			printf("nama : %s\n",Q.data[i].elmt.nama);
			printf("nilai : %.2f\n",Q.data[i].elmt.nilai);
			printf("prioritas : %d\n",Q.data[i].prioritas);
		}
		
		printf("---------------------\n");
	}else{
		/*proses jika queue kosong*/
		printf("queue kosong\n");
	}
	
}

void add_prioritas(char nim[],char nama[],float nilai,int prioritas,queue *Q){
	
	if(isEmpty(*Q)==1){
		/*jika queue kosong*/
		(*Q).first = 0;
		(*Q).last = 0;
		strcpy((*Q).data[0].elmt.nim, nim);
		strcpy((*Q).data[0].elmt.nama, nama);
		(*Q).data[0].elmt.nilai = nilai;
		(*Q).data[0].prioritas = prioritas;
	}else{
		if(isFull(*Q) != 1){
			
			int i = (*Q).last;			
			int status = 0;
			//mencari tempat untuk elemen baru
			while(i>=(*Q).first && status==0){
				//elemen baru menjadi elemen terakhir
				if((*Q).data[i].prioritas >= prioritas && i==(*Q).last){
					(*Q).last++;
					i = (*Q).last;
					strcpy((*Q).data[i].elmt.nim, nim);
					strcpy((*Q).data[i].elmt.nama, nama);
					(*Q).data[i].elmt.nilai = nilai;
					(*Q).data[i].prioritas = prioritas;
					status=1;
				}else{
					//elemen baru menjadi elemen di tengah queue
					if((*Q).data[i-1].prioritas >= prioritas && (*Q).data[i].prioritas < prioritas){
						int j;
						
						//menggeser elemen ke belakang mulai dari elemen yang paling belakang
						for(j=(*Q).last;j>=i;j--){
							(*Q).data[j+1] = (*Q).data[j];
						}
						
						//masukan elemen baru
						strcpy((*Q).data[i].elmt.nim, nim);
						strcpy((*Q).data[i].elmt.nama, nama);
						(*Q).data[i].elmt.nilai = nilai;
						(*Q).data[i].prioritas = prioritas;
						(*Q).last++;
						status = 1;
					}else{
						//elemen baru menjadi elemen pertama queue
						if((*Q).data[(*Q).first].prioritas < prioritas && i==(*Q).first){
							int j;
							
							//menggeser elemen ke belakang mulai dari belakang
							for(j=(*Q).last;j>=(*Q).first;j--){
								(*Q).data[j+1] = (*Q).data[j];
							}
						
							//masukan elemen baru
							strcpy((*Q).data[(*Q).first].elmt.nim, nim);
							strcpy((*Q).data[(*Q).first].elmt.nama, nama);
							(*Q).data[(*Q).first].elmt.nilai = nilai;
							(*Q).data[(*Q).first].prioritas = prioritas;
							(*Q).last++;
							status = 1;
						}else{
							i--;
						}
					}	
				}
			}
		}else{
			printf("queue penuh\n");
		}
	}
	
}