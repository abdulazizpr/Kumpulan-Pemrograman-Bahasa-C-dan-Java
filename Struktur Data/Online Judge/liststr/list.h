#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct{
	char kata[100];
}bungkusan;

typedef struct elmt *alamatelmt;
typedef struct elmt{
	bungkusan elmt;
	alamatelmt next;
}elemen;

typedef struct{
	elemen *first;
}list;

void createList(list *);
int countElment(list );
void addFirst(char [],list *);
void printElement(list );