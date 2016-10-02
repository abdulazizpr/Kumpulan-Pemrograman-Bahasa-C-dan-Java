#include "header.h"

/*
Saya Abdul Aziz Priatna tidak melakukan kecurangan seperti yang telah
dispesifikasikan pada mata kuliah Algoritma dan Pemograman 2
dalam mengerjakan Kuis 1, jika saya melakukan kecurangan
maka Allah/Tuhan adalah saksi saya, dan saya bersedia 
menerima hukumanNya. Aamiin.

*/

int main(){
	
	int baris,kolom,i,j;
	scanf("%d %d",&baris,&kolom);//inputan baris x kolom
	
	
	for(i=0;i<baris;i++){
		for(j=0;j<kolom;j++){
			scanf("%d",&matriks[i][j]);//inputan matriks
		}
	}
	
	for(i=0;i<baris;i++){
		for(j=0;j<kolom;j++){
			genap(i,j,baris,kolom);//melakukan proses di prosedur genap
		}
	}
	
	for(i=0;i<baris;i++){
		for(j=0;j<kolom;j++){
			tampil(i,j,baris,kolom);//menampilkan di prosedur tampil
		}
		printf("\n");
	}
	
	
	
	
	
	return 0;
}