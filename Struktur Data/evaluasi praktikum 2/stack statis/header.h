#include <stdio.h>
#include <string.h>

/*
Saya Abdul Aziz Priatna tidak melakukan kecurangan seperti yang telah dispesifikasikan
pada mata kuliah Strurktur Data dalam mengerjakan Evaluasi Praktikum 2, jika saya melakukan kecurangan
maka Allah/Tuhan adalah saksi saya, dan saya bersedia menerima hukumanNya. Aamiin.
*/

typedef struct{
	char kode[100];
	char buku[100];
}bungkusan;

typedef struct{
	int top;
	bungkusan data[50];
}stack;

void createEmpty(stack *);
int isEmpty(stack );
int isFull(stack );
void push(char [],char [],stack *);
void pop(stack *);