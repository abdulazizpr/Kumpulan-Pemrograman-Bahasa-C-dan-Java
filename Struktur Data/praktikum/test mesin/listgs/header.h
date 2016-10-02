#include <stdio.h>
#include <string.h>

int n;

typedef struct{
	int angka;
	char kata[50];
}data;

typedef struct{
	data elmt;
	int prev;
	int next;
}elemen;

typedef struct{
	int first;
	int tail;
	elemen data[100];
}list;

void createList(list *);
int countElement(list );
int emptyElement(list );
void addFirst(int ,char [],list *);
void addAfter(int ,int ,char [],list *);
void addLast(int ,char [],list *);
void delFirst(list *);
void delAfter(int ,list *);
void delLast(list *);
void printElemen(list );
void delAll(list *);
