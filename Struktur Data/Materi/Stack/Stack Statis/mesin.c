#include "header.h"

void createEmpty(stack *S){ (*S).top = -1; }

int isEmpty(stack S){
	int hasil = 0;
	
	if(S.top == -1) hasil = 1;
	
	return hasil;
}

int isFull(stack S){
	int hasil = 0;
	
	if(S.top == 9) hasil = 1;
	
	return hasil;
}

void push(char nim[],char nama[],float nilai, stack *S){
	
	//jika stack penuh
	if(isFull(*S) == 1) printf("stack penuh\n");
	else{
		if(isEmpty(*S) == 1){	//jika stack kosong
			(*S).top = 0;
			strcpy((*S).data[0].nim, nim);
			strcpy((*S).data[0].nama, nama);
			(*S).data[0].nilai = nilai;
		}else{					//jika stack tidak kosong
			(*S).top++;
			strcpy((*S).data[(*S).top].nim, nim);
			strcpy((*S).data[(*S).top].nama, nama);
			(*S).data[(*S).top].nilai = nilai;
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

nilaiMatkul pop_isi(stack *S){
	
	nilaiMatkul data;
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
		nilaiMatkul data;
		for(i=(*S).top;i>=0;i--){
			data = pop_isi(S);
			push(data.nim,data.nama,data.nilai,S2);
		}
	}
	
}

void printStack(stack S){
	
	if(S.top != -1){
		printf("-----isi stack-----\n");
		int i;
		for(i=S.top;i>=0;i--){
			printf("=====================\n");
			printf("elemen ke : %d\n",i);
			printf("nim : %s\n",S.data[i].nim);
			printf("nama : %s\n",S.data[i].nama);
			printf("nilai : %f\n",S.data[i].nilai);
		}
		printf("------------------\n");
	}
	//proses jika stack kosong
	else printf("stack kosong\n");
}