#include "header.h"

//fungsi sum untuk menjumlahkan angka genap
int sumgenap(int n){
	
	if(n==0 || n==1){//basis
		return 0;
	}else{
		return n+sumgenap(n-2);//rekurens
	}
	
}

//prosedur untuk melalkukan proses penggenapan matriks
void genap(int i,int j,int baris,int kolom){
	
	if(matriks[i][j]%2==0){//jika matriks genap
		matriks[i][j]=sumgenap(matriks[i][j]);//maka melukan penjumlahan di fungsi sumgenap
	}else{//jika tidak
		matriks[i][j]=matriks[i][j]-1;//maka matriks dikurang 1 dulu agar range nya tidak jauh
		matriks[i][j]=sumgenap(matriks[i][j]);//lalu dijumlahkan lagi di sumgenap
	}
	
}

//menampilkan isi matriks di prosedur isi tampil
void tampil(int i,int j,int baris,int kolom){
	
	printf("%d",matriks[i][j]);
	if(j<kolom-1){
		printf(" ");
	}
	
}