#include "header.h"

int main(){
	
	list genap,ganjil;
	createList(&genap);
	createList(&ganjil);
	
	int n,i,jumlah_stok;
	scanf("%d",&n);
	
	int angka;
	for(i=0;i<n;i++){
		scanf("%d",&angka);
		if(angka%2==0){
			addLast(angka,&genap);
		}else{
			addLast(angka,&ganjil);
		}
	}

	printf("Ganjil\n");
	printElement(ganjil);
	printf("Genap\n");
	printElement(genap);
	
	return 0;
}