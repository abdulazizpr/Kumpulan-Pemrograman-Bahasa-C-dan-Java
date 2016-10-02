#include "header.h"

/*
Saya Abdul Aziz Priatna tidak melakukan kecurangan seperti yang telah dispesifikasikan
pada mata kuliah Strurktur Data dalam mengerjakan TP3, jika saya melakukan kecurangan
maka Allah/Tuhan adalah saksi saya, dan saya bersedia menerima hukumanNya. Aamiin.
*/

int main(){
	
	banyak = 100;	
	list L1,L2;
	createList(&L1);	//buat list 1
	createList(&L2);	//buat list 2
	
	int n,m,i;
	scanf("%d",&n);		//banyaknya inputan untuk list
	
	char tempat_awal[50];
	data tempat_mancing;
	for(i=0;i<n;i++){
		scanf("%s %d",&tempat_mancing.tempat,&tempat_mancing.berat_ikan);
		addLast(tempat_mancing.tempat,tempat_mancing.berat_ikan,&L1);//masukan secara addlast
	}
	
	scanf("%d",&m);
	scanf("%s",&tempat_awal);
	addLast(tempat_awal,0,&L2);//masukan secara addLast juga
	
	data kunjungan;
	for(i=0;i<m;i++){
		scanf("%s",kunjungan.tempat);
		addLast(kunjungan.tempat,0,&L2);//masukan secara addLast juga
	}
	
	hasiljalan2(L1,L2);	//coba jalan2 yuk ke mesin :D
	
	
	return 0;
}