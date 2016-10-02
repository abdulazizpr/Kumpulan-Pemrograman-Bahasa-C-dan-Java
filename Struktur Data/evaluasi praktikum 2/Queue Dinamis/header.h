#include <stdio.h>
#include <string.h>
#include <malloc.h>

/*
Saya Abdul Aziz Priatna tidak melakukan kecurangan seperti yang telah dispesifikasikan
pada mata kuliah Strurktur Data dalam mengerjakan Evaluasi Praktikum 2, jika saya melakukan kecurangan
maka Allah/Tuhan adalah saksi saya, dan saya bersedia menerima hukumanNya. Aamiin.
*/

typedef struct{
	char namab[100];
	int waktu;
	int ongkos;
}kontainer;

typedef struct elm *alamatelmt;
typedef struct elm{
	kontainer elmt;
	int prioritas;
	alamatelmt next;
}elemen;

typedef struct{
	elemen *first;
	elemen *last;
}queue;

void add(char [],int ,int ,queue *);
void del(queue *);
void printQueue(int,queue );
//void add_prioritas(char ,int ,int ,int ,queue *);
