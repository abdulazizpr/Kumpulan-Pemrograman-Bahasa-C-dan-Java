#include "header.h"

int main(){
	
	list L;
	createList(&L);
	
	
	int n,i;
	scanf("%d",&n);
	
	char kata[100];
	for(i=0;i<n;i++){
		scanf("%s",&kata);
		
		eBaris *cari = searchB(kata[0],L);
		if(cari==NULL) addLastB(kata[0],&L);
		
		eBaris *sekarang = searchB(kata[0],L);
		addLastK(kata,sekarang);
	}
	
	printElement(L);
	
	return 0;
}