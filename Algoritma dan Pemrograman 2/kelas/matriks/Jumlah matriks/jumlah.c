#include <stdio.h>

int main(){
	
	int matriks1[3][3];
	int matriks2[3][3];
	int matriks3[3][3];
	
	int baris;
	int kolom;
	
	for(baris=0;baris<3;baris++){
		for(kolom=0;kolom<3;kolom++){
			//printf("masukan angka: \n");
			scanf("%d",&matriks1[baris][kolom]);
			//printf("\n");
		}
	}
	
	for(baris=0;baris<3;baris++){
		for(kolom=0;kolom<3;kolom++){
			//printf("masukan angka: \n");
			scanf("%d",&matriks2[baris][kolom]);
			//printf("\n");
		}
	}	
	
	
	for(baris=0;baris<3;baris++){
		for(kolom=0;kolom<3;kolom++){
			matriks3[baris][kolom]=matriks1[baris][kolom]+matriks2[baris][kolom];
		}
	}
	
	printf("Isi matriks 1 : \n");
	for(baris=0;baris<3;baris++){
		for(kolom=0;kolom<3;kolom++){
			printf("%d ",matriks1[baris][kolom]);
		}
		printf("\n");
	}
	
	printf("Isi matriks 2 : \n");
	for(baris=0;baris<3;baris++){
		for(kolom=0;kolom<3;kolom++){
			printf("%d ",matriks2[baris][kolom]);
		}
		printf("\n");
	}
	
	printf("Isi matriks 3 : \n");
	for(baris=0;baris<3;baris++){
		for(kolom=0;kolom<3;kolom++){
			printf("%d ",matriks3[baris][kolom]);
		}
		printf("\n");
	}
	

	
return 0;	
}