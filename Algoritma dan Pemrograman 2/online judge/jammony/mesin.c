#include "header.h"

void tampil(waktu mony[],int n){
	int i;
	
	for(i=0;i<n;i++){
		printf("%.2d:%.2d:%.2d\n",mony[i].jam,mony[i].menit,mony[i].detik);
		//printf("%d\n",jmldetik[i]);
	}
	
}

void sorting(int jmldetik[],int n){
	
	int i,j,minindeks,temp;
	
	for(i=0;i<n-1;i++){
		
		minindeks=i;
		
		for(j=i+1;j<n;j++){
			if(jmldetik[j]<jmldetik[minindeks]){
				minindeks=j;
			}
		}
		
		temp=jmldetik[i];
		jmldetik[i]=jmldetik[minindeks];
		jmldetik[minindeks]=temp;
	}
	
	konversi(n,jmldetik);
}

void konversi(int n,int jmldetik[]){
	int i;
	
	waktu mony[n];
	for(i=0;i<n;i++){
		mony[i].jam=(jmldetik[i]%86400)/3600;
		mony[i].menit=((jmldetik[i]%86400)%3600)/60;
		mony[i].detik=((jmldetik[i]%86400)%3600)%60;
	}
	
	tampil(mony,n);
	
}
