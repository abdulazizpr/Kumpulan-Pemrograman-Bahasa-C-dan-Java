#include <stdio.h>
#include <string.h>

typedef struct{
	char nim[10];
	char nama[10];
	char nilai[2];
}nilaiMatkul;

int main(){
	
	nilaiMatkul rekaman;
	FILE *arsipMatkul;
	arsipMatkul = fopen("ArsipMatkul.dat","r");
	char kata_cari[10];
	printf("masukan nim yang dicari : \n");
	scanf("%s",&kata_cari);
	fscanf(arsipMatkul,"%s %s %s",&rekaman.nim,rekaman.nama,rekaman.nilai);
	
	if(strcmp(rekaman.nim,"XXXXXXXX")==0){
		printf("arsip kosong\n");
	}else{
		if(strcmp(kata_cari,"XXXXXXXX")==0){
			printf("tidak ditemukan\n");
		}else{
			while((strcmp(rekaman.nim,"XXXXXXXX")!=0) && (strcmp(rekaman.nim,kata_cari)!=0)){
				fscanf(arsipMatkul,"%s %s %s\n",&rekaman.nim,&rekaman.nama,&rekaman.nilai);
			}
		}
		
		if(strcmp(rekaman.nim,kata_cari)==0){
			printf("hasil pencarian : \n");
			printf("nim %s\n",rekaman.nim);
			printf("nama %s\n",rekaman.nama);
			printf("nilai %s\n",rekaman.nilai);
			printf("------------\n");
			
		}else{
			printf("tidak ditemukan\n");
		}
	}
	
	fclose(arsipMatkul);
	
	return 0;
}