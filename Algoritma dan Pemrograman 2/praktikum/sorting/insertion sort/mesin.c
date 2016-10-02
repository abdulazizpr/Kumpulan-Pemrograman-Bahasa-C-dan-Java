#include "header.h"

void tampil(int angka[],int n){
	int i;
	
	for(i=0;i<n;i++){
		printf("%d ",angka[i]);
	}
	printf("\n");
	
}

void insertion(int angka[],int n){
	int i,j,angka_sisip;
	
	for(i=1;i<n;i++){
		angka_sisip=angka[i];
		j=i-1;
		while(angka_sisip<angka[j] && j>=0){
			angka[j+1]=angka[j];
			j=j-1;
		}
		
		//menempatkan angka_sisip
		angka[j+1]=angka_sisip;
		
	}
	
	tampil(angka,n);
	
}