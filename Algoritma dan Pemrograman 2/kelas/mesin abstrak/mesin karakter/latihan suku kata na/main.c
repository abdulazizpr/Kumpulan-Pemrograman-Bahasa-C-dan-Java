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
	scanf("%49[^\n]s", &pita);
	int jumlah=0;
	
	START(pita);	
	char now, next;
	now = GETCC();
	INC(pita);
	next = GETCC();
	while(EOP(pita) == 0){
		
		if(now == 'n' && next=='a'){
			if(next!=' ' && next!='.')
			jumlah++;
		}
		
		now = next;
		
		INC(pita);
		next = GETCC();
	}
	
	printf("%d\n",jumlah);
	
	return 0;
}