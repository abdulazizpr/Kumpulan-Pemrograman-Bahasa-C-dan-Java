#include "header.h"

int main(){
	
	
	stack S;
	createEmpty(&S);
	
	int n,i;
	char karakter;
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		scanf(" %c",&karakter);
		push(karakter,&S);
	}
	
	operasi(&S);
	
	return 0;
}