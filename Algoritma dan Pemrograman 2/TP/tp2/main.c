#include "header.h"

/*
Saya Abdul Aziz Priatna(1307123) tidak melakukan kecurangan seperti yang telah dispesifikasikan pada 
mata kuliah Algoritma dan Pemograman 2 dalam mengerjakan TP 2, jika saya melakukan kecurangan
maka Allah/Tuhan adalah saksi saya, dan saya bersedia menerima hukumanNya. Aamiin.
*/

int main(){
	
	//variabel
	int n,m,i,j,k;
	scanf("%d %d",&n,&m);//inputan ordo n x m
	
	int matriks1[n][m];//matriks1 ukuran n x m
	int matriks2[n][m];//matriks2 ukuran n x m
	int matriks3[n][m];//matriks3 ukuran n x m
	int matriks4[n][m];//matriks4 ukuran n x m
	
	
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d",&matriks1[i][j]);//inputan matriks1
		}
	}
	
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d",&matriks2[i][j]);//inputan matriks2
		}
	}
	
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d",&matriks3[i][j]);//inputan matriks3
		}
	}
	
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d",&matriks4[i][j]);//inputan matriks4
		}
	}
	
	int hasil[n][m];//untuk menampung hasil
	
	int deret[100];//variabel untuk menampung deret dari fungsi deretfibbonaci
	
	//prosedur untuk melakukan fungsi deretfibbonaci dan membandingkan hasil deret dan matriks4
	lemparfibb(n,m,matriks1,matriks2,matriks3,matriks4,hasil,deret);
	
	tampilhasil(n,m,hasil);//lalu hasilnya di tampilkan di prosedur tampilhasil
	
	return 0;
}