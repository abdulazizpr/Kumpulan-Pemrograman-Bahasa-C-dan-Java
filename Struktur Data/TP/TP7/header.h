#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct{
	char raptor[100];
	int waktu_mulai;
	int lama_waktu;
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

void add(char [],int ,int ,queue *);
void del(queue *);
void printQueue(queue );
void add_prioritas(char [],int ,int ,int ,queue *);
