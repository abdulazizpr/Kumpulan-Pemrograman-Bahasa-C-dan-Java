#include <stdio.h>
#include <string.h>

typedef struct{
	int arr1[2][2];
	int gelinding;
}bungkusan;

void putar(int ,int ,int ,bungkusan* );
void selectionsort(int ,bungkusan* );
void insertionsort(int ,bungkusan* );
void quicksort(int ,int ,bungkusan* );
void merge(bungkusan* ,bungkusan* ,bungkusan* ,int , int);