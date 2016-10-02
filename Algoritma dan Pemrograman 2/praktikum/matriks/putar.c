#include <stdio.h>

int matriks[100][100];

void putar(int a,int b){
	int i,j;
	int temp[100][100];//variabel buat menampung hasil pemutaran
	
	//proses pemutaran kearah kanan
	for(i=0;i<a;i++){
		for(j=0;j<b;j++){
			temp[i][j]=matriks[b-j-1][i];
		}
	}
	
	//proses pencopian ulang matriks
	for(i=0;i<a;i++){
		for(j=0;j<b;j++){
			matriks[i][j]=temp[i][j];
		}
	}
	
	
}

int main(){
	int baris,kolom,i,j,banyak;
	scanf("%d %d",&baris,&kolom);//memamsukan baris dan kolom
	
	//proses pengisian matriks
	for(i=0;i<baris;i++){
		for(j=0;j<kolom;j++){
			scanf("%d",&matriks[i][j]);
		}
	}
	
	scanf("%d",&banyak);//memasukan berapa kali putaran
	
	//di mod 4 biar efektif pengulangannya
	for(i=0;i<banyak%4;i++){
		putar(baris,kolom);
	}
	
	for(i=0;i<baris;i++){
		for(j=0;j<kolom;j++){
			printf("%d ",matriks[i][j]);
		}
		printf("\n");
	}
	
	
	
	return 0;
}