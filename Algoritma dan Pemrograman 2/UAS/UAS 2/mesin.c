#include "header.h"

//dimulai dari indeks ke-0 pita
void start(char pita[]){
	indeks = 0;
	panjangkata = 0;
	
	while(pita[indeks] == ' '){
		indeks++;
	}
	
	while(pita[indeks] != ' ' && pita[indeks] != '.'){
		ckata[panjangkata] = pita[indeks];
		indeks++;
		panjangkata++;
	}
	ckata[panjangkata] = '\0';
}

//maju satu kata
void inc(char pita[]){
	//panjang kata dimulai dari 0
	panjangkata = 0;
	while(pita[indeks] == ' '){
		indeks++;
	}
	while(pita[indeks] != ' ' && pita[indeks] != '.'){
		ckata[panjangkata] = pita[indeks];
		indeks++;
		panjangkata++;
	}
	ckata[panjangkata] = '\0';
}

//mengambil satu kata
char* getkata(){
	return ckata;
	//mengembalikan kata yang telah ditampung sebelumnya
}

//eop jika bertem titik
int eop(char pita[]){
	if(pita[indeks] == '.'){
		return 1;
	}else{
		return 0;
	}
}

//laluu di cek apakah ada underscore diantara 2 kata
void cekunderscore(char pita[]){

	int i=0;									//inisialisasi
	while(i < panjangkata){						//berhenti jika i lebih kecil dari panjangkata
		if(ckata[i]=='_' && ckata[i+1]=='_'){	//jika huruf di kata underscore minimal 2 buah
			underscore++;						//maka underscore terus bertambah
			i = i + panjangkata;				//dan i akan bertambah sebanyak panjangkata
		}else{									//jika tidak
			i++; 								//maka terus mencari sampai ketemu
		}		
	
	}
}