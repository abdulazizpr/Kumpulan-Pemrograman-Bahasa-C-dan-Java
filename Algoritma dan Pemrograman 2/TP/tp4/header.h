#include <stdio.h>
#include <string.h>

//bungkusan
typedef struct{
	char toko[100];
	char makanan[100];
	int harga;
}bungkusan;

//variabel global
int n,i,j;
bungkusan kueh[100];

//prosedur
void tulis();
void quicksort(int ,int );