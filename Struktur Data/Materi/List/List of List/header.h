#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct{
	char nim[10];
	char nama[50];
}mahasiswa;

typedef struct{
	char kode[10];
	char nilai[2];
}matKul;

typedef struct eklm *alamatekolom;
typedef struct eklm{
	matKul elmt;
	alamatekolom next;
}eKolom;

typedef struct ebr *alamatebaris;
typedef struct ebr{
	mahasiswa elmt;
	eKolom *col;
	alamatebaris next;
}eBaris;

typedef struct{
	eBaris *first;
}list;

void createList(list *);
int countElementB(list );
int countElementK(eBaris );
void addFirstB(char [],char [],list *);
void addFirstK(char [],char [],eBaris *);
void addAfterB(eBaris *,char [],char []);
void addAfterK(eKolom *,char [],char []);
void addLastB(char [],char [],list *);
void addLastK(char [],char [],eBaris *);
void delFirstB(list *);
void delFirstK(eBaris *);
void delAfterB(eBaris *);
void delAfterK(eKolom *);
void delLastB(list *L);
void delLastK(eBaris *);
void printElement(list L);
void delAllB(list *);
void delAllK(eBaris *);