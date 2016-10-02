#include "header.h"

/*
Saya Abdul Aziz Priatna tidak melakukan kecurangan seperti yang telah dispesifikasikan pada mata kuliah Struktur Data dalam mengerjakan kuis 1, jika saya melakukan kecurangan maka Allah/Tuhan adalah saksi saya, dan saya bersedia menerima hukumanNya. Aamiin.
*/

int main(){
	
	n = 50;
	
	int m;
	scanf("%d",&m);
	
	list L;
	createList(&L);
	
	int i,pembagi;
	nilai angka;
	for(i=0;i<m;i++){
		scanf("%d %d",&angka.pembilang,&angka.penyebut);
		addLast(angka.pembilang,angka.penyebut,&L);
	}
	
	scanf("%d",&pembagi);
	
	cek(pembagi,&L);
	
	printElemen(L);
	
	
	return 0;
}