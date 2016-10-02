#include "header.h"

int main(){
	
	list L;
	createList(&L);
	printElement(L);
	printf("=================\n");
	
	addFirstB("1","Orang_1",&L);
		addFirstK("IK40K1","A",L.first);
		addAfterK(L.first->col,"IK40Z1","A");
		addLastK("IK40Z2","A",L.first);
	addAfterB(L.first,"2","Orang_2");
		addFirstK("T15141","A",L.first->next);
		addLastK("IF5021","A",L.first->next);
	addLastB("3","Orang_3",&L);
		addFirstK("IF5321","A",L.first->next->next);
	printElement(L);
	
		
	printf("=================\n");
	
	eBaris *baris = L.first;
	
	while(baris != NULL){
		delAllK(baris);
		baris = baris->next;
	}
	delAllB(&L);
	
	printElement(L);
	
	printf("=================\n");
	
	return 0;
}