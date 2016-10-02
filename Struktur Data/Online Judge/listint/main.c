#include "list.h"

int main(){
	
	list L;
	createList(&L);
	
	int n,i;
	scanf("%d",&n);
	
	int angka[n];
	
	for(i=0;i<n;i++){
		scanf("%lld",&angka[i]);
		addFirst(angka[i],&L);
	}
	
	printElement(L);
	
	
	return 0;
}