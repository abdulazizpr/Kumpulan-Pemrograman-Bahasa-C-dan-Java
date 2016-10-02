#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct{
	int angka;
}angkaKecil;

typedef struct{
	int angka;
}angkaBesar;

typedef struct eklm *alamatekolom;
typedef struct eklm{
	angkaBesar elmt;
	alamatekolom next;
}eKolom;

typedef struct ebr *alamatebaris;
typedef struct ebr{
	angkaKecil elmt;
	eKolom *col;
	alamatebaris next;
}eBaris;

typedef struct{
	eBaris *first;
}list;

void createList(list *);
int countElementB(list );
int countElementK(eBaris );
void addFirstB(int ,list *);
void addFirstK(int ,eBaris *);
void addAfterB(eBaris *,int );
void addAfterK(eKolom *,int );
void addLastB(int ,list *);
void addLastK(int ,eBaris *);
void delFirstB(list *);
void delFirstK(eBaris *);
void delAfterB(eBaris *);
void delAfterK(eKolom *);
void delLastB(list *L);
void delLastK(eBaris *);
void printElement(list L);
void delAllB(list *);
void delAllK(eBaris *);