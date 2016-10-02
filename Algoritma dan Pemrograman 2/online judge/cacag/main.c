#include "header.h"

int main(){
	
	int n,i,status;
	float hasil[100],nilai;
	
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%f",&angka[i][0].pembilang);
		scanf("%f",&angka[i][0].penyebut);
		scanf("%f",&angka[i][1].pembilang);
		scanf("%f",&angka[i][1].penyebut);
	}
	scanf("%f",&nilai);
	
	for(i=0;i<n;i++){
		sorting(i);
		hasil[i]=cek(i);
	}
	
	status=cari(n,nilai,hasil);
	
	tampil(n,status);
	
	
	return 0;
}