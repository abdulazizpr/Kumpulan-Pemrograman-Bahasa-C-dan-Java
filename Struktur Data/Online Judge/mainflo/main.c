#include "header.h"

int main(){
	
	list L;
	createList(&L);
	
	int n,i;
	scanf("%d",&n);
	
	
	bungkusan tabel[n];
	
	for(i=0;i<n;i++){
		scanf("%lf",&tabel[i].koma);
		tabel[i].blk_koma = hasil_blk(tabel[i].koma);
		addFirst(tabel[i].koma,tabel[i].blk_koma,&L);
	}
	
	printElement(L);	
	
	return 0;
}