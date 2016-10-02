#include "header.h"

/*
Saya Abdul Aziz Priatna(1307123) tidak melakukan kecurangan seperti yang telah dispesifikasikan pada 
mata kuliah Algoritma dan Pemograman 2 dalam mengerjakan TP 1, jika saya melakukan kecurangan
maka Allah/Tuhan adalah saksi saya, dan saya bersedia menerima hukumanNya. Aamiin.
*/

int main(){
	
	//varibael
	int b,k,i,j,l,m,ubah;
	
	//inputan dimensi matriks ukuran b x k
	scanf("%d %d",&b,&k);
	
	nama apa;//variabel bungkusan
	for(i=0;i<b;i++){
		for(j=0;j<k;j++){
			scanf("%d",&apa.matriks[i][j]);//inputan matriks
			apa.matriks2[i][j]=apa.matriks[i][j];//mengcopy isi matriks 1 ke matrisk 2
		}
	}
	
	//banyaknya perubahan yang akan di ubah
	scanf("%d",&ubah);
	char perubahan[ubah][100]; int x[ubah],y[ubah];
	
	for(i=0;i<ubah;i++){
		scanf("%s",&perubahan[i]);//inputan string perubahan
		scanf("%d %d",&x[i],&y[i]);//koordinat perubahan
	}
	
	
	//lalu di proses ke fungsi proses
	nama hasil=proses(b,k,apa,ubah,perubahan,x,y);
	
	//dan hasilnya di tampilkan di prosedur
	tampil(hasil,b,k);
	

	
	
return 0;	
}