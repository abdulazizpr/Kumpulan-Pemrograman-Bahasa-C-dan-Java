#include "header.h"

/*
Saya Abdul Aziz Priatna(1307123) tidak melakukan kecurangan seperti yang telah dispesifikasikan pada 
mata kuliah Algoritma dan Pemograman 2 dalam mengerjakan TP 4, jika saya melakukan kecurangan
maka Allah/Tuhan adalah saksi saya, dan saya bersedia menerima hukumanNya. Aamiin.
*/

int main(){
	
	//inputan banyaknya masukan
	scanf("%d",&n);
	
	//menginput data sebanyak i
	for(i=0;i<n;i++){
		scanf("%s",&kueh[i].toko);
		scanf("%s",&kueh[i].makanan);
		scanf("%d",&kueh[i].harga);
	}
	
	//melakukan sorting degan quicksort
	quicksort(0,n-1);
	
	//menampilkan hasil sorting
	tulis();
	
	return 0;
}
