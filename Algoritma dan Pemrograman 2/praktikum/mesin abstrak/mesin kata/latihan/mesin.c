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

char* getkata(){
	return ckata;
	//mengembalikan kata yang telah ditampung sebelumnya
}

int eop(char pita[]){
	if(pita[indeks] == '.'){
		return 1;
	}else{
		return 0;
	}
}