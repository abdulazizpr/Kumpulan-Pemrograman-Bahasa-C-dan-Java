#include "header.h"

/*
Saya Abdul Aziz Priatna(1307123) tidak melakukan kecurangan seperti yang telah dispesifikasikan pada 
mata kuliah Algoritma dan Pemograman 2 dalam mengerjakan TP 3, jika saya melakukan kecurangan
maka Allah/Tuhan adalah saksi saya, dan saya bersedia menerima hukumanNya. Aamiin.
*/

int main(){
	
	//variabel
	int n,i,j;
	scanf("%d",&n);//banyaknya inputan
	
	dota karakter[n];//variabel bungkusan
	for(i=0;i<n;i++){
		scanf("%s",&karakter[i].tipe);//string tipe
		scanf("%s",&karakter[i].nama);//string nama
		scanf("%s",&karakter[i].skill);//string skill
	}
	
	insertionsort(n,karakter);//lalu di sorting menggunakan insertion sort
	
	return 0;
}