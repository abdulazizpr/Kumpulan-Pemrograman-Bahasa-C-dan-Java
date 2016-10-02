#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct smp *alamatsimpul;
typedef struct jlr *alamatjalur;

typedef struct smp{
	char info[100];
	alamatsimpul next;
	alamatjalur arc;
}simpul;

typedef struct jlr{
	int info;
	alamatjalur next;
	simpul *node;
}jalur;

typedef struct{
	simpul *first;
}graph;

void createEmpty(graph *);
void addSimpul(char [],graph *);
void addJalur(simpul *,int , simpul **);
void delSimpul(char [],graph *);
simpul *findSimpul(char [],graph );
void delJalur(char [],simpul **);
void printGraph(graph );