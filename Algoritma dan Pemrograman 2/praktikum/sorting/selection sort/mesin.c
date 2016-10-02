#include "header.h"

void tampil(int angka[],int n){
	int i;
	
	for(i=0;i<n;i++){
		printf("%d ",angka[i]);
	}
	printf("\n");
	
}



void selection(int angka[],int n){
	int i,j,minindeks,temp;
	
	for(i=0;i<n-1;i++){
		//inisialisasi indeks minimum
		minindeks=i;
		/*untuk mencari nilai minimum*/
		for(j=i+1;j<n;j++){
			if(angka[j]<angka[minindeks]){
				minindeks=j;
			}
		}
		//pertukaran dengan nilai minimum
		temp=angka[minindeks];
		angka[minindeks]=angka[i];
		angka[i]=temp;
	}
	
	tampil(angka,n);
	
}