#include "header.h"

void uruttabel(int tabel[],int n){
	int tampung,tukar,i;
	do{
		tukar=0;
		for(i=0;i<n;i++){
			if(tabel[i]>tabel[i+1]){
				tampung=tabel[i];
				tabel[i]=tabel[i+1];
				tabel[i+1]=tampung;
				tukar=1;
			}
		}
	}while(tukar==1);
	
}

void merge(int tabel1[],int tabel2[],int tabel_urut[],int n,int m){
	
	uruttabel(tabel1,n);
	uruttabel(tabel2,m);
	
	int index1=0;
	int index2=0;
	int index3=0;
	
	while(index1<n && index2<m){
		if(tabel1[index1]<tabel2[index2]){
			tabel_urut[index3]=tabel1[index1];
			index1++;
			index3++;
		}else if(tabel1[index1]>tabel2[index2]){
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
	
	int i=0;
	for(i=index1;i<n;i++){
		tabel_urut[index3]=tabel1[i];
		index3++;
	}
	for(i=index2;i<m;i++){
		tabel_urut[index3]=tabel2[i];
		index3++;
	}
}