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

void push(int angka,stack *S){
	
	elemen *baru = (elemen *) malloc (sizeof (elemen));
	baru->elmt.angka=angka;
	
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
		push((*S).top->elmt.angka,S2);
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
		
		elemen *elmt = S.top;
		int i = 1;
		
		while(elmt != NULL){
			printf("%d",elmt->elmt.angka);
			if(elmt->next != NULL){
				printf(" ");
			}
			i++;
			elmt = elmt->next;
		}
		printf("\n");
	}
	else printf("Stack Kosong\n");
}