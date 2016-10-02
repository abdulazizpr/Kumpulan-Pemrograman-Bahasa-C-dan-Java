#include <stdio.h>
#include <string.h>

int indeks;	//gaboleh dipake di main
int panjangkata;
char ckata[50];


void STARTKATA(char pita[]){

	indeks = 0;
	panjangkata = 0;
	
	while(pita[indeks] == ' ') indeks++;	//ketemu spasi dilewat
	
	while((pita[indeks] != ' ') && (pita[indeks] != '.'))
	{
		ckata[panjangkata] = pita[indeks];
		indeks++;
		panjangkata++;
	}
	ckata[panjangkata] = '\0';

}

void RESETKATA(){

	panjangkata = 0 ;
	ckata[panjangkata] = '\0';
	
}

void INCKATA(char pita[]){

	panjangkata = 0;
	
	while(pita[indeks] == ' ') indeks++;	//ketemu spasi dilewat

	while((pita[indeks] != ' ') && (pita[indeks] != '.'))
	{
		ckata[panjangkata] = pita[indeks];
		indeks++;
		panjangkata++;
	}
	ckata[panjangkata] = '\0';
	
}

char* GETCKATA(){
	return ckata;
}

int GETPANJANGKATA(){
	return panjangkata;
}

int EOPKATA(char pita[]){
	
	if(pita[indeks] == '.')	return 1;
	else return 0;
	
}

//menghitung banyak kata dalam pita
int main(){

	char pita[300], hasil[100][100];
	int status=0, i,j;
	int lebar;
	int banyakkata[100];
	
	scanf("%299[^\n]s", &pita);
	scanf("%d",&lebar);
	
	STARTKATA(pita);
	while(EOPKATA(pita) == 0)
	{
		for(i=0;i<GETPANJANGKATA();i++){
			if(ckata[i]=='a')
			{
				strcpy(hasil[status],GETCKATA());
			}
		}
		status++;
		INCKATA(pita);
	}
	
	int jumlah=0;
	
	for(i=0;i<status-1;i++){
		banyakkata[i]=strlen(hasil[i]);
		jumlah=(jumlah+banyakkata[i]);
	}
	
	for(j=0;j<lebar-jumlah-1;j++){
		printf("-");
	}
	//printf("%d\n",jumlah);
	for(i=0;i<status-2;i++){
		printf("%s",hasil[i]);
		if(i<status-3){
			printf("-");
		}
	}
	printf("\n"); 
	
	for(j=0;j<lebar-strlen(hasil[status-2]);j++){
		printf("-");
	}
	printf("%s",hasil[status-2]);
	printf("\n"); 
	
return 0;
}