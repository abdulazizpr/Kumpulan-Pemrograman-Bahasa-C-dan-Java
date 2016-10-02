#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct{
	char kode_barang[10];
	char jenis_barang[50];
	int jumlah;
}data;

typedef struct elmt *alamatelmt;
typedef struct elmt{
	data elmt;
	alamatelmt next;
}elemen;

typedef struct{
	elemen *first;
}list;

void createList(list *);
void addFirst(char [],char [],int ,list *);
void addAfter(elemen *,char [],char [],int ,list *);
void addLast(char [],char [],int ,list *);
void delFirst(list *);
void delAfter(elemen *,list *);
void delLast(list *);
void printElemen(list );
void delAll(list *);