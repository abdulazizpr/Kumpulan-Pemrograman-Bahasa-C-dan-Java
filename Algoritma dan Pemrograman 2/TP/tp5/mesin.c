#include "header.h"

//mengecek bulan
int cekbulan(int i,kelas* tabel){
	
	int temp;
	if(strcmp(tabel[i].bulan,"januari")==0){
		temp=1;
	}else if(strcmp(tabel[i].bulan,"februari")==0){
		temp=2;
	}else if(strcmp(tabel[i].bulan,"maret")==0){
		temp=3;
	}else if(strcmp(tabel[i].bulan,"april")==0){
		temp=4;
	}else if(strcmp(tabel[i].bulan,"mei")==0){
		temp=5;
	}else if(strcmp(tabel[i].bulan,"juni")==0){
		temp=6;
	}else if(strcmp(tabel[i].bulan,"juli")==0){
		temp=7;
	}else if(strcmp(tabel[i].bulan,"agustus")==0){
		temp=8;
	}else if(strcmp(tabel[i].bulan,"september")==0){
		temp=9;
	}else if(strcmp(tabel[i].bulan,"oktober")==0){
		temp=10;
	}else if(strcmp(tabel[i].bulan,"november")==0){
		temp=11;
	}else if(strcmp(tabel[i].bulan,"desember")==0){
		temp=12;
	}
	
	return temp;
}

//prosedur sorting
void sorting(kelas* tabel,int n){
	
	int i,j,minindeks;
	
	for(i=0;i<n-1;i++){
		//inisialisasi indeks minimum
		minindeks=i;
		
		kelas temp;
		/*untuk mencari nilai minimum*/
		for(j=i+1;j<n;j++){
			if((tabel[j].tahun<tabel[minindeks].tahun)||(tabel[j].tahun==tabel[minindeks].tahun && 
			tabel[j].no_bulan<tabel[minindeks].no_bulan)||(tabel[j].no_bulan==tabel[minindeks].no_bulan && 
			tabel[j].tanggal<tabel[minindeks].tanggal)){
				//jika ada tahun yang sama maka diurutkan berdasarkan bulan atau jika ada bulan yang sama maka diurutkan berdasarkan tanggal
				minindeks=j;
			}
		}
		temp=tabel[i];
		tabel[i]=tabel[minindeks];
		tabel[minindeks]=temp;
	}
	
	
}

//prosedur penggabungan tabel terurut
void merge(kelas* tabel1,kelas* tabel2,kelas* tabel_urut,int n,int m){
		
	int index1=0;
	int index2=0;
	int index3=0;
	
	while(index1<n && index2<m){
		if((tabel1[index1].tahun<tabel2[index2].tahun)||
		(tabel1[index1].tahun==tabel2[index2].tahun && tabel1[index1].no_bulan<tabel2[index2].no_bulan)||
		(tabel1[index1].no_bulan==tabel2[index2].no_bulan && tabel1[index1].tanggal<tabel2[index2].tanggal)){
			//jika ada tahun yang sama maka diurutkan berdasarkan bulan atau jika ada bulan yang sama maka diurutkan berdasarkan tanggal
			tabel_urut[index3]=tabel1[index1];
			index1++;
			index3++;
		}else if((tabel1[index1].tahun>tabel2[index2].tahun)||
		(tabel1[index1].tahun==tabel2[index2].tahun && tabel1[index1].no_bulan>tabel2[index2].no_bulan)||
		(tabel1[index1].no_bulan==tabel2[index2].no_bulan && tabel1[index1].tanggal>tabel2[index2].tanggal)){
			//jika ada tahun yang sama maka diurutkan berdasarkan bulan atau jika ada bulan yang sama maka diurutkan berdasarkan tanggal
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
