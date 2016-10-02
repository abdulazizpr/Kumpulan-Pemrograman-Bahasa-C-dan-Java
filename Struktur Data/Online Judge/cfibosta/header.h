#include <stdio.h>
#include <string.h>

int n;

typedef struct{
	int angka;
}bilangan;

typedef struct{
	int top;
	bilangan data[100];
}stack;

void createEmpty(stack *);
int isFull(stack );
void push(int , stack *);
void pop(stack *);
void printStack(stack );
void fib(int* , int ,int ,int , int );