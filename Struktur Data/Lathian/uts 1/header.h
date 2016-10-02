#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct{
	int angka_besar;
}e_besar;

typedef struct{
	int angka_kecil;
}e_kecil;

typedef struct eklm *alamatekolom;
typedef struct eklm{
	e_kecil elmt;
	alamatekolom next;
}eKolom;

typedef struct ebr *alamatebaris;
typedef struct ebr{
	e_besar elmt;
	eKolom *col;
	alamatebaris next;
}eBaris;

typedef struct{
	eBaris *first;
}list;

