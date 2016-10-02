#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct{
	char nim[10];
	char nama[50];
	char nilai[2];
}nilaiMatkul;

typedef struct elmt *alamatelmt;
typedef struct elmt{
	nilaiMatkul elmt;
	alamatelmt next;
}elemen;

typedef struct{
	elemen *first;
}list;

void createList(list *);
void addFirst(char [],char [],char [],list *);
void addAfter(elemen *,char [],char [],char [],list *);
void addLast(char [],char [],char [],list *);
void delFirst(list *);
void delAfter(elemen *,list *);
void delLast(list *);
void printElemen(list );
void delAll(list *);