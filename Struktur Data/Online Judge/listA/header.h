#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct{
	int angka;
}isiB;

typedef struct{
	char kata[100];
}isiK;

typedef struct eklm *alamatekolom;
typedef struct eklm{
	isiK elmt;
	alamatekolom next;
}eKolom;

typedef struct ebr *alamatebaris;
typedef struct ebr{
	isiB elmt;
	eKolom *col;
	alamatebaris next;
}eBaris;

typedef struct{
	eBaris *first;
}list;

void createList(list *);
int countElementB(list );
int countElementK(eBaris );

//untuk kolom
void addFirstB(int ,list *);
void addAfterB(eBaris *,int );
void addLastB(int ,list *);

//untuk baris
void addFirstK(char [],eBaris *);
void addAfterK(eKolom *,char []);
void addLastK(char [],eBaris *);

//untuk baris
void delFirstB(list *);
void delAfterB(eBaris *);
void delLastB(list *);

//untuk kolom
void delFirstK(eBaris *);
void delAfterK(eKolom *);
void delLastK(eBaris *);

void printElement(list );
void delAllB(list *);
void delAllK(eBaris *);