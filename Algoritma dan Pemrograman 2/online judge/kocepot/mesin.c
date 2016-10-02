#include "header.h"

void gerak(int i,int j,char arah[100][100],int koordinat[100],titik awal[100],titik akhir[100]){
	
	if(strcmp(arah[j],"horizontal")==0){
		akhir[i].x=akhir[i].x+koordinat[j];
	}else if(strcmp(arah[j],"-horizontal")==0){
		akhir[i].x=akhir[i].x-koordinat[j];
	}else if(strcmp(arah[j],"vertikal")==0){
		akhir[i].y=akhir[i].y+koordinat[j];
	}else if(strcmp(arah[j],"-vertikal")==0){
		akhir[i].y=akhir[i].y-koordinat[j];
	}else if(strcmp(arah[j],"miring")==0){
		akhir[i].x=akhir[i].x+koordinat[j];
		akhir[i].y=akhir[i].y+koordinat[j];
	}else if(strcmp(arah[j],"-miring")==0){
		akhir[i].x=akhir[i].x-koordinat[j];
		akhir[i].y=akhir[i].y-koordinat[j];
	}
		
}

void tampil(int n,titik akhir[100]){
	
	int i,j;
	for(i=0;i<n;i++){
		printf("%d %d\n",akhir[i].x,akhir[i].y);
	}
	
}