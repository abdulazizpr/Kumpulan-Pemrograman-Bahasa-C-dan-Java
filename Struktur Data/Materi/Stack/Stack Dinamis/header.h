#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct{
	char nim[10];
	char nama[50];
	float nilai;
}nilaiMatkul;

typedef struct elmt *alamat;
typedef struct elmt{
	nilaiMatkul elmt;
	alamat next;
}elemen;

typedef struct{
	elemen *top;
}stack;

void createEmpty(stack *);
int isEmpty(stack );
int countElement(stack );
void push(char [],char [],float ,stack *);
void pop(stack *);
void printStack(stack );
void pop_isi(stack *,stack *);
void pindahinstack(stack *,stack *);