#include <stdio.h>
#include <string.h>
#include <malloc.h>

//int total_jarak;

typedef struct{
	char kota[10];
	int jarak;
}data;

typedef struct elmt *alamatelmt;
typedef struct elmt{
	data elmt;
	alamatelmt next;
	alamatelmt prev;
}elemen;

typedef struct{
	elemen *first;
	elemen *tail;
}list;

//prosedur operasi list
void createList(list *);
void addFirst(char [],int ,list *);
void addAfter(elemen *,char [],int ,list *);
void addLast(char [],int ,list *);
void delFirst(list *);
void delAfter(elemen *,list *);
void delLast(list *);
void printElemen(list );
void delAll(list *);

//operasi perintah
void operasi_add(char [],char [],int ,list *);
void operasi_del(char [],list *);
elemen *cari(char [],list *);
int operasi_count(char [],char [],list *);