#include "header.h"

//proses penjumlahan huruf
bungkusan jumlahhuruf(int a,char kata[100][100],char cari){
	
	int i,j;
	bungkusan jumlah;
	for(i=0;i<a;i++){
		jumlah.jumlahhuruf[i]=0;//inisialisasi di array
		for(j=0;j<strlen(kata[i]);j++){//jika ada huruf yang di cari
			if(kata[i][j]==cari) jumlah.jumlahhuruf[i]++;//maka jumlahhuruf terus bertambah sesuai di indeks masing2
		}
	}
	
	//lempar bungkusan jumlah
	return jumlah;
}

//sequential_search
int sequential_search(bungkusan jumlahhuruf,int n,int angkacari){
	
	int ketemu=0;
	int i=0;
	
	//proses pencarian
	while(i<n && ketemu==0){
		if(jumlahhuruf.jumlahhuruf[i]==angkacari){//jika jumlah huruf sama dengan angka yang di cari
			ketemu=1;//maka ketemu 1
		}else{//jika tidak
			i++;//maka terus mencari
		}
	}
	
	//lempar ketemu
	return ketemu;
}

//binary_search
int binary_search(bungkusan jumlahhuruf,int n,int angkacari){
	int ketemu=0;
	int i=0;
	int j=n-1;
	int k;
	
	//proses pencarian
	while(ketemu==0 && i<=j){
		k=(i+j)/2;
		if(jumlahhuruf.jumlahhuruf[k]==angkacari){//jika jumlah huruf sama
			ketemu=1;//maka ketemu 1
		}else{//jika tidak
			if(jumlahhuruf.jumlahhuruf[k]>angkacari){//jika jumlah huruf lebih besar dari angkacari
				j=k-1;//maka proses mundur
			}else{//jika tidak
				i=k+1;//maka proses maju
			}
			
		}
	}
	
	//lempar ketemu
	return ketemu;

}	
