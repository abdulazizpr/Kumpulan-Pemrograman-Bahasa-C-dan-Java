#include "header.h"

int main(){
	
	int n,i,j,kali,hasil[100],status;
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		scanf("%d",&angka[i].a);
		scanf("%d",&angka[i].b);
		scanf("%d",&angka[i].c);
	}
	
	scanf("%d",&kali);
	for(i=0;i<n;i++){
		sorting(i);
		hasil[i]=cek(i);
	}
	
	status=cari(n,kali,hasil);
	
	tampil(n,status);
	
	return 0;
}