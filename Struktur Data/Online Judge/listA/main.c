#include "header.h"

int main(){
	
	list L;
	createList(&L);
	
	int n,i,j;
	scanf("%d",&n);
	
	char kata[n][100];
	for(i=0;i<n;i++){
		scanf("%s",&kata[i]);
		
		int jumlah_a = hitungA(kata[i]);
		
		eBaris *baris = tambahCariB(jumlah_a,&L);
		
		addLastK(kata[i],baris);
		
	}
	
	printElement(L);
	
	
	return 0;
}