#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct{
	char nama_depan[10];
	char nama_belakang[10];
}data;

typedef struct elmt *alamatelmt;
typedef struct elmt{
	data elmt;
	alamatelmt next;
	alamatelmt prev;
}elemen;

typedef struct{
	elemen *first;
	elemen *tail;
}list;

void createList(list *);
void addFirst(char [],char [],list *);
void addAfter(elemen *,char [],char [],list *);
void addLast(char [],char [],list *);
void delFirst(list *);
void delAfter(elemen *,list *);
void delLast(list *);
void printElemen(list );
void delAll(list *);