#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct{
	float angka;
}data;

typedef struct elmt *alamat;
typedef struct elmt{
	data elmt;
	alamat next;
}elemen;

typedef struct{
	elemen *top;
}stack;

void createEmpty(stack *);
int isEmpty(stack );
int countElement(stack );
void push(float ,stack *);
void pop(stack *);
void printStack(stack );