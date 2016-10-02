#include <stdio.h>
#include <string.h>

int n;

typedef struct{
	char nim[10];
	char nama[50];
	char nilai[2];
}nilaiMatkul;

typedef struct{
	nilaiMatkul elmt;
	int prev;
	int next;
}elemen;

typedef struct{
	int first;
	int tail;
	elemen data[100];
}list;

void createList(list *);
int countElement(list );
int emptyElement(list );
void addFirst(char [],char [],char [],list *);
void addAfter(int ,char [],char [],char [],list *);
void addLast(char [],char [],char [],list *);
void delFirst(list *);
void delAfter(int ,list *);
void delLast(list *);
void printElemen(list );
void delAll(list *);
