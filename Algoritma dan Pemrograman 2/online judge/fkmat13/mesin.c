#include "header.h"

int faktorial(int n){
	
	if((n ==0) || (n == 1)){
			return 1;
	}else{
		return (n * faktorial(n-1));
	}
}

void hslfaktorial(int kolom, int baris, int hkolom[100],int hbaris[100]){
	long long int hasilkolom[kolom],hasilbaris[baris],hasil[kolom][baris];
	
	int i,j;
	for(i=0;i<kolom;i++){
		hasilkolom[i]=faktorial(hkolom[i]);
	}
	
	for(i=0;i<baris;i++){
		hasilbaris[i]=faktorial(hbaris[i]);
	}
	
	for(i=0;i<baris;i++){
		for(j=0;j<kolom;j++){
			hasil[j][i]=hasilkolom[j]*hasilbaris[i];
			printf("%lld\n",hasil[j][i]);
		}
	}
	
}