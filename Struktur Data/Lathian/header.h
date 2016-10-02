#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct{
	int angka;
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
void addFirst(int ,list *);
void addAfter(elemen *,int ,list *);
void addLast(int ,list *);
void delFirst(list *);
void delAfter(elemen *,list *);
void delLast(list *);
void printElemen(list );
void delAll(list *);