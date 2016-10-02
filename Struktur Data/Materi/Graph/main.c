#include "header.h"

int main(){
	
	graph G;
	createEmpty(&G);
	addSimpul('A',&G);
	addSimpul('B',&G);
	addSimpul('C',&G);
	addSimpul('D',&G);
	addSimpul('E',&G);
	addSimpul('F',&G);
	
	simpul *begin = findSimpul('A',G);
	simpul *end = findSimpul('B',G);
	if(begin != NULL && end != NULL){
		addJalur(end,3,&begin);
	}
	
	begin = findSimpul('B',G);
	end = findSimpul('D',G);
	if(begin != NULL && end != NULL){
		addJalur(end,3,&begin);
	}
	
	end = findSimpul('E',G);
	if(begin != NULL && end != NULL){
		addJalur(end,7,&begin);
	}
	
	begin = findSimpul('C',G);
	end = findSimpul('A',G);
	if(begin != NULL && end != NULL){
		addJalur(end,3,&begin);
	}
	
	begin = findSimpul('D',G);
	if(begin != NULL && end != NULL){
		addJalur(end,8,&begin);
	}
	
	end = findSimpul('C',G);
	if(begin != NULL && end != NULL){
		addJalur(end,3,&begin);
	}
	
	begin = findSimpul('E',G);
	end = findSimpul('D',G);
	if(begin != NULL && end != NULL){
		addJalur(end,4,&begin);
	}
	
	end = findSimpul('F',G);
	if(begin != NULL && end != NULL){
		addJalur(end,4,&begin);
	}
	
	begin = findSimpul('F',G);
	end = findSimpul('D',G);
	if(begin != NULL && end != NULL){
		addJalur(end,2,&begin);
	}
	
	printf("================\n");
	printGraph(G);
	printf("\n================\n");
	
/* 	begin = findSimpul('A',G);
	if(begin != NULL){
		delJalur('B',&begin);
	} */
	
	hapussimpuljalur('A',&G);
	
	printf("================\n");
	printf("setelah dihapus\n");
	printGraph(G);
	printf("\n================\n");
	
	return 0;
}