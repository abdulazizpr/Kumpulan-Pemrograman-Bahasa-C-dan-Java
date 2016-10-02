#include "header.h"

int main(){
	
	n = 100;
	
	list L;
	
	createList(&L);
	
	int m,i,harga_lelang;
	scanf("%d",&m);
	
	data peserta[m];
	for(i=0;i<m;i++){
		scanf("%d",&peserta[i].harga);
		scanf("%s",&peserta[i].nama);
		addFirst(peserta[i].harga,peserta[i].nama,&L);
	}
	
	scanf("%d",&harga_lelang);
	
	printElemen(L,harga_lelang);
	
	
	return 0;
}