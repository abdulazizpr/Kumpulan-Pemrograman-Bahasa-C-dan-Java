#include <stdio.h>
#include <string.h>

//bungkusan untuk menampung jumlahhuruf
typedef struct{
	int jumlahhuruf[100];
}bungkusan;

bungkusan jumlahhuruf(int ,char [100][100],char );//fungsi untuk menjumlahkan huruuf yang dicari
int sequential_search(bungkusan ,int ,int );//pencarian sequential_search
int binary_search(bungkusan ,int ,int );//pencarian binary_search