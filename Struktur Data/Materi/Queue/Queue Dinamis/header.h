#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct{
	char nim[10];
	char nama[50];
	float nilai;
}kontainer;

typedef struct elm *alamatelmt;
typedef struct elm{
	kontainer elmt;
	int prioritas;
	alamatelmt next;
}elemen;

typedef struct{
	elemen *first;
	elemen *last;
}queue;

void add(char [],char [],float ,queue *);
void del(queue *);
void printQueue(queue );
void add_prioritas(char [],char [],float ,int ,queue *);
