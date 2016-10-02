#include <stdio.h>
#include <string.h>
#include <malloc.h>

char anak[100];
char ortu[100];
char temp[100][100];
int panjang[100];
int jumlah_hapus;

typedef struct smp *alamatsimpul;

typedef struct smp{
	char nama[100];
	alamatsimpul sibling;
	alamatsimpul child;
}simpul;


typedef struct{
	simpul *root;
}tree;
