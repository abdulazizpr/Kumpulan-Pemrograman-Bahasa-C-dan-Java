#include <stdio.h>
#include <string.h>

typedef struct{
	char huruf;
}bungkusan;

typedef struct{
	int top;
	bungkusan data[3];
}stack;

void createEmpty(stack *);
int isEmpty(stack );
int isFull(stack );
void push(char ,stack *);
void pop(stack *);
bungkusan pop_isi(stack *);