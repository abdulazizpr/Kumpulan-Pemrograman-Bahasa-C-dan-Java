#include "header.h"

int main(){
	
	graph G;
	createEmpty(&G);
	
	int n,i;
	scanf("%d",&n);
	
	simpul *begin;
	simpul *end;
	
	char kota_awal;
	char kota_akhir;
	for(i=0;i<n;i++){
		scanf(" %c %c",&kota_awal,&kota_akhir);
	}
	
	/* scanf("%s",&masukan);
	
	addSimpul('A',&G);
	addSimpul('B',&G);
	addSimpul('C',&G);
	addSimpul('D',&G);
	addSimpul('E',&G);
	
	simpul *begin = findSimpul('A',G);
	simpul *end = findSimpul('C',G);
	if(begin != NULL && end != NULL){
		addJalur(end,&begin);
	}
	
	begin = findSimpul('A',G);
	end = findSimpul('D',G);
	if(begin != NULL && end != NULL){
		addJalur(end,&begin);
	}
	
	begin = findSimpul('B',G);
	end = findSimpul('A',G);
	if(begin != NULL && end != NULL){
		addJalur(end,&begin);
	}
	
	begin = findSimpul('B',G);
	end = findSimpul('E',G);
	if(begin != NULL && end != NULL){
		addJalur(end,&begin);
	}
	
	begin = findSimpul('D',G);
	end = findSimpul('B',G);
	if(begin != NULL && end != NULL){
		addJalur(end,&begin);
	}
	
	printGraph(G);	
	delSimpul('B',&G);
	printGraph(G); */

	
	return 0;
}