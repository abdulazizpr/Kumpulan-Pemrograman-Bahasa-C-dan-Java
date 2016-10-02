#include <stdio.h>
#include <string.h>

int n;

typedef struct{
	char kode_brg[5];
	char nama_brg[100];
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
void addFirst(char [],char [],list *);
void addAfter(int ,char [],char [], list *);
void addLast(char [],char [],list *);
void delFirst(list *);
void delAfter(int ,list *);
void delLast(list *);
void sorting(data [],int );
void printElemen(list );
void delAll(list *);