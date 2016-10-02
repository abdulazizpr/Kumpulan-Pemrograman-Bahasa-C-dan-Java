#include "header.h"

int main(){
	
	list L;
	createList(&L);
	
	int n,i;
	scanf("%d",&n);
		
	bungkusan tabel[n];
	
	for(i=0;i<n;i++){
		scanf("%d",&tabel[i].jam);
		scanf("%d",&tabel[i].menit);
		scanf("%d",&tabel[i].detik);
		tabel[i].jumlah_detik = konversi(tabel[i].jam,tabel[i].menit,tabel[i].detik);
		addFirst(tabel[i].jam,tabel[i].menit,tabel[i].detik,tabel[i].jumlah_detik,&L);
	}
	
	printElement(L);	
	
	return 0;
}