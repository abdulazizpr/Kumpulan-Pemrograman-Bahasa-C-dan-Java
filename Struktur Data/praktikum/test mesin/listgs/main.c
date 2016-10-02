#include "header.h"

int main(){
	
	n = 7;
	
	list L;
	createList(&L);
	
	int i;
	data tabel[n];
	for(i=0;i<n;i++){
		scanf("%d %s",&tabel[i].angka,&tabel[i].kata);
	}
	
	addLast(tabel[0].angka,tabel[0].kata,&L);
	addFirst(tabel[1].angka,tabel[1].kata,&L);
	addAfter(L.first,tabel[2].angka,tabel[2].kata,&L);
	printElemen(L);
	
	delAfter(L.first,&L);
	delLast(&L);
	delFirst(&L);
	printElementoHead(L);
	
	addFirst(tabel[3].angka,tabel[3].kata,&L);
	addLast(tabel[4].angka,tabel[4].kata,&L);
	addFirst(tabel[5].angka,tabel[5].kata,&L);
	addAfter(L.first,tabel[6].angka,tabel[6].kata,&L);
	printElemen(L);
	
	
	return 0;
}