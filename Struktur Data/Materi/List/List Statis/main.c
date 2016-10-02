#include "header.h"

int main(){
	
	n = 10;
	
	list L;
	
	createList(&L);
	printElemen(L);
	
	printf("=================\n");
	addFirst("13501019","Orang_1","A",&L);
	printf("%d\n",L.first);
	printf("%d\n",L.data[L.first].next);
	addAfter(L.first,"13501037","Orang_2","A",&L);
	addLast("13501019","Orang_3","A",&L);
	printElemen(L);
	
	printf("=================\n");
	
	delLast(&L);
	delAfter(L.first,&L);
	delFirst(&L);
	//delAll(&L);
	printElemen(L);
	
	printf("=================\n");
	
	
	return 0;
}