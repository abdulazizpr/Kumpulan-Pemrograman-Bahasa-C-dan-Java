#include "header.h"

int main(){
	
	int n,i,j;
	scanf("%d",&n);
	
	int jmldetik[n];
	
	for(i=0;i<n;i++){
		scanf("%d",&jmldetik[i]);
	}
	
	sorting(jmldetik,n);
	
	return 0;
}
