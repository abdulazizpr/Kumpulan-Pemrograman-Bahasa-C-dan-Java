#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct smp *alamatsimpul;
typedef struct smp{
	char info;
	alamatsimpul sibling;
	alamatsimpul child;
}simpul;

typedef struct{
	simpul *root;
}tree;

void makeTree(char ,tree *);
void addChild(char c,simpul *);
void delChild(char c,simpul *root);
simpul *findSimpul(char ,simpul *);