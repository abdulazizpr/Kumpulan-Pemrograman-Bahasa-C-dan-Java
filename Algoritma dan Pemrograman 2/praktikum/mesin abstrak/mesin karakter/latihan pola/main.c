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
	int i;
	int spasi=0;
	int jumlahspasi=0;
	int status=0;
	
	START(pita);
	printf("%c\n", GETCC());
	spasi++;
	while(EOP() == 0){
		if(GETCC()==' '){
			if(status == 1){
				printf("\n");
				spasi--;
			}
			jumlahspasi++;
			status=0;
		}
		
		INC(pita);
		
		if(jumlahspasi % 2 == 0){
			if(GETCC() != ' '){
				for(i=0 ; i<spasi ;i++){
					printf(" ");
				}
				spasi++;
				printf("%c\n",GETCC());
			}
		}else{
			spasi++;
			while(status==0){
				for(i=0 ; i<spasi-1 ; i++){
					printf(" ");
				}
				status = 1;
			}
			if(GETCC() != ' '){
				printf("%c", GETCC());
			}
		}
	}
	
	return 0;
}