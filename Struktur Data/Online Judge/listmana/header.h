#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct{
	char huruf;
}dataB;

typedef struct{
	char kata[100];
}dataK;

typedef struct eklm *alamatekolom;
typedef struct eklm{
	dataK elmt;
	alamatekolom next;
}eKolom;

typedef struct ebr *alamatebaris;
typedef struct ebr{
	dataB elmt;
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
void addFirstK(char [],eBaris *);
void addAfterB(eBaris *,char );
void addAfterK(eKolom *,char []);
void addLastB(char ,list *);
void addLastK(char [],eBaris *);
void delFirstB(list *);
void delFirstK(eBaris *);
void delAfterB(eBaris *);
void delAfterK(eKolom *);
void delLastB(list *L);
void delLastK(eBaris *);
void printElement(list L);
void delAllB(list *);
void delAllK(eBaris *);
eBaris *searchB(char ,list );