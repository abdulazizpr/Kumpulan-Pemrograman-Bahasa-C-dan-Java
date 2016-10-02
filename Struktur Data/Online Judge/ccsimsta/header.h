#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct{
	int angka;
}bilangan;

typedef struct elmt *alamat;
typedef struct elmt{
	bilangan elmt;
	alamat next;
}elemen;

typedef struct{
	elemen *top;
}stack;

stack S1;

void createEmpty(stack *);
int isEmpty(stack );
int countElement(stack );
void push(int ,stack *);
void pop(stack *);
void printStack(stack );
void isi_stack(stack ,stack *);
void copy_stack(stack ,stack *);
void pop_cari(int ,stack *);
void pop_banyak(int ,stack *);