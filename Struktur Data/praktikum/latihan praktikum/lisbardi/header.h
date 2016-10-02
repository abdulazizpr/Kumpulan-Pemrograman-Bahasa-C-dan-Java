#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct{
	char barang[10];
	int stok;
}data;

typedef struct elmt *alamatelmt;
typedef struct elmt{
	data elmt;
	alamatelmt next;
}elemen;

typedef struct{
	elemen *first;
}list;

void createList(list *);
void addFirst(char [],int ,list *);
void addAfter(elemen *,char [],int ,list *);
void addLast(char [],int ,list *);
void delFirst(list *);
void delAfter(elemen *,list *);
void delLast(list *);
void printElemen(list );
void delAll(list *);