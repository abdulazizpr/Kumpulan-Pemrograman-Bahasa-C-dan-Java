#include "header.h"

int main(){
	
	
	stack S;
	createEmpty(&S);
	printStack(S);
	
	printf("=====================\n");
	push("13507701","Nana",64.75,&S);
	push("13507702","Rudi",75.11,&S);
	push("13507703","Dea",84.63,&S);
	printStack(S);
	
/* 	printf("=====================\n");
	printf("data yang keluar diambil\n");
	nilaiMatkul data;
	data=pop_isi(&S);
	
	printf("%s\n",data.nim);
	printf("%s\n",data.nama);
	printf("%f\n",data.nilai); */
	//pop(&S);
	//pop(&S);
	//printStack(S);
	printf("=====================\n");//balik stack
	printf("-------Balik-------\n");
	stack S2;
	createEmpty(&S2);
	pindahinstack(&S,&S2);
	printStack(S2);
	
	
	
	
	printf("=====================\n");
	
	return 0;
}