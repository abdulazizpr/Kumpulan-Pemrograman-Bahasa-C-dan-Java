#include "header.h"

int main(){
	
	
	int i;
	scanf("%d",&n);
	
	list L;
	
	createList(&L);	
	
	data barang;
	for(i=0;i<n;i++){
		scanf("%s",&barang.kode_brg);
		scanf("%s",&barang.nama_brg);
		addFirst(barang.kode_brg,barang.nama_brg,&L);
	}
	
	printElemen(L);
	
	
	return 0;
}