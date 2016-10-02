#include "header.h"

int main(){
	
	list L;
	createList(&L);
	
	
	int n,i;
	scanf("%d",&n);
	
	data kamu[n];
	for(i=0;i<n;i++){
		scanf("%s",&kamu[i].kata);
		kamu[i].nilai=jumlah_ascii(kamu[i].kata);
		addLast(kamu[i].kata,kamu[i].nilai,&L);
	}
	
	sort_depan(&L);
	sort_belakang(&L);
	printElement(L);
	
	
	return 0;
}