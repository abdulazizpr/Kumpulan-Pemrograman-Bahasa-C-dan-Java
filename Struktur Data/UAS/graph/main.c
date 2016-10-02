#include "header.h"

int main(){
	
	//buat graph kosong
	graph G;
	createEmpty(&G);
	
	int n,i;
	scanf("%d",&n);//masukan sebanyak input yang dihapus
	
	simpul *begin;
	simpul *end;
	
	char kota_awal,kota_akhir,hapus_kota;//deklarasi kota awal, akhir, dan kota yang akan dihapus
	
	for(i=0;i<n;i++){
		scanf(" %c %c",&kota_awal,&kota_akhir);//masukan kota awal dan akhir
		
		begin = findSimpul(kota_awal,G);//cari awal mula kota
		end = findSimpul(kota_akhir,G);//cari akhir kota
		
		if(begin == NULL && end==NULL){//jika tidak ada awal dan akhir
			addSimpul(kota_awal,&G);//maka tambahkan simpul awal
			addSimpul(kota_akhir,&G);//tambahkan simpul akhir
			
			//lalu cari lagi
			begin = findSimpul(kota_awal,G);
			end = findSimpul(kota_akhir,G);
			
			addJalur(end,&begin);//lalu tambahkan jalur
		}else if(begin != NULL && end==NULL){//jika awalnya ada dan akhirnya tidak ada
			addSimpul(kota_akhir,&G);//maka tambahkan simpul akhirnya
			end = findSimpul(kota_akhir,G);//lalu cari akhir
			
			addJalur(end,&begin);//lalu tambahkan jalur
		}else{		//jika ada semua
			addJalur(end,&begin);//maka tinggal tambah jalur
		}
		
	}
	
	scanf(" %c",&hapus_kota);//lalu hapus kota yang diinginkan
	
	delSimpul(hapus_kota,&G);//kemudian hapus kota tersebut
	
	printGraph(G);//lalu print berapa jumlah simpul dan jalur yang tersedia

	
	return 0;
}