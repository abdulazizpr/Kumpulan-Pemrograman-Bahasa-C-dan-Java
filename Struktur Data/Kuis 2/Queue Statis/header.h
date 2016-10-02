#include <stdio.h>
#include <string.h>

/*
Saya Abdul Aziz Priatna tidak melakukan kecurangan seperti yang telah dispesifikasikan
pada mata kuliah Strurktur Data dalam mengerjakan Kuis 2, jika saya melakukan kecurangan
maka Allah/Tuhan adalah saksi saya, dan saya bersedia menerima hukumanNya. Aamiin.
*/

//kontainer
typedef struct{
	char nama[100];
	int waktu;
}kontainer;


//elemen
typedef struct{
	kontainer elmt;
	int prioritas;
}elemen;

//queue
typedef struct{
	int first;
	int last;
	elemen data[50];
}queue;

void add(char [],int ,queue *);
void del(queue *);
void printQueue(queue );
void add_prioritas(char [],int ,int ,queue *);
