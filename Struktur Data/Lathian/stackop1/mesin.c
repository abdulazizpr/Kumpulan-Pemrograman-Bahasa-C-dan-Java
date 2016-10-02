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

void push(char karakter,stack *S){
	
	elemen *baru = (elemen *) malloc (sizeof (elemen));
	baru->elmt.karakter=karakter;
	
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
		push((*S).top->elmt.karakter,S2);
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
			printf("%c",elmt->elmt.karakter);
			if(elmt->next!=NULL){
				printf(" ");
			}
			elmt = elmt->next;
		}
		
		printf("\n");
		
	}
	else printf("Stack Kosong\n");
}

void operasi(stack *S){
	
	if((*S).top != NULL){
		
		stack S2;
		createEmpty(&S2);
		pindahinstack(S,&S2);
		
		char prev = S2.top->elmt.karakter;//inisialisasi
		pop(&S2);
		char now = S2.top->elmt.karakter;
		pop(&S2);
		int hasil = prev-48;
		char next = S2.top->elmt.karakter;
		pop(&S2);
		while(isEmpty(S2)!=1){
			if(now=='+'){
				if(next != '=' || next != '+'|| next != '-') hasil = hasil + (next-48);
			}else if(now=='-'){
				if(next != '=' || next != '+'|| next != '-') hasil = hasil - (next-48);
			}
			
			prev = now;
			now = next;
			next = S2.top->elmt.karakter;
			pop(&S2);
		}
		
		printf("%d\n",hasil);
		
	}
	
}