#include "header.h"

void createEmpty(stack *S){ (*S).top = -1; }

int isEmpty(stack S){
	int hasil = 0;
	
	if(S.top == -1) hasil = 1;
	
	return hasil;
}

int isFull(stack S){
	int hasil = 0;
	
	if(S.top == 49) hasil = 1;
	
	return hasil;
}

void push(char kode[],char buku[], stack *S){
	
	//jika stack penuh
	if(isFull(*S) == 1) printf("Stack Overflow\n");
	else{
		if(isEmpty(*S) == 1){	//jika stack kosong
			(*S).top = 0;
			strcpy((*S).data[0].kode,kode);
			strcpy((*S).data[0].buku,buku);
		}else{					//jika stack tidak kosong
			(*S).top++;
			strcpy((*S).data[(*S).top].kode,kode);
			strcpy((*S).data[(*S).top].buku,buku);
		}
	}
	
}

void pop(stack *S){
	//jika stack berisi satu elemen
	if((*S).top == 0) (*S).top--;
	else{	//jika stack tidak kosong
		if((*S).top != -1) (*S).top--;
	}
}

void printStack(char cek_kode[],stack S){
	
	if(S.top != -1){
		int i;
		int jumlah = 0;
		for(i=S.top;i>=0;i--){
			//jika 2 kode awal sama maka print
			if(cek_kode[0]==S.data[i].kode[0] && cek_kode[1]==S.data[i].kode[1]) printf("%s\n",S.data[i].buku);
			else {
				printf("-----\n");//lalu print spasi
				jumlah++;//lalu jumlahkan buku yang tidak bisa di pinjam
			}	
		}
		//lalu tampilkan jumlah buku yang tidak bisa dipinjam
		printf("%d\n",jumlah);
	}
	//proses jika stack kosong
	else printf("Stack Overflow\n");
}

bungkusan pop_isi(stack *S){
	
	bungkusan data;
	if((*S).top == 0){ 
		data = (*S).data[(*S).top];
		(*S).top = -1;
	}else{	//jika stack tidak kosong
		if((*S).top != -1){
			data = (*S).data[(*S).top];
			(*S).top = (*S).top - 1;
		}else{
			printf("kosong\n");
		}	
	}
	
	return data;
}

void pindahinstack(stack *S,stack *S2){

	if((*S).top != -1){
		int i;
		bungkusan data;
		for(i=(*S).top;i>=0;i--){
			data = pop_isi(S);
			push(data.kode,data.buku,S2);
		}
	}
	
}