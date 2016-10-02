#include "header.h"

int main(){
	
	list L;
	createList(&L);	
	
	int n,m,i;
	scanf("%d",&n);//banyaknya inputan peserta
	
	char nama_nopeserta[100];
	for(i=0;i<n;i++){
		scanf("%s",&nama_nopeserta);//input peserta
		addLastB(nama_nopeserta,&L);//masukan kedalam list besar
	}
	
	char perintah[100];
	data peserta;
	
	scanf("%d",&m);//banyaknya inputan perintah
	
	for(i=0;i<m;i++){
		scanf("%s",&perintah);
		
		if(strcmp(perintah,"INSERT")==0){//jika perintahnya insert
			scanf("%s",&nama_nopeserta);
			scanf("%s",&peserta.penilaian);
			scanf("%d",&peserta.nilai);
			
			eBaris *cari = cariB(nama_nopeserta,L);//cari baris untuk diisi
			
			eKolom *cari2 = cariK(peserta.penilaian,*cari);//cari kolom jika sudah ada isi
			if(cari2==NULL){//jika tidak ada
				if(strcmp(peserta.penilaian,"UXD")==0){//jika inputannya UXD
					addFirstK(peserta.penilaian,peserta.nilai,cari);//maka prioritaskan di kolom pertama
				}else if(strcmp(peserta.penilaian,"CODE")==0){//jika inputannya CODE
					if(cari->col==NULL) addFirstK(peserta.penilaian,peserta.nilai,cari);//jika kolomnya null maka prioritaskan di pertama
					else addAfterK(cari->col,peserta.penilaian,peserta.nilai);//jika tidak tempatkan di kedua
				}else if(strcmp(peserta.penilaian,"PRES")==0){//jika inputannya PRES
					addLastK(peserta.penilaian,peserta.nilai,cari);//maka tempatkan di akhir
				}
			}//masukan ke dalam list kecil sesuai baris
			
		}else if(strcmp(perintah,"UPDATE")==0){//jika perintahnya update
			scanf("%s",&nama_nopeserta);
			scanf("%s",&peserta.penilaian);
			scanf("%d",&peserta.nilai);
			
			update(nama_nopeserta,peserta.penilaian,peserta.nilai,&L);//lakukan proses update
		}else if(strcmp(perintah,"DELETE")==0){//jika perintahnya delete
			scanf("%s",&nama_nopeserta);
			scanf("%s",&peserta.penilaian);
			delete(nama_nopeserta,peserta.penilaian,&L);//lakukan proses delete
		}
		
	}
	
	//hapus jika ada data yang tidak lengkap agar bisa di sorting
	hapustidaklengkap(&L);
	
	//jika data tiap baris memiliki 3 kolom
	if(countElementB(L)==hitungkolom(L)){
		sort(&L);//maka urutkan berdasarkan nilai yang ada
	}
	
	printElement(L);//tampilkan isi elemen
	
	return 0;
} 