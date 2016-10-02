#include <stdio.h>
#include <string.h>

typedef struct{
	char huruf;
}kontainer;

typedef struct{
	kontainer elmt;
	int prioritas;
}elemen;

typedef struct{
	int first;
	int last;
	elemen data[3];
}queue;

void add(char ,queue *);
void del(queue *);
void printQueue(queue );
void add_prioritas(char ,int ,queue *);
