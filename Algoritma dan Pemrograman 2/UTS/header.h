#include <stdio.h>
#include <string.h>

//bungkusan berisi 2 string dan 1 int
typedef struct{
	char kata1[100];
	char kata2[100];
	int jumlah;
}bungkusan;

//fungsi
int pasangankonsonanvokal(int ,bungkusan* );

//prosedur
void selectionsort(int ,bungkusan* );
void insertionsort(int ,bungkusan* );
void bubblesort(int ,bungkusan* );
void quicksort(int ,int ,bungkusan* );
void merge(bungkusan [],bungkusan [],bungkusan [],int ,int );