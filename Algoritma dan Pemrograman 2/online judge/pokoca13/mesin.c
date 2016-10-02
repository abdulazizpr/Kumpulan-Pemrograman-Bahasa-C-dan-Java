#include "header.h"

void tampil(int n,int status){
	int i;
	
	for(i=0;i<n;i++){
		printf("%d %d %d\n",angka[i].a,angka[i].b,angka[i].c);
	}
	
	if(status==1){
		printf("valid\n");
	}else{
		printf("tidak valid\n");
	}
	
}

int cari(int n,int kali,int* hasil){
	int i,status;
	
	status=0;
	i=0;
	while(i<n && status==0){
		if(hasil[i]==kali){
			status = 1;
		}else{
			i++;
		}
	}
	
	return status;
	
}

int cek(int i){
	int kali;
	if(angka[i].c%angka[i].a==0){
		kali = angka[i].c/angka[i].a;
	}else{
		kali = 0;
	}
	
	return kali;	
}

void sorting(int i){
	int temp;
	
	if(angka[i].a>angka[i].b){
		temp=angka[i].a;
		angka[i].a=angka[i].b;
		angka[i].b=temp;
	}
	if(angka[i].a>angka[i].c){
		temp=angka[i].a;
		angka[i].a=angka[i].c;
		angka[i].c=temp;
	}
	if(angka[i].b>angka[i].c){
		temp=angka[i].b;
		angka[i].b=angka[i].c;
		angka[i].c=temp;
	}
	
}