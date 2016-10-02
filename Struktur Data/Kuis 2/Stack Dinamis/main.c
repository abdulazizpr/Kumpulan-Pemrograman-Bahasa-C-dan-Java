#include "header.h"

int main(){
	
	
	stack S;
	createEmpty(&S);
	
	int n,i;
	char operator;
	scanf("%d",&n);			//banyaknya inputan
	
	int angka;
	for(i=0;i<n;i++){
		scanf("%d",&angka);	//masukan input angka sebanyak n
		push(angka,&S);//lalu push ke stack
	}
	scanf(" %c",&operator);//input operator +/*
	
	//print dengan operator
	printStack(operator,S);
	
	return 0;
}