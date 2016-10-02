#include "header.h"

void createEmpty(stack *S){ (*S).top = -1; }

int isEmpty(stack S){
	int hasil = 0;
	
	if(S.top == -1) hasil = 1;
	
	return hasil;
}

int isFull(stack S){
	int hasil = 0;
	
	if(S.top == 2) hasil = 1;
	
	return hasil;
}

void push(char huruf, stack *S){
	
	//jika stack penuh
	if(isFull(*S) == 1) printf("Stack Overflow\n");
	else{
		if(isEmpty(*S) == 1){	//jika stack kosong
			(*S).top = 0;
			(*S).data[0].huruf = huruf;
		}else{					//jika stack tidak kosong
			(*S).top++;
			(*S).data[(*S).top].huruf = huruf;
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
			push(data.huruf,S2);
		}
	}
	
}

void printStack(stack S){
	
	if(S.top != -1){
		int i;
		for(i=S.top;i>=0;i--){
			printf("%c\n",S.data[i].huruf);
		}
	}
	//proses jika stack kosong
	else printf("Stack Overflow\n");
}