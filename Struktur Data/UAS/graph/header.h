#include <stdio.h>
#include <string.h>
#include <malloc.h>

/*
Saya Abdul Aziz Priatna tidak melakukan kecurangan seperti yang telah dispesifikasikan
pada mata kuliah Strurktur Data dalam mengerjakan UAS, jika saya melakukan kecurangan
maka Allah/Tuhan adalah saksi saya, dan saya bersedia menerima hukumanNya. Aamiin.
*/

typedef struct smp *alamatsimpul;
typedef struct jlr *alamatjalur;

//bungkusan simpul
typedef struct smp{
	char info;
	alamatsimpul next;
	alamatjalur arc;
}simpul;


//bungkusan jalur
typedef struct jlr{
	alamatjalur next;
	simpul *node;
}jalur;

//bungkusan graph
typedef struct{
	simpul *first;
}graph;

//operasi graph
void createEmpty(graph *);
void addSimpul(char ,graph *);
void addJalur(simpul *, simpul **);
void delSimpul(char ,graph *);
simpul *findSimpul(char ,graph );
void delJalur(char ,simpul **);
void printGraph(graph );