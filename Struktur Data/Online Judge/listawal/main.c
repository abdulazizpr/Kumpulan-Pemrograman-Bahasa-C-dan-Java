#include "header.h"

eBaris *cariAkhirB(list L){
	if(L.first != NULL){
		eBaris *tunjuk = L.first;

		while(tunjuk->next != NULL){
			tunjuk = tunjuk->next;
		}
		return tunjuk;
	}
	return NULL;
}

eBaris *cariB(int angka, list L){
	if(L.first != NULL){
		eBaris *tunjuk = L.first;

		//yang dicari 
		while(tunjuk != NULL){
			if (tunjuk->elmt.angka==angka){
				return tunjuk;
			}
			tunjuk = tunjuk->next;
		}
		return NULL;
	}
	return NULL;
}

int main(){
	
	list L;
	createList(&L);
	
	
	int n,i;
	scanf("%d",&n);
	
	int angka;
	int satuan;
	for(i=0;i<n;i++){
		scanf("%d",&angka);
		if(angka/10<=0) satuan = angka;
		else satuan = angka/10;
		
		eBaris *baris = cariB(satuan,L);
		
		if(baris==NULL){
			
			addLastB(satuan,&L);
			
			eBaris *akhir = cariAkhirB(L);
			
			addLastK(angka,akhir);			
		}else{
			addLastK(angka,baris);
		}
	}
	
	printElement(L);
	/* printElement(L);
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
	
	printf("=================\n"); */
	
	return 0;
}