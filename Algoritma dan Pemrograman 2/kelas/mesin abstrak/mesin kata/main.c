#include <stdio.h>
#include <string.h>

int indeks;
char cc;

void START(char pita[]){
	indeks = 0;
	cc = pita[indeks];
}

void INC(char pita[]){
	indeks++;
	cc = pita[indeks];
}

void ADV(char pita[]){
	indeks++;
	cc = pita[indeks];
	while((cc == ' ') && (EOP() == 0)){
		indeks++;
		cc = pita[indeks];
	}
}

char GETCC(){
	return cc;
}

int EOP(){
	if(cc == '.'){
		return 1;
	}else{
		return 0;
	}
}

int main(){
	char pita[50];
	printf("masukkan pada kalimat pada pita\n");
	scanf("%49[^\n]s", &pita);

	START(pita);
	printf("%c\n", GETCC());
	while(EOP() == 0){
		INC(pita);
		printf("%c\n", GETCC());
	}
return 0;
}
