#include <stdio.h>
#include <string.h>

typedef struct{
	int isi[4]; 
	int pengali;
}bungkusan;

void selectionsort1(int ,int ,bungkusan* );
void selectionsort2(int ,bungkusan* );
void insertionsort1(int ,int ,bungkusan* );
void insertionsort2(int ,bungkusan* );
void quicksort1(int ,int ,int ,bungkusan* );
void quicksort2(int ,int ,bungkusan* );