#include "header.h"

int main(){
	
	list L;
	createList(&L);
	
	data laki2;
	data perempuan;
	
	scanf("%s",&laki2.nama_depan);
	scanf("%s",&laki2.nama_belakang);
	addLast(laki2.nama_depan,laki2.nama_belakang,&L);
	
	scanf("%s",&perempuan.nama_depan);
	scanf("%s",&perempuan.nama_belakang);
	addLast(perempuan.nama_depan,perempuan.nama_belakang,&L);
	
	printElement(L);
	
	return 0;
}