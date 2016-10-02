#include <stdio.h>
#include <string.h>

typedef struct{
	char nim[10];
	char nama[50];
	float nilai;
	
}kontainer;

typedef struct{
	kontainer elmt;
	int prioritas;
}elemen;

typedef struct{
	int first;
	int last;
	elemen data[10];
}queue;

void add(char [],char [],float ,queue *);
void del(queue *);
void printQueue(queue );
void add_prioritas(char [],char [],float ,int ,queue *);
