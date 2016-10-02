#include "header.h"

/*
Saya Abdul Aziz Priatna(1307123) tidak melakukan kecurangan seperti yang telah dispesifikasikan pada 
mata kuliah Algoritma dan Pemograman 2 dalam mengerjakan TP 5, jika saya melakukan kecurangan
maka Allah/Tuhan adalah saksi saya, dan saya bersedia menerima hukumanNya. Aamiin.
*/


int main(){
	
	int n,i;
	int cari_desimal;
	//inputan tabel sebanyak n
	scanf("%d",&n);
	
	//deklarasi bungkusan
	bungkusan tabel1[n];
	bungkusan tabel2[n];
	bungkusan tabel3[n];
	bungkusan tabel4[n];
	
	//inputan
	for(i=0;i<n;i++){
		scanf("%s",&tabel1[i].binner);
	}
	for(i=0;i<n;i++){
		scanf("%s",&tabel2[i].binner);
	}
	for(i=0;i<n;i++){
		scanf("%s",&tabel3[i].binner);
	}
	for(i=0;i<n;i++){
		scanf("%s",&tabel4[i].binner);
	}
	
	//inputan pencarian
	scanf("%d",&cari_desimal);
	
	//deklarasi bungkusan hasil
	bungkusan hasil1[n];
	bungkusan hasil2[n];

	for(i=0;i<n;i++){
		//penjumlahanbiner tabel 1 dan 2
		strcpy(hasil1[i].binner,penjumlahanbiner(i,tabel1,tabel2));
		
		//penjumlahanbiner tabel 3 dan 4
		strcpy(hasil2[i].binner,penjumlahanbiner(i,tabel3,tabel4));
		
		//konversikan ke desimal
		hasil1[i].desimal=konversibiner(i,hasil1);
		hasil2[i].desimal=konversibiner(i,hasil2);
	}
	
	//disorting sebelum di merge
	sorting(hasil1,n);
	sorting(hasil2,n);
	
	//deklarasi penggabungan hasil
	bungkusan gabung[n+n];
	
	//hasil1 dan hasil2 digabungkan di merge
	merge(hasil1,hasil2,gabung,n,n);
	
	binary_search(gabung,n+n,cari_desimal);

	return 0;
}