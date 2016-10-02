#include "header.h"

void createEmpty(stack *S){ 
	(*S).top = NULL;
}

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

void push(float angka,stack *S){
	
	elemen *baru = (elemen *) malloc (sizeof (elemen));
	baru->elmt.angka=angka;
	
	if((*S).top==NULL){
		baru->next = NULL;
	}else{
		baru->next = (*S).top;
	}
	
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
		elemen *tampil = S.top;
		while(tampil != NULL){
			printf("%d\n",tampil->elmt.angka);
			tampil = tampil->next;
		}		
	}
	else printf("Stack Kosong\n");
}

int cek_sama(stack S1,stack S2){
	
	if(S1.top != NULL && S2.top != NULL){
		
		elemen *cari1 = S1.top;
		elemen *cari2 = S2.top;
		int status = 0;
		
		while(cari1 != NULL && cari2 !=NULL && status==0){
			if(cari1->elmt.angka != cari2->elmt.angka) status = 1;
			cari1 = cari1->next;
			cari2 = cari2->next;
		}
		
		if((cari1!=NULL && cari2==NULL)||(cari1==NULL && cari2!=NULL)){
			status = 1;
		}
		
		return status;
	}
	
}

void pop_isi(stack *S,stack *S2){
	
	if(isEmpty(*S) != 1){
		push((*S).top->elmt.angka,S2);
		pop(S);
	}
	
}

int jumlahangka(stack S){
	
	if(S.top != NULL){
		
		elemen *maju = S.top;
		
		int hasil = 0;
		while(maju != NULL){
			hasil+=maju->elmt.angka;
			maju = maju->next;
		}
	
		return hasil;
	}
	
}

void pindahinstack(stack S){
	
	if(S.top != NULL){
		
		stack S1;
		createEmpty(&S1);
		elemen *maju = S.top;
		
		while(maju != NULL){
			push(maju->elmt.angka,&S1);
			maju = maju->next;
		}
		
		printStack(S1);
	}
}