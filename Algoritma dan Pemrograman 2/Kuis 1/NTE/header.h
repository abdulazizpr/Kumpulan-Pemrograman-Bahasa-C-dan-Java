#include <stdio.h>

typedef struct{
	int a;//angka pertama
	int b;//angka kedua
	int c;//angka ketiga
}isi;

void caritengah(int m,int n,isi angka[],int hasil[m][n]);

int nilaitengah(isi angka);

void printhasil(int m,int n,int hasil[m][n]);
