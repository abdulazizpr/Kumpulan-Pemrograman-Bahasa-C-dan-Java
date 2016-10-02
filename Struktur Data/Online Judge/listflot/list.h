#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct{
	float angka;
}desimal;

typedef struct elmt *alamatelmt;
typedef struct elmt{
	desimal elmt;
	alamatelmt next;
}elemen;

typedef struct{
	elemen *first;
}list;

void createList(list *);
int countElment(list );
void addFirst(float ,list *);
void printElement(list );