#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct{
	char huruf;
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

void add(char ,queue *);
void del(queue *);
void printQueue(queue );
void add_prioritas(char ,int ,queue *);
