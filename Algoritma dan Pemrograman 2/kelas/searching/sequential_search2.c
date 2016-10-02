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

void sequential_search(int n,char cari[50],int ketemu){
	
	int i;
	
	ketemu = 0;
	i = 0;
	while((i<n) && (ketemu == 0)){
		if(strcmp(tabel[i].nim, cari) == 0 || strcmp(tabel[i].nama, cari) == 0){
			//jika data ketemu
			ketemu = 1;
		}else{
			i = i + 1;
		}
	}
	
	tampil(i,ketemu);
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
	sequential_search(n,cari,ketemu);
	
	return 0;
}
