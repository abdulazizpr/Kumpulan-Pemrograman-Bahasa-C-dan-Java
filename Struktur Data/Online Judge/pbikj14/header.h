#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct smp *alamatsimpul;
typedef struct smp{
	int nilai;
	alamatsimpul left;
	alamatsimpul right;
}simpul;

typedef struct{
	simpul *root;
}tree;

void makeTree(int ,tree *);
void addRight(int ,simpul **);
void addLeft(int ,simpul **);
void delRight(simpul **);
void delLeft(simpul **);
void printTreePreOrder(simpul *);
void printTreeInOrder(simpul *);
void printTreePostOrder(simpul *);
void printTreeLevelOrderNext(simpul *);
void printTreeLevelOrder(simpul *);
void copyTree(simpul *,simpul **);
int isEqual(simpul *,simpul *);
simpul* cariSimpul(int ,simpul* );
int jumlahsimpulkiri(int ,simpul *);