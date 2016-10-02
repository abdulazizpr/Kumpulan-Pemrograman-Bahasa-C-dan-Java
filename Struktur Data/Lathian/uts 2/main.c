#include "header.h"

int main(){
	
	list L;
	createList(&L);
	
	int n,m,i,j;
	scanf("%d",&n);
	
	char huruf;
	int angka;
	
	eBaris *maju;
	for(i=0;i<n;i++){
		scanf(" %c",&huruf);
		scanf("%d",&m);
		addLastB(huruf,&L);
		
		if(i==0) maju = L.first;
		else maju = maju->next;
		
		for(j=0;j<m;j++){
			scanf("%d",&angka);
			addLastK(angka,maju);
		}
	}
	
	printElement(L);
	
	return 0;
}