#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct{
	double koma;
	int blk_koma;
}bungkusan;

typedef struct elmt *alamatelmt;
typedef struct elmt{
	bungkusan elmt;
	alamatelmt next;
}elemen;

typedef struct{
	elemen *first;
}list;

void createList(list *);
int hasil_blk(double );
void addFirst(double ,int ,list *);
void sorting(bungkusan [],int );
void printElement(list );