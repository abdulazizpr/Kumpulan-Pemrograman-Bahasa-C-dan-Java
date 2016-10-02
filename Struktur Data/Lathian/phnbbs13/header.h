#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct{
	char nama[100];
	char info;
}kontainer;

typedef struct smp *alamatsimpul;
typedef struct smp{
	kontainer data;
	alamatsimpul left;
	alamatsimpul right;
}simpul;

typedef struct{
	simpul *root;
}tree;

void makeTree(char [],char ,tree *);
void addRight(char [],char ,simpul **);
void addLeft(char [],char ,simpul **);
void delRight(simpul **);
void delLeft(simpul **);
void printTreePreOrder(simpul *);
void printTreeInOrder(simpul *);
void printTreePostOrder(simpul *);
void printTreeLevelOrderNext(simpul *);
void printTreeLevelOrder(simpul *);
void copyTree(simpul *,simpul **);
int isEqual(simpul *,simpul *);
simpul* cariSimpul(char [],simpul* );
int jumlahsimpul(int ,simpul *);