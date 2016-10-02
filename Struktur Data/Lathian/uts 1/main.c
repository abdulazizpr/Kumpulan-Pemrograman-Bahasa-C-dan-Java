#include "header.h"

int main(){
	
	list L;
	createList(&L);
	
	int n,i,j;
	scanf("%d",&n);
	
	int besar,kecil[n];
	
	for(i=0;i<n;i++){
		scanf("%d",&besar);
		scanf("%d",&kecil[i]);
		addLastB(besar,&L);
	}
	
	i = 0;
	eBaris *now = L.first;
	while(now != NULL && i<n){
		for(j=2;j<=kecil[i];j++){
			if(now->elmt.angka_besar%j==0){
				addLastK(j,now);
			}
		}
		now = now->next;
		i++;
	}
	
	printElement(L);
	
	return 0;
}