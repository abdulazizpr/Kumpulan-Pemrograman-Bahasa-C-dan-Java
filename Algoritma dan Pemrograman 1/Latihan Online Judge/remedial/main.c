#include "header.h"

/*
Saya Abdul Aziz Priatna(1307123) tidak melakukan kecurangan seperti yang telah dispesifikasikan pada mata kuliah Algoritma dan Pemrograman I 
dalam mengerjakan Remedial Alpro 1, jika saya melakukan kecurangan maka Allah/Tuhan adalah saksi saya, dan saya bersedia 
menerima hukumanNya. Aamiin.

*/

int main(){
	
	//variabel
	int n,m,i,j;
	scanf("%d",&n);//banyaknya inputan array of integer
	
	int angka[n];//banyaknya array angka sebanyak n
	for(i=0;i<n;i++){
		scanf("%d",&angka[i]);//banyaknya inputan angka sebanyak i
	}
	
	//banyaknya inputan array of string
	scanf("%d",&m);
	
	//banyaknya string sebanyak n
	char kata[m][100];
	for(j=0;j<m;j++){
		scanf("%s",&kata[j]);//banyaknya inputan kata sebanyak i
	}
	
	//variabel bungkusan untuk menampung hasil penjumlahan dari array of string
	tes hasil;
	hasil=tambah(m,kata);//hasil dideklasikan dengan fungsi tambah
	
	int max=maximal(m,hasil);//di deklarasikan dengan maximal
	
	//panggil prosedur untuk liat hasil valid/tidak valid
	validtidakvalid(n,angka,m,kata,hasil,max);
	
	
	
	return 0;
}