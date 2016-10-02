#include "header.h"

int main(){
	
	scanf("%d",&n);
	
	list L;
	
	createList(&L);
	
	int i;
	float baru[n];
	for(i=0;i<n;i++){
		scanf("%f",&baru[i]);
		
		if(countElement(L)<3) addLast(baru[i],&L);
		else{
			if((int)baru[i]%2==0){
				addAfter(L.data[L.first].next,baru[i],&L);
			}else{
				addLast(baru[i],&L);
			}
		}
	}
	
	printElemen(L);
	
	
	return 0;
}