#include "header.h"

void tampil(int n,int status){
	int i;
	for(i=0;i<n;i++){
		printf("%.0f %.0f %.0f %.0f\n",angka[i][0].pembilang,angka[i][0].penyebut,angka[i][1].pembilang,angka[i][1].penyebut);
	}
	
	if(status==1){
		printf("valid\n");
	}else{
		printf("tidak valid\n");
	}
	
}

int cari(int n,float nilai,float* hasil){
	int i,status;
	
	status=0;
	i=0;
	while(i<n && status==0){
		if(hasil[i]==nilai){
			status=1;
		}
		i++;
		
	}
	
	return status;
}

float cek(int i){
	
	float hasil;
	hasil=(angka[i][1].pembilang/angka[i][1].penyebut)/(angka[i][0].pembilang/angka[i][0].penyebut);
	
	return hasil;
	
}

void sorting(int i){
	bungkusan temp;
	if((angka[i][0].pembilang/angka[i][0].penyebut)>(angka[i][1].pembilang/angka[i][1].penyebut)){
		temp=angka[i][0];
		angka[i][0]=angka[i][1];
		angka[i][1]=temp;
	}
	
}
