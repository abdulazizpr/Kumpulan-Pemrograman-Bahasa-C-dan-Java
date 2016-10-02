#include "header.h"

int main(){
	
	list L;
	createList(&L);
	
	int n,i;
	scanf("%d",&n);
	
	char kata[100];
	for(i=0;i<n;i++){
		scanf("%s",&kata);
		addLast(kata,&L);
	}
	
	palindrom(L);
	
	return 0;
}