#include <stdio.h>
#include <string.h>
typedef struct{
 char nim[10];
 char nama[100];
 char nilai[2];
} nilaiMatKul;

int main(){
	
	nilaiMatKul rekaman;
	FILE *arsipMatKul1;
	FILE *arsipMatKul2;
	FILE *arsipMatKul3;
	
	arsipMatKul1 = fopen("ArsipMatkul1.dat", "r");
	arsipMatKul2 = fopen("ArsipMatkul2.dat", "r");
	arsipMatKul3 = fopen("ArsipMatkul3.dat", "w");
	
	printf("mulai proses penggabungan file\n");
	fscanf(arsipMatKul1, "%s %s %s\n", &rekaman.nim, &rekaman.nama, &rekaman.nilai);

	while(strcmp(rekaman.nim, "XXXXXXXX") != 0){
		fprintf(arsipMatKul3, "%s %s %s\n", rekaman.nim, rekaman.nama,rekaman.nilai);
		fscanf(arsipMatKul1, "%s %s %s\n", &rekaman.nim, &rekaman.nama, &rekaman.nilai);
	}
	
	fscanf(arsipMatKul2, "%s %s %s\n", &rekaman.nim, &rekaman.nama, &rekaman.nilai);
	while(strcmp(rekaman.nim, "XXXXXXXX") != 0){
		fprintf(arsipMatKul3, "%s %s %s\n", rekaman.nim, rekaman.nama, rekaman.nilai);
		fscanf(arsipMatKul2, "%s %s %s\n", &rekaman.nim, &rekaman.nama,&rekaman.nilai);
	} 
	fprintf(arsipMatKul3, "%s %s %s\n", "XXXXXXXX","XXX","X");
	printf("proses penggabungan file selesai\n");
	fclose(arsipMatKul1);
	fclose(arsipMatKul2);
	fclose(arsipMatKul3);
	return 0;
}