#include "header.h"

int main(){
	
	int n,m,i,j,k;
	scanf("%d",&n);
	
	titik awal[100];
	int koordinat[100];
	char arah[100][100];
	titik akhir[100];
	
	for(i=0;i<n;i++){
		scanf("%d",&awal[i].x);
		scanf("%d",&awal[i].y);
		
		scanf("%d",&m);
		akhir[i].x=awal[i].x;
		akhir[i].y=awal[i].y;
		for(j=0;j<m;j++){
			scanf("%s",&arah[j]);
			scanf("%d",&koordinat[j]);
			
			gerak(i,j,arah,koordinat,awal,akhir);
			
		}
		
	}
	
	tampil(n,akhir);
	
	return 0;
}