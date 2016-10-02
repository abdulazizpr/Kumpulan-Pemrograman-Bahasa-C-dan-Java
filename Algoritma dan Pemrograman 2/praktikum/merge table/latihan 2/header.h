#include <stdio.h>
#include <string.h>

typedef struct{
	char nama[100];
	char kartu[100];
	int tampung;
}bungkusan;

void tampil(int ,int ,bungkusan* );
int cekkartu(int ,bungkusan* );
void selectionsort(int ,bungkusan* );
void insertionsort(int ,bungkusan* );
void bubblesort(int ,bungkusan* );
void quicksort(int ,int ,bungkusan* );