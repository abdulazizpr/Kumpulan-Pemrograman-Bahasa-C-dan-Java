#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct{
	char kata[100];
	int jumlah_a;
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
void addFirst(char [],list *);
void addAfter(elemen *,char [],list *);
void addLast(char [],list *);
void delFirst(list *);
void delAfter(elemen *,list *);
void delLast(list *);
void printElement(list );
void delAll(list *);