#include "header.h"

void tampil(char nama[50][50],int n){
	int i;
	
	for(i=0;i<n;i++){
		printf("%s\n",nama[i]);
	}
	
}

void sorting(char nama[50][50],int n){
	
	int i,j,minindeks;
	char temp[50];
	
	/*proses pertukaran*/
	for(i=0;i<n-1;i++){
		minindeks=i;
		
		//untuk membandingkan
		for(j=i+1;j<n;j++){
			//mengurutkan dari a-z jika -1
			if(strcmp(nama[j],nama[minindeks])==-1){
				minindeks=j;
			}
		}
		//pertukaran
		strcpy(temp,nama[i]);
		strcpy(nama[i],nama[minindeks]);
		strcpy(nama[minindeks],temp);
	}
	
	tampil(nama,n);
	
}