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

void push(int angka,char kartu[],int prioritas, stack *S){
	
	//jika stack penuh
	if(isFull(*S) == 1) printf("stack penuh\n");
	else{
		if(isEmpty(*S) == 1){	//jika stack kosong
			(*S).top = 0;
			(*S).data[0].angka = angka;
			strcpy((*S).data[0].kartu, kartu);
			(*S).data[0].prioritas = prioritas;
		}else{					//jika stack tidak kosong
			(*S).top++;
			(*S).data[(*S).top].angka = angka;
			strcpy((*S).data[(*S).top].kartu, kartu);
			(*S).data[(*S).top].prioritas = prioritas;
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

kontainer lempardata(stack *S){
	
	kontainer data;
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
		kontainer data;
		for(i=(*S).top;i>=0;i--){
			data = lempardata(S);
			push(data.angka,data.kartu,data.prioritas,S2);
		}
	}
	
}

void pop_isi(stack *S,stack *S2){
	
	if(isEmpty(*S) == 0 && isFull(*S2) == 0){ 
        push((*S).data[(*S).top].angka,(*S).data[(*S).top].kartu, (*S).data[(*S).top].prioritas, S2);
        pop(&(*S));
    }
	
}

void printStack(stack S){
	
	if(S.top != -1){
		
		int i;
		for(i=S.top;i>=0;i--){
			printf("%d ",S.data[i].angka);
			printf("%s\n",S.data[i].kartu);
		}
		
	}
	//proses jika stack kosong
	else printf("stack kosong\n");
}

void buang_kartu(stack *S1,stack *S2,stack *S3,stack *S4,stack *S5){
	
	if(isEmpty(*S1) != 1 && isEmpty(*S2) != 1&& isEmpty(*S3) != 1 && isEmpty(*S4) != 1){
		
		stack Stemp;
		createEmpty(&Stemp);
		kontainer temp;
			
		do{	
			//inisialisasi temp untuk pencarian nilai minimal
			temp.angka = 10;//inisialisasi angka terbesar agar nilai yang dicari bisa didapat
			temp.kartu[0] = '\0';//kartu di set null
			temp.prioritas = 0;//prioritas di 0 kan
			
			
			if(isEmpty (*S1) != 1){//jika S1 tidak kosong
				if((*S1).data[(*S1).top].angka < temp.angka){//jika nilai top S1 lebih kecil dari nilai temp
					temp = (*S1).data[(*S1).top];//masukan semua data top S1 ke dalam
				}else if((*S1).data[(*S1).top].angka==temp.angka){//jika nilanya sama
					if((*S1).data[(*S1).top].prioritas < temp.prioritas){//maka bandingkan berdasarkan prioritas
						temp = (*S1).data[(*S1).top];
					}
				}				
			}
			
			if(isEmpty (*S2) != 1){//jika S2 tidak kosong
				if((*S2).data[(*S2).top].angka < temp.angka){//jika nilai top S2 lebih kecil dari nilai temp
					temp = (*S2).data[(*S2).top];//masukan semua data top S2 ke dalam
				}else if((*S2).data[(*S2).top].angka==temp.angka){//jika nilanya sama
					if((*S2).data[(*S2).top].prioritas < temp.prioritas){//maka bandingkan berdasarkan prioritas
						temp = (*S2).data[(*S2).top];
					}
				}				
			}if(isEmpty (*S3) != 1){//jika S3 tidak kosong
				if((*S3).data[(*S3).top].angka < temp.angka){//jika nilai top S3 lebih kecil dari nilai temp
					temp = (*S3).data[(*S3).top];//masukan semua data top S3 ke dalam
				}else if((*S3).data[(*S3).top].angka==temp.angka){//jika nilanya sama
					if((*S3).data[(*S3).top].prioritas < temp.prioritas){//maka bandingkan berdasarkan prioritas
						temp = (*S3).data[(*S3).top];
					}
				}				
			}if(isEmpty (*S4) != 1){//jika S4 tidak kosong
				if((*S4).data[(*S4).top].angka < temp.angka){//jika nilai top S4 lebih kecil dari nilai temp
					temp = (*S4).data[(*S4).top];//masukan semua data top S4 ke dalam
				}else if((*S4).data[(*S4).top].angka==temp.angka){//jika nilanya sama
					if((*S4).data[(*S4).top].prioritas < temp.prioritas){//maka bandingkan berdasarkan prioritas
						temp = (*S4).data[(*S4).top];
					}
				}				
			}	
			
			if(temp.angka == (*S1).data[(*S1).top].angka && temp.prioritas == (*S1).data[(*S1).top].prioritas){//jika angka dan prioritas di S1 sama dengan temp
				pop_isi(S1,S5);//maka pop S1 lalu isi S5
			}else if(temp.angka == (*S2).data[(*S2).top].angka && temp.prioritas == (*S2).data[(*S2).top].prioritas){//jika angka dan prioritas di S2 sama dengan temp
				pop_isi(S2,S5);//maka pop S2 lalu isi S5
			}else if(temp.angka == (*S3).data[(*S3).top].angka && temp.prioritas == (*S3).data[(*S3).top].prioritas){//jika angka dan prioritas di S3 sama dengan temp
				pop_isi(S3,S5);//maka pop S3 lalu isi S5
			}else if(temp.angka == (*S4).data[(*S4).top].angka && temp.prioritas == (*S4).data[(*S4).top].prioritas){//jika angka dan prioritas di S4 sama dengan temp
				pop_isi(S4,S5);//maka pop S4 lalu isi S5
			}
			
		}while(isEmpty(*S1) != 1 || isEmpty(*S2) != 1 || isEmpty(*S3) != 1|| isEmpty(*S4) != 1);//berulang selama salah satu dari stack tidak kosong
		
	}
}
