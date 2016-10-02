#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct{
	char karakter;
}kontainer;

typedef struct elmt *alamat;
typedef struct elmt{
	kontainer elmt;
	alamat next;
}elemen;

typedef struct{
	elemen *top;
}stack;

void createEmpty(stack *);
int isEmpty(stack );
int countElement(stack );
void push(char ,stack *);
void pop(stack *);
void printStack(stack );
void pop_isi(stack *,stack *);
void pindahinstack(stack *,stack *);
void operasi(stack *);