#include "header.h"

int main(){
	
	list L;
	createList(&L);
	
	int n,i,jumlah_stok;
	scanf("%d",&n);
	
	data tabel[n];
	for(i=0;i<n;i++){
		scanf("%s %d",&tabel[i].barang,&tabel[i].stok);
		addLast(tabel[i].barang,tabel[i].stok,&L);
	}
	
	scanf("%d",&jumlah_stok);
	
	for(i=0;i<n;i++) hapus_barang(jumlah_stok,&L);
	
	printElement(L);
	
	return 0;
}