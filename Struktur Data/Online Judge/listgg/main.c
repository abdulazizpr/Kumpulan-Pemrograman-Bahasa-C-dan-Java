#include "header.h"

int main(){
	
	list L;
	createList(&L);
	
	int n,i,x=0,y=0;
	scanf("%d",&n);
	
	int arr[n];
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	
	int genap[100];
	int ganjil[100];
	
	for(i=0;i<n;i++){
		if(arr[i]%2==0){
			genap[x]=arr[i];
			x++;
		}else{
			ganjil[y]=arr[i];
			y++;
		}
	}
	
	addLastB(1,&L);
	for(i=0;i<y;i++){
		addLastK(ganjil[i],L.first);
	}
	
	addLastB(2,&L);
	for(i=0;i<x;i++){
		addLastK(genap[i],L.first->next);
	}
	
	printElement(L);
	return 0;
}