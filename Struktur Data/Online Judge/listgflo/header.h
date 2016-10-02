#include <stdio.h>
#include <string.h>

int n;

typedef struct{
	float angka;
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
void addFirst(float ,list *);
void addAfter(int ,float ,list *);
void addLast(float ,list *);
void delFirst(list *);
void delAfter(int ,list *);
void delLast(list *);
void printElemen(list );
void delAll(list *);
