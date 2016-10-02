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
	arsipMatkul = fopen("ArsipMatkul.dat","w");
	printf("Tuliskan rekaman satu per satu : \n");
	printf("masukan nim : \n");
	scanf("%s",&rekaman.nim);
	
	while((strcmp(rekaman.nim,"XXXXXXXX")!=0)){
		//proses
		printf("masukan nama : \n");
		scanf("%s",&rekaman.nama);
		printf("masukan nilai : \n");
		scanf("%s",&rekaman.nilai);
		
		fprintf(arsipMatkul,"%s %s %s\n",rekaman.nim,rekaman.nama,rekaman.nilai);
		
		//iterasi
		printf("masukan nim : \n");
		scanf("%s",&rekaman.nim);
	}
	
	fprintf(arsipMatkul,"%s %s %s\n","XXXXXXXX","XXX","X");
	fclose(arsipMatkul);
	
	return 0;
}