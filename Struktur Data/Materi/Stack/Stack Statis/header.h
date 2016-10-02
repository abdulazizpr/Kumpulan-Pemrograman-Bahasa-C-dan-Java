#include <stdio.h>
#include <string.h>

typedef struct{
	char nim[10];
	char nama[50];
	float nilai;
}nilaiMatkul;

typedef struct{
	int top;
	nilaiMatkul data[10];
}stack;

void createEmpty(stack *);
int isEmpty(stack );
int isFull(stack );
void push(char [],char [],float ,stack *);
void pop(stack *);
nilaiMatkul pop_isi(stack *);