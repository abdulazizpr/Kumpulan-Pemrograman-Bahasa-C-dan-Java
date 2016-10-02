#include <stdio.h>
#include <string.h>

//bungkusan untuk menampung hasil penjumlahan di setiap indeks
typedef struct{
	int digit[100];
}tes;//nama bungkusan

//fungsi bungkusan untuk penjumlahan
tes tambah(int ,char [][100]);

//fungsi untuk mencari nilai maximal
int maximal(int, tes );

//untuk menampilkan hasil valid/tidak valid
void validtidakvalid(int , int [100],int , char [][100],tes ,int );
