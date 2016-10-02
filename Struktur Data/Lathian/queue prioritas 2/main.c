#include "header.h"

int main(){
	
	int n,m,i,j,kapasitas;
	scanf("%d",&kapasitas);
	scanf("%d",&n);
	
	int	k;
	char huruf;
	int prioritas;
	
	queue Q;
	createEmpty(&Q);
	
	for(i=0;i<n;i++){
		scanf(" %c",&huruf);
		add(huruf,&Q);
	}
	
	scanf("%d",&m);
	char perintah[50];
	for(i=0;i<m;i++){
		scanf("%s",&perintah);
		if(strcmp(perintah,"masuk")==0){
			scanf(" %c",&huruf);
			if(countElement(Q)!=kapasitas) add(huruf,&Q);
		}
		else if(strcmp(perintah,"keluar")==0) del(&Q);
		else if(strcmp(perintah,"prioritas")==0){
			scanf(" %c",&huruf);	
			scanf("%d",&prioritas);	
			if(countElement(Q)!=kapasitas) add_prioritas(huruf,prioritas,&Q);
		}
	}
	
	printQueue(Q);
	
	return 0;
}