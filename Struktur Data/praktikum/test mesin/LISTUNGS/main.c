#include "header.h"


int main(){
	
	n = 4;
	
	list L;
	
	createList(&L);
	
	char nama1[50],nama2[50],nama3[10],nama4[10];
	char nim1[10],nim2[10],nim3[10],nim4[10];
	char gender1[2], gender2[2], gender3[2],gender4[2];
	
	scanf("%s %s %s",nama1,nim1,gender1);//addLast
	scanf("%s %s %s",nama2,nim2,gender2);//addFirst
	scanf("%s %s %s",nama3,nim3,gender3);//addAfter, L.head
	scanf("%s %s %s",nama4,nim4,gender4);//addLast
	
	addLast(nama1,nim1,gender1,&L);
	addFirst(nama2,nim2,gender2,&L);
	addAfter(L.first,nama3,nim3,gender3,&L);
	printElemen(L);
	
	printf("-----\n");
	
	delLast(&L);
	printElemen(L);
	
	printf("-----\n");
	
	addLast(nama4,nim4,gender4,&L);
	printElemen(L);
	
	printf("-----\n");
	
	delAfter(L.first,&L);
	delLast(&L);
	printElemen(L);
	
	printf("-----\n");
	
	delFirst(&L);
	printElemen(L);
	
	printf("-----\n");	
	
	
	return 0;
}