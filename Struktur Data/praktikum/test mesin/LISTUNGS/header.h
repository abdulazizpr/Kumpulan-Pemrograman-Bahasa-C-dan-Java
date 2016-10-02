#include <stdio.h>
#include <string.h>

int n;

typedef struct{
	char nama[50];
	char nim[10];
	char gender[2];
}data;

typedef struct{
	data elmt;
	int next;
}elemen;

typedef struct{
	int first;
	elemen data[100];
}list;

void createList(list *);
int countElement(list );
int emptyElement(list );
void addFirst(char [],char [],char [],list *);
void addAfter(int ,char [],char [],char [],list *);
void addLast(char [],char [],char [],list *);
void delFirst(list *);
void delAfter(int ,list *);
void delLast(list *);
void printElemen(list );
void delAll(list *);