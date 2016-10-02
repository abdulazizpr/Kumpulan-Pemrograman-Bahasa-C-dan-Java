#include "header.h"

void caritengah(int m,int n,isi angka[],int hasil[m][n]){
	
	int i,j;
	int indeks=0;
	
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			hasil[i][j]=nilaitengah(angka[indeks]);
			indeks++;
		}
	}
	
}

int nilaitengah(isi angka){
	
	if((angka.a>angka.b && angka.b>angka.c) || (angka.a<angka.b && angka.b<angka.c)){
		return angka.b;
	}else if((angka.a>angka.c && angka.c>angka.b) || (angka.a<angka.c && angka.c<angka.b)){
		return angka.c;
	}else if((angka.b>angka.a && angka.a>angka.c) || (angka.b<angka.a && angka.a<angka.c)){
		return angka.a;
	}
	
}

void printhasil(int m,int n,int hasil[m][n]){
	int i,j;
	
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf("%d",hasil[i][j]);
			if(j<n-1){
				printf(" ");
			}
		}
		printf("\n");
	}
}