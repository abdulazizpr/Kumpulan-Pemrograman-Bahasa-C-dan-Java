#include "header.h"

void createEmpty(stack *S){ (*S).top = -1; }

int isEmpty(stack S){
	int hasil = 0;
	
	if(S.top == -1) hasil = 1;
	
	return hasil;
}

int isFull(stack S){
	int hasil = 0;
	
	if(S.top == n) hasil = 1;
	
	return hasil;
}

void push(int angka, stack *S){
	
	//jika stack penuh
	if(isFull(*S) == 1) printf("stack penuh\n");
	else{
		if(isEmpty(*S) == 1){	//jika stack kosong
			(*S).top = 0;
			(*S).data[0].angka = angka;
		}else{					//jika stack tidak kosong
			(*S).top++;
			(*S).data[(*S).top].angka = angka;
		}
	}
	
}

void pop(stack *S){
	//jika stack berisi satu elemen
	if((*S).top == 0) (*S).top = -1;
	else{	//jika stack tidak kosong
		if((*S).top != -1) (*S).top = (*S).top - 1;
	}
}

void printStack(stack S){
	
	if(S.top != -1){
		int i,j,spasi = 0;
		for(i=S.top;i>=0;i--){
			if(i%2==0){
				for(j=0;j<spasi;j++){
					printf(" ");
				}
			}
			printf("%.3d",S.data[i].angka);
			if(i%2==0 && i != 0){
				printf("-");
			}else{
				printf("\n");
				spasi = spasi+4;
			}
		}
		
	}
	//proses jika stack kosong
	else printf("stack kosong\n");
}

void fib(int* arr, int n,int pertama,int kedua , int i){
	if(i == 0){
		arr[i] = pertama;
		fib(arr, n, pertama, kedua,i+1);
	}else if(i == 1){
		arr[i] = kedua;
		fib(arr, n, pertama ,kedua ,i+1);
	}else{
		if(i<n){
			arr[i] = arr[i-1] + arr[i-2];
			fib(arr, n, pertama, kedua ,i+1);
		}
	}
}
