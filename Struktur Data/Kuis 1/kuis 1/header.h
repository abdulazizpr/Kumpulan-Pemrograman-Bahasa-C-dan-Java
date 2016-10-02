#include <stdio.h>
#include <string.h>

int n;

int tampung1[100];
int tampung2[100];
int tampung3[100];
int tampung4[100];
int jumlah1;
int jumlah2;

typedef struct{
	int pembilang;
	int penyebut;
}nilai;

typedef struct{
	nilai elmt;
	int next;
}elemen;

typedef struct{
	int first;
	elemen data[100];
}list;

void createList(list *);
int countElement(list );
int emptyElement(list );
void addFirst(int ,int ,list *);
void addAfter(int ,int ,int ,list *);
void addLast(int ,int ,list *);
void delFirst(list *);
void delAfter(int ,list *);
void delLast(list *);
void printElemen(list );
void delAll(list *);
