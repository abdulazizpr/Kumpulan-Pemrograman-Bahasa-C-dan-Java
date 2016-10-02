#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct smp *alamatsimpul;
typedef struct smp{
	char info;
	alamatsimpul left;
	alamatsimpul right;
}simpul;

typedef struct{
	simpul *root;
}tree;

int jumlahsimpul;

void makeTree(char ,tree *);
void addRight(char ,simpul **);
void addLeft(char ,simpul **);
void delRight(simpul **);
void delLeft(simpul **);
void printTreePreOrder(simpul *);
void printTreeInOrder(simpul *);
void printTreePostOrder(simpul *);
void printTreeLevelOrderNext(simpul *);
void printTreeLevelOrder(simpul *);
void copyTree(simpul *,simpul **);
int isEqual(simpul *,simpul *);