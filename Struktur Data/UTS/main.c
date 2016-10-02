#include "header.h"

/*
Saya Abdul Aziz Priatna tidak melakukan kecurangan seperti yang telah dispesifikasikan pada mata kuliah Struktur Data dalam mengerjakan UTS, jika saya melakukan kecurangan maka Allah/Tuhan adalah saksi saya, dan saya bersedia menerima hukumanNya. Aamiin.
*/

int main(){
	
	list L;
	createList(&L);
	
	int n,i;
	scanf("%d",&n);//banyaknya inputan
	
	int pembilang,penyebut;
	for(i=0;i<n;i++){
		scanf("%d %d",&pembilang,&penyebut);//input pembilang dan penyebut
		
		eBaris *maju = cari(penyebut,L);//untuk cari baris yang masih kosong
		
		if(maju==NULL){//jika tidak ada
			addLastB(penyebut,&L);//masukan secara addLastB
		}
		//dicek lagi untuk diisi ke kolom
		eBaris *utkkolom = cari(penyebut,L);
		addLastK(pembilang,utkkolom);//masukan secara addLastK sesuai baris yang ditemukan
				
	}
	
	printElement(L);
	
	return 0;
}