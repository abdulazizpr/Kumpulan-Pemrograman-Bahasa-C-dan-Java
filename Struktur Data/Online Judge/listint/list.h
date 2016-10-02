#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct{
	int angka;
}nilai;

typedef struct elmt *alamatelmt;
typedef struct elmt{
	nilai elmt;
	alamatelmt next;
}elemen;

typedef struct{
	elemen *first;
}list;

void createList(list *);
int countElment(list );
void addFirst(int ,list *);
void printElement(list );