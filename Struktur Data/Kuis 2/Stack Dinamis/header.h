#include <stdio.h>
#include <string.h>
#include <malloc.h>

/*
Saya Abdul Aziz Priatna tidak melakukan kecurangan seperti yang telah dispesifikasikan
pada mata kuliah Strurktur Data dalam mengerjakan Kuis 2, jika saya melakukan kecurangan
maka Allah/Tuhan adalah saksi saya, dan saya bersedia menerima hukumanNya. Aamiin.
*/

//kontainer
typedef struct{
	int angka;
}data;

//elemen
typedef struct elmt *alamat;
typedef struct elmt{
	data elmt;
	alamat next;
}elemen;

//stack
typedef struct{
	elemen *top;
}stack;

void createEmpty(stack *);
int isEmpty(stack );
int countElement(stack );
void push(int ,stack *);
void pop(stack *);
void printStack(char ,stack );
void pop_isi(stack *,stack *);
void pindahinstack(stack *,stack *);