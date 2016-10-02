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

void printStack(stack S){
	
	if(S.top != NULL){
		elemen *elmt = S.top;
		int i = 1;
		
		while(elmt != NULL){
			printf("%d\n",elmt->elmt.angka);
			elmt = elmt->next;
		}
		
	}
}

void isi_stack(stack S,stack *S1){    
	
	elemen *elmt = S.top;
	
	
	while(elmt != NULL){
		push(elmt->elmt.angka,S1);
		elmt = elmt->next;
	}
	push(-1,S1);

}

void copy_stack(stack S,stack *S1){    
	
	elemen *elmt = S.top;
	
	while(elmt != NULL){
		push(elmt->elmt.angka,S1);
		elmt = elmt->next;
	}

}

void pop_cari(int angka,stack *S){
	
	if((*S).top != NULL){
		
		elemen *hapus = (*S).top;
		int status = 0;
		while((*S).top != NULL && status == 0){
			if((*S).top->elmt.angka == angka){
				pop(S);
				status = 1;
			}else{
				pop(S);
			}
		}
		
	}
	
}

void pop_banyak(int banyak,stack *S){
	
	if((*S).top != NULL){
		
		int status = 0,i = 0;
		while((*S).top != NULL && i<banyak){
			pop(S);
			i++;
		}
		
	}
	
}