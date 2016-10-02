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
	printf("isi file arsip beruntun adalah : \n");
	fscanf(arsipMatkul,"%s %s %s",&rekaman.nim,&rekaman.nama,&rekaman.nilai);
	
	if(strcmp(rekaman.nim,"XXXXXXXX")==0){
		printf("arsip kosong\n");
	}else{
		do{
			//proses
			printf("nim : %s\n",rekaman.nim);
			printf("nama : %s\n",rekaman.nama);
			printf("nilai : %s\n",rekaman.nilai);
			printf("-----------------\n");
			
			//iterasi
			fscanf(arsipMatkul,"%s %s %s\n",&rekaman.nim,&rekaman.nama,&rekaman.nilai);
			
		}while(strcmp(rekaman.nim,"XXXXXXXX")!=0);
	}
	
	fclose(arsipMatkul);
	
	return 0;
}