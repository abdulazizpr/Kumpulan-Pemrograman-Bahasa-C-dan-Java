#include <stdio.h>

int main(){
	
	int matriks[4][4];
	int baris;
	int kolom;
	for(baris=0;baris<4;baris++){
		for(kolom=0;kolom<4;kolom++){
			printf("masukan angka: \n");
			scanf("%d",&matriks[baris][kolom]);
			printf("\n");
		}
	}
	
	for(baris=0;baris<4;baris++){
		for(kolom=0;kolom<4;kolom++){
			printf("%d ",matriks[baris][kolom]);
		}
		printf("\n");
	}
	
return 0;	
}