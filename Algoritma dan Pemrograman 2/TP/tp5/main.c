#include "header.h"

/*
Saya Abdul Aziz Priatna(1307123) tidak melakukan kecurangan seperti yang telah dispesifikasikan pada 
mata kuliah Algoritma dan Pemograman 2 dalam mengerjakan TP 5, jika saya melakukan kecurangan
maka Allah/Tuhan adalah saksi saya, dan saya bersedia menerima hukumanNya. Aamiin.
*/


int main(){
	
	int n,m,i;//variabel
	//banyaknya inputan tabel 1
	scanf("%d",&n);
	kelas tabel1[n];
	
	for(i=0;i<n;i++){
		scanf("%s",&tabel1[i].nama);
		scanf("%d",&tabel1[i].tanggal);
		scanf("%s",&tabel1[i].bulan);
		scanf("%d",&tabel1[i].tahun);
		tabel1[i].no_bulan=cekbulan(i,tabel1);//mengubah nama bulan menjadi no bulan
	}
	
	//banyaknya inputan tabel 2
	scanf("%d",&m);
	kelas tabel2[m];
	
	for(i=0;i<m;i++){
		scanf("%s",&tabel2[i].nama);
		scanf("%d",&tabel2[i].tanggal);
		scanf("%s",&tabel2[i].bulan);
		scanf("%d",&tabel2[i].tahun);
		tabel2[i].no_bulan=cekbulan(i,tabel2);//mengubah nama bulan menjadi no bulan
	}
	
	//sorting tiap tabel satu2
	sorting(tabel1,n);
	sorting(tabel2,m);
	
	kelas tabel3[n+m];//deklarasi untuk penggabungan
	merge(tabel1,tabel2,tabel3,n,m);//mulai penggabungan tabel
	
	//output hasil penggabungan
	for(i=0;i<n+m;i++){
		printf("%s %d %s %d\n",tabel3[i].nama,tabel3[i].tanggal,tabel3[i].bulan,tabel3[i].tahun);
	}
	
	
	return 0;
}