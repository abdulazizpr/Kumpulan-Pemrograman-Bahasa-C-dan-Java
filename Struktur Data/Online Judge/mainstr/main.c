#include "header.h"

int main(){
	
	list L;
	createList(&L);
	
	int n,i;
	scanf("%d",&n);
	
	bungkusan tabel[n];
	
	for(i=0;i<n;i++){
		scanf("%s",&tabel[i].kata);
		tabel[i].jumlah_a=hasil_jumlah(tabel[i].kata);
		addFirst(tabel[i].kata,tabel[i].jumlah_a,&L);
	}
	
	printElement(L);
	
	
	return 0;
}