#include "header.h"

/*
Saya Abdul Aziz Priatna(1307123) tidak melakukan kecurangan seperti yang telah dispesifikasikan pada 
mata kuliah Algoritma dan Pemograman 2 dalam mengerjakan TP7, jika saya melakukan kecurangan
maka Allah/Tuhan adalah saksi saya, dan saya bersedia menerima hukumanNya. Aamiin.
*/


int main(){
	
	//inputan file hepi
	int n=0,i,j;								//variabel buat menghitung banyaknya data
	laporan hepi[100];							//tabel buat menampung data dari file
	FILE *fsumber1;								//deklarasi file
	fsumber1=fopen("thepi.txt","r"); 
	
	//proses read file
	fscanf(fsumber1,"%s %s %d %d\n",&hepi[n].kode_barang,&hepi[n].nama_barang,&hepi[n].harga_barang,&hepi[n].jumlah_yang_terjual);		//cara readnya
	
	//di cek apakah dummy atau tidak
	while(strcmp(hepi[n].kode_barang,"##")!=0,strcmp(hepi[n].nama_barang,"##")!=0){
		fscanf(fsumber1,"%s %s %d %d\n",&hepi[n+1].kode_barang,&hepi[n+1].nama_barang,&hepi[n+1].harga_barang,&hepi[n+1].jumlah_yang_terjual);
		n++;
	}
	
	fclose(fsumber1);					   		//cara menutup akses file
	
	//inputan file moni
	int m=0;									//variabel buat menghitung banyaknya data
	laporan moni[100];							//tabel buat menampung data dari file
	FILE *fsumber2;								//deklarasi file
	fsumber2=fopen("tmoni.txt","r"); 
	
	//proses read file
	fscanf(fsumber2,"%s %s %d %d\n",&moni[m].kode_barang,&moni[m].nama_barang,&moni[m].harga_barang,&moni[m].jumlah_yang_terjual);		//cara readnya
	
	//di cek apakah dummy atau tidak
	while(strcmp(moni[m].kode_barang,"##")!=0,strcmp(moni[m].nama_barang,"##")!=0){
		fscanf(fsumber2,"%s %s %d %d\n",&moni[m+1].kode_barang,&moni[m+1].nama_barang,&moni[m+1].harga_barang,&moni[m+1].jumlah_yang_terjual);
		m++;
	}
	
	fclose(fsumber2);  //cara menutup akses file
	
	//inputan file piyu
	int o=0;									//variabel buat menghitung banyaknya data
	laporan piyu[100];							//tabel buat menampung data dari file
	FILE *fsumber3;								//deklarasi file
	fsumber3=fopen("tpiyu.txt","r"); 
	
	//proses read file
	fscanf(fsumber3,"%s %s %d %d\n",&piyu[o].kode_barang,&piyu[o].nama_barang,&piyu[o].harga_barang,&piyu[o].jumlah_yang_terjual);		//cara readnya
	
	//di cek apakah dummy atau tidak
	while(strcmp(piyu[o].kode_barang,"##")!=0,strcmp(piyu[o].nama_barang,"##")!=0){
		fscanf(fsumber3,"%s %s %d %d\n",&piyu[o+1].kode_barang,&piyu[o+1].nama_barang,&piyu[o+1].harga_barang,&piyu[o+1].jumlah_yang_terjual);
		o++;
	}
	
	fclose(fsumber3);  //cara menutup akses file
	
	//perhitungan total harga 
	for(i=0;i<n;i++){
		hepi[i].total=total_harga(i,hepi);
	}
	
	for(i=0;i<m;i++){
		moni[i].total=total_harga(i,moni);
	}
	
	for(i=0;i<o;i++){
		piyu[i].total=total_harga(i,piyu);
	} 
	
	//disorting dulu sebelum disatukan
	sorting(0,n-1,hepi);
	sorting(0,m-1,moni);
	sorting(0,o-1,piyu);	

	int nau1=n+m;						//inisialisasi jumlah array yang akan digabung
	laporan tobi1[nau1];				//deklarasi bungkusan tobi1 untuk penggabungan pertama
	merge(hepi,moni,tobi1,n,m);			//penggabungan tobi pertama
	
	int nau2=n+m+o;						//inisialisasi jumlah array yang akan digabung
	laporan tobi2[nau2];				//deklarasi bungkusan tobi1 untuk penggabungan terakhir
	merge(piyu,tobi1,tobi2,o,nau1);		//penggabungan tobi terakhir
	
	//menampilkan hasil ke layar cmd
	for(i=0;i<nau2;i++){
		printf("%s %s %d\n",tobi2[i].kode_barang,tobi2[i].nama_barang,tobi2[i].total);
	}	
	printf("Pengcopyan data berhasil !\n");
	
	//output akan dicopy di file ttobi.txt
 	FILE *fsumber4;
	fsumber4 = fopen("ttobi.txt", "w");		//inisialisasi mode write
	
	//proses pencopyan data
	for(i=0;i<nau2;i++){
		fprintf(fsumber4,"%s %s %d\n",tobi2[i].kode_barang,tobi2[i].nama_barang,tobi2[i].total);
	} 
		fprintf(fsumber4,"## ## ##\n");
	fclose(fsumber4);
	
	return 0;
}