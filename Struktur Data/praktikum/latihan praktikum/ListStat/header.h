#include <stdio.h>
#include <string.h>

int n;

typedef struct{
	int harga;
	char nama[100];
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
void addFirst(int ,char [],list *);
void addAfter(int ,int ,char [], list *);
void addLast(int ,char [],list *);
void delFirst(list *);
void delAfter(int ,list *);
void delLast(list *);
void sorting(data [],int );
void printElemen(list ,int );
void delAll(list *);