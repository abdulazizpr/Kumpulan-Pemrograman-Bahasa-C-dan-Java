#include <stdio.h>
#include <string.h>

typedef struct{
	char nim[50];
	char nama[50];
	float nilai;
}nilaiMatkul;

nilaiMatkul tabel[100];

void tampil(int i,int ketemu){
	
	printf("Hasil Pencarian : \n");
	if(ketemu == 1){
		printf("nim: %s\n", tabel[i]. nim);
		printf("nama: %s\n", tabel[i]. nama);
		printf("nilai: %0.2f\n", tabel[i]. nilai);
	}else{
		printf("tidak ditemukan\n");
	}
	
}

void binary_search(int n,char cari[50],int ketemu){
	
	int i,j,k;
	
	ketemu = 0;
	i = 0;
	j = n;
	while(ketemu == 0 && i<=j){
		k = (i + j) / 2;
		if(strcmp(tabel[k].nim,cari)==0 || strcmp(tabel[k].nama,cari)==0){
			ketemu = 1;
		}else{
			if(strcmp(tabel[k].nim,cari)!=0 || strcmp(tabel[k].nama,cari)!=0){
				j = k - 1;
			}else{
				i = k + 1;
			}
		}	
	}
	
	tampil(i,ketemu);
}

void bubblesort(int n){
	int i,tukar;
	
	nilaiMatkul temp;
	do{
		tukar=0;
		
		for(i=0;i<n-1;i++){
			if(strcmp(tabel[i].nim,tabel[i+1].nim)==1){
				temp=tabel[i];
				tabel[i]=tabel[i+1];
				tabel[i+1]=temp;
				tukar=1;
			}
		}
		
	}while(tukar==1);
	
}

int main(){
	
	char cari[50];
	int ketemu,i,n;
	
	printf("masukan banyaknya isi tabel : ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%s %s %f",&tabel[i].nim,&tabel[i].nama,&tabel[i].nilai);
	}
	
	
	printf("Masukan Pencarian : ");
	scanf("%s",&cari);
	
	bubblesort(n);
	/* for(i=0;i<n;i++){
		printf("%s %s %0.2f\n",tabel[i].nim,tabel[i].nama,tabel[i].nilai);	
	} */
	
	binary_search(n,cari,ketemu);
	
	return 0;
}
