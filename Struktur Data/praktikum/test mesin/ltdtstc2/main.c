#include "header.h"

int main(){
	
	list L;
	createList(&L);
	
	int i;
	data barang[5];
	for(i=0;i<5;i++){
		scanf("%s",&barang[i].kode_barang);
		scanf("%s",&barang[i].jenis_barang);
		scanf("%d",&barang[i].jumlah);
	}
	
	addFirst(barang[0].kode_barang,barang[0].jenis_barang,barang[0].jumlah,&L);
	addLast(barang[1].kode_barang,barang[1].jenis_barang,barang[1].jumlah,&L);
	addFirst(barang[2].kode_barang,barang[2].jenis_barang,barang[2].jumlah,&L);
	
	elemen *terakhir = L.first;
	while(terakhir->next != NULL){
		terakhir = terakhir->next;
	}
	
	addAfter(terakhir,barang[3].kode_barang,barang[3].jenis_barang,barang[3].jumlah,&L);
	printElement(L);
	
	printf("=====\n");
	
	delLast(&L);
	delFirst(&L);
	
	printElement(L);
	
	printf("=====\n");
	
	addFirst(barang[4].kode_barang,barang[4].jenis_barang,barang[4].jumlah,&L);
	delAfter(L.first,&L);
	
	printElement(L);
	
	printf("=====\n");
	
	delAll(&L);
	printElement(L);
	
	printf("=====\n");
	
	
	
	return 0;
}