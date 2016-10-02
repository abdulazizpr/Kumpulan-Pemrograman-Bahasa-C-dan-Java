#include "header.h"

/*
Saya Abdul Aziz Priatna(1307123) tidak melakukan kecurangan seperti yang telah dispesifikasikan pada 
mata kuliah Algoritma dan Pemograman 2 dalam mengerjakan UAS, jika saya melakukan kecurangan
maka Allah/Tuhan adalah saksi saya, dan saya bersedia menerima hukumanNya. Aamiin.
*/

int main(){
	
	//masukan pita
	char pita[666];
	scanf("%667[^\n]s", &pita);
	
	//mulai ambil huruf
	START(pita);
	prev=' ';				//inisialisasi previus
	now = GETCC();			//mengambil huruf yang sekarang
	
	INC(pita);				//maju satu huruf
	next1 = GETCC();		//mengambil huruf selanjutnya di next1
	
	INC(pita);				//maju satu huruf lagi
	next2 = GETCC();		//mengambil huruf selanjutnya di next2
	
	spasi = 0;				//inisialisasi hitung spasi
	
	//proses akan berhenti jika eop
	while(EOP() == 0){
		cek(pita);			//mengecek apakah ada 2 spasi diantara 2 huruf
	}
	
	printf("%d\n",spasi);	//jumlah spasi
	
	return 0;
}