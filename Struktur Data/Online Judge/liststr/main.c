#include "list.h"

int main(){
	
	list L;
	createList(&L);
	
	int n,i;
	scanf("%d",&n);
	
	char kata[n][100];
	
	for(i=0;i<n;i++){
		scanf("%s",&kata[i]);
		addFirst(kata[i],&L);
	}
	
	printElement(L);
	
	
	return 0;
}