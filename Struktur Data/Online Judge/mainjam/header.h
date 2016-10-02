#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct{
	int jam;
	int menit;
	int detik;
	int jumlah_detik;
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
int countElment(list );
int konversi(int , int , int );
void sorting(bungkusan [],int );
void addFirst(int ,int ,int ,int ,list *);
void printElement(list );