#include "header.h"

int main(){
	
	int n,i,j;
	scanf("%d",&n);
	
	int kapasitas[n];
	int	k;
	char huruf;
	char huruf2[n];
	int prioritas[n];
	
	queue Q[n];
	for(i=0;i<n;i++){
		createEmpty(&Q[i]);
	}
	
	for(i=0;i<n;i++){
		scanf("%d",&kapasitas[i]);
		scanf("%d",&k);
		for(j=0;j<k;j++){
			scanf(" %c",&huruf);
			add(huruf,&Q[i]);
		}
		scanf(" %c",&huruf2[i]);
		scanf("%d",&prioritas[i]);
	}
	
	for(i=0;i<n;i++){
		cekkapasitas(kapasitas[i],huruf2[i],prioritas[i],&Q[i]);
	}
	
	return 0;
}