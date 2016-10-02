#include "header.h"

void createEmpty(stack *S){ (*S).top = NULL; }

int isEmpty(stack S){
	
	int hasil = 0;
	if(S.top == NULL) hasil = 1;
	
	return hasil;
}

int countElement(stack S){
	
	int hasil = 0;
	if(S.top != NULL){
		/*stack tidak kosong*/
		
		elemen *elmt = S.top;	//inisialisasi
		
		while(elmt != NULL){
			hasil++;
			elmt = elmt->next;
		}
		
	}
	
	return hasil;
	
}

void push(char nim[],char nama[],float nilai,stack *S){
	
	elemen *baru = (elemen *) malloc (sizeof (elemen));
	strcpy(baru->elmt.nim,nim);
	strcpy(baru->elmt.nama,nama);
	baru->elmt.nilai=nilai;
	
	baru->next = (*S).top;
	(*S).top = baru;	
	baru = NULL;
}

void pop(stack *S){
	
	if((*S).top != NULL){	//jika stack tidak kosong
		elemen *keluar = (*S).top;
		(*S).top = (*S).top->next;
		keluar->next = NULL;
		free(keluar);
	}
	
}

void pop_isi(stack *S,stack *S2){
	
	if(isEmpty(*S) != 1){
		push((*S).top->elmt.nim,(*S).top->elmt.nama,(*S).top->elmt.nilai,S2);
		pop(S);
	}
	
}

void pindahinstack(stack *S,stack *S2){
	
	if((*S).top != NULL){
		
		while((*S).top != NULL){
			pop_isi(S,S2);
		}
		
	}
}

void printStack(stack S){
	
	if(S.top != NULL){
		printf("-----isi stack-----\n");
		
		elemen *elmt = S.top;
		int i = 1;
		
		while(elmt != NULL){
			printf("================\n");
			printf("elemen ke : %d\n",i);
			printf("nim : %s\n",elmt->elmt.nim);
			printf("nama : %s\n",elmt->elmt.nama);
			printf("nilai : %f\n",elmt->elmt.nilai);
			
			i++;
			elmt = elmt->next;
		}
		
		printf("--------------------\n");
		
	}
	else printf("Stack Kosong\n");
}