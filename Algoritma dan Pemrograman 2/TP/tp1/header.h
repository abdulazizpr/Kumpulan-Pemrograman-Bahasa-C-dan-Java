#include <stdio.h>
#include <string.h>


//bungkusan matriks
typedef struct{
	int matriks[100][100];
	int matriks2[100][100];
}nama;

//fungsi bungkusan untuk menampung proses perubahan matriks
nama proses(int ,int ,nama ,int ,char [][100],int [],int []);

//prosedur untuk menampilkan hasil matriks yang telah berubah
void tampil(nama ,int ,int );