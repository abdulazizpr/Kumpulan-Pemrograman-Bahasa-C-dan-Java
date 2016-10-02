#include "header.h"

int main(){
	
	
	stack S;
	createEmpty(&S);
	
	char kode[100],namab[100];
	int n,i;
	scanf("%d",&n);//banyaknya data yang di input
	char cek_kode[3];
	
	for(i=0;i<n;i++){
		scanf("%s %s",&kode,&namab);//masukan kode dan namab
		push(kode,namab,&S);//lalu masukan kode dan namab ke dalam stack
	}
	scanf("%s",&cek_kode);//lalu input cek kode
	
	printStack(cek_kode,S);//lalu print
	
	return 0;
}