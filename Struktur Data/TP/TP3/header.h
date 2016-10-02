#include <stdio.h>
#include <string.h>

int banyak;			//variabel global untuk banyaknya list

//kontainer
typedef struct{
	char tempat[50];
	int berat_ikan;
}data;

//elemen
typedef struct{
	data elmt;
	int prev;
	int next;
}elemen;

//list
typedef struct{
	int first;
	int tail;
	elemen data[100];
}list;

//library prosedur
void createList(list *);
int countElement(list );
int emptyElement(list );
void addFirst(char [],int ,list *);
void addAfter(int ,char [],int ,list *);
void addLast(char [],int ,list *);
void delFirst(list *);
void delAfter(int ,list *);
void delLast(list *);
void printElemen(list );
void delAll(list *);
void hasiljalan2(list ,list );
