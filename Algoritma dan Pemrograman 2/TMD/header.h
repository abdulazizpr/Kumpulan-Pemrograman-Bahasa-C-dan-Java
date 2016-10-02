/* 
Nama		: Abdul Aziz Priatna
NIM			: 1307123
Kelas		: Ilmu Komputer C2 2013

Tugas Masa Depan Algoritma dan Pemrograman 2

Sumpah		:
Saya Abdul Aziz Priatna(1307123) tidak melakukan kecurangan seperti yang telah dispesifikasikan pada 
mata kuliah Algoritma dan Pemograman 2 dalam mengerjakan Tugas Masa Depan Alpro 2, jika saya melakukan kecurangan maka Allah/Tuhan adalah saksi saya, dan saya bersedia menerima hukumanNya. Aamiin.
*/

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <windows.h> //standard library buat tipe data HANDLE, fungsi GetStdHandle dan prosedur SetConsoleTextAtrribute

//bungkusan
typedef struct{
	char nama_pola[100];
	int x,y;
}bungkusan;//nama bungkusan

//variabel global
int n;							
bungkusan pola[100];
char tampung[999];

//prosedur animasi
void wait(float );

//prosedur warna
void setcolor(unsigned short );

//halaman rekaman pola
void rekaman_pola();

//halaman simulasi animasi
void simulasianimasi(char [],int );//tampil simulasi
void inputpolaanimasi();//input pola animasi

///////////////////////////////////////////mesin crud//////////////////////////////////////////////////////////
//isi tampilan tabel
void tampil_tabel();

//prosedur metode CRUD (Create,Read,Update<tidak ada>,Delete)
void insert(bungkusan );
void baca_data();
void hapus(char []);
int cari(bungkusan );

//prosedur penyimpanan data
void simpan();

///////////////////////////////////////////mesin crud//////////////////////////////////////////////////////////

///////////////////////////////////////////mesin kata//////////////////////////////////////////////////////////
//variabel global mesinkata
int indeks;
char ckata[100];//current kata
int panjangkata;

//mesin kata
void STARTKATA(char []);
void RESETKATA();
void INCKATA(char []);
char* GETCKATA();
int GETPANJANGKATA();
int EOPKATA(char []);

///////////////////////////////////////////mesin kata///////////////////////////////////////////////////////////

