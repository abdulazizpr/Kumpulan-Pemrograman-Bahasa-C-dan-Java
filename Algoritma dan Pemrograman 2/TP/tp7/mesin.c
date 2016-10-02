#include "header.h"

//fungsi hitung total harga
int total_harga(int i,laporan* tabel){
	
	return tabel[i].harga_barang*tabel[i].jumlah_yang_terjual;
	
}

//prosedur sorting
void sorting(int l,int r,laporan* tabel){
	
	//variabel
	int i,j;
	laporan temp;
	i=l;
	j=r;
	
	do{
		strcpy(temp.kode_barang,tabel[(l+r)/2].kode_barang);//pengkopian string dari pivot tengah
		while(strcmp(tabel[i].kode_barang,temp.kode_barang)==-1){
			i++;//pengecekan terus maju hingga bertemu titik j
		}
		while(strcmp(tabel[j].kode_barang,temp.kode_barang)==1){
			j--;//pengecekan terus mundur hingga bertemu titik i
		}
		if(i<=j){//jika lebih kecil atau sama dengan j
			//maka ia akan bertukar tempat
			temp=tabel[i];
			tabel[i]=tabel[j];
			tabel[j]=temp;
			i++;//terus maju
			j--;//terus mundur
		}
	}while(i<j);
	
	if(l<j){//jika l kurang dari j
		sorting(l,j,tabel);//maka ia melakukan sorting lagi dari kiri ke kanan
	}
	if(i<r){//jika i kurang dari r
		sorting(i,r,tabel);//maka ia melakukan sorting lagi dari kanan ke kiri
	}
	
}

//prosedur penggabungan tabel
void merge(laporan tabel1[],laporan tabel2[],laporan tabel_urut[],int n,int m){
		
	int index1=0;
	int index2=0;
	int index3=0;
	
	while(index1<n && index2<m){
		if(strcmp(tabel1[index1].kode_barang,tabel2[index2].kode_barang)==-1){
			tabel_urut[index3]=tabel1[index1];
			index1++;
			index3++;
		}else if(strcmp(tabel1[index1].kode_barang,tabel2[index2].kode_barang)==1){
			tabel_urut[index3]=tabel2[index2];
			index2++;
			index3++;
		}else{
			tabel_urut[index3]=tabel1[index1];
			index1++;
			index3++;
			tabel_urut[index3]=tabel2[index2];
			index2++;
			index3++;
		}
	}
	
	int i;
	for(i=index1;i<n;i++){
		tabel_urut[index3]=tabel1[i];
		index3++;
	}
	for(i=index2;i<m;i++){
		tabel_urut[index3]=tabel2[i];
		index3++;
	}
	
}