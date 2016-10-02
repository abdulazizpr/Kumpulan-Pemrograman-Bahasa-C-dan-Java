#include "list.h"

int main(){
	
	list L;
	createList(&L);
	printElement(L);
	printf("=================\n");
	
	addFirst("1305019","Andik","A",&L);
	addAfter(L.first,"1305037","Shalahuddin","A",&L);
	addLast("1305058","Rosa","A",&L);
	printElement(L);
	
	printf("=================\n");
	
	delLast(&L);
	delAfter(L.first,&L);
	delFirst(&L);
	//delAll(&L);
	printElement(L);
	
	printf("=================\n");
	
	return 0;
}