#include "header.h"

int main(){
	
	list L;
	createList(&L);
	
	data tabel[7];
	int i;
	for(i=0;i<7;i++){
		scanf("%d",&tabel[i].angka);
		scanf("%s",&tabel[i].kata);
	}
	
	addLast(tabel[0].angka,tabel[0].kata,&L);
	addFirst(tabel[1].angka,tabel[1].kata,&L);
	addAfter(L.first,tabel[2].angka,tabel[2].kata,&L);
	printElement(L);
	
	delAfter(L.first,&L);
	delLast(&L);
	delFirst(&L);
	printElement(L);
	
	addFirst(tabel[3].angka,tabel[3].kata,&L);
	addLast(tabel[4].angka,tabel[4].kata,&L);
	addFirst(tabel[5].angka,tabel[5].kata,&L);
	addAfter(L.first->next->next->prev,tabel[6].angka,tabel[6].kata,&L);
	
	printelementohead(L);
	
	
	return 0;
}