#include "header.h"

//memulai karakter
void START(char pita[]){
	indeks = 0;
	cc = pita[indeks];
}

//maju satu karakter
void INC(char pita[]){
	indeks++;
	cc = pita[indeks];
}

//maju satu karakter lewati spasi dan titik
void ADV(char pita[]){
	indeks++;
	cc = pita[indeks];
	while((cc == ' ') && (EOP() == 0)){
		indeks++;
		cc = pita[indeks];
	}
}

//mengambil satu karakter
char GETCC(){
	return cc;
}

//proses eop jika ada titik
int EOP(){
	if(cc == '.'){
		return 1;
	}else{
		return 0;
	}
}


//mengecek apakah ada 2 spasi diantara karakter selain titik dan spasi
void cek(char pita[]){
	
	//jika karakter sekarang dan karakter selanjutnya itu ada spasi(berarti 2 spasi)
	if(now==' ' && next1==' '){
		if(prev!=' '&& next2!='.' && next2!=' '){//jika sebelum dan selanjutnya(lagi) tidak ada spasi dan titik
			spasi++;//maka spasi bertambah
		}
	}
	prev = now;					//karakter sebelumnya adalah karakter sekarang
	now  = next1;				//karakter sekarang merupakan karakter selanjutnya
	next1 = next2;				//karakter selanjutnya merupakan karakter selanjutnya lagi
	INC(pita);					//lalu maju satu karakter
	next2 = GETCC();			//lalu ambil karakter selanjutnya lagi
	
}