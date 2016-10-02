#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct{
	int angka;
}kelompok;

typedef struct{
	int angka;
}komponen;

typedef struct eklm *alamatekolom;
typedef struct eklm{
	komponen elmt;
	alamatekolom next;
}eKolom;

typedef struct ebr *alamatebaris;
typedef struct ebr{
	kelompok elmt;
	eKolom *col;
	alamatebaris next;
}eBaris;

typedef struct{
	eBaris *first;
}list;