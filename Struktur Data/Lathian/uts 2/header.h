#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct{
	char huruf;
}eBesar;

typedef struct{
	int angka;
}eKecil;

typedef struct eklm *alamatekolom;
typedef struct eklm{
	eKecil elmt;
	alamatekolom next;
}eKolom;

typedef struct ebr *alamatebaris;
typedef struct ebr{
	eBesar elmt;
	eKolom *col;
	alamatebaris next;
}eBaris;

typedef struct{
	eBaris *first;
}list;

void createList(list *);
int countElementB(list );
int countElementK(eBaris );
void addFirstB(char ,list *);
void addFirstK(int ,eBaris *);
void addAfterB(eBaris *,char );
void addAfterK(eKolom *,int );
void addLastB(char ,list *);
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