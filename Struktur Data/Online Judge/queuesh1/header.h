#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct{
	int waktu;
	char nama[100];
}kontainer;

typedef struct elm *alamatelmt;
typedef struct elm{
	kontainer elmt;
	alamatelmt next;
}elemen;

typedef struct{
	elemen *first;
	elemen *last;
}queue;

void add(int ,char [],queue *);
void del(queue *);
void printQueue(queue );
