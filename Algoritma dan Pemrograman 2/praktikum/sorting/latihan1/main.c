#include "header.h"

int main(){
	
	int i,n;
	scanf("%d",&n);
	char nama[n][50];
	
	//input
	for(i=0;i<n;i++){
		scanf("%s",&nama[i]);
	}
	
	//pengurutan
	sorting(nama,n);
	
	return 0;
}