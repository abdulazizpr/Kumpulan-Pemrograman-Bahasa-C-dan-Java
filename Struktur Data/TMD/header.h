#include <stdio.h>
#include <string.h>
#include <malloc.h>

/*
Saya Abdul Aziz Priatna tidak melakukan kecurangan seperti yang telah dispesifikasikan
pada mata kuliah Struktur Data dalam mengerjakan Tugas Masa Depan Struktur Data, jika saya melakukan kecurangan
maka Allah/Tuhan adalah saksi saya, dan saya bersedia menerima hukumanNya. Aamiin.
*/

//variabel global
char anak[100];
char ortu[100];
char temp[100][100];
int panjang[100];
int jumlah_hapus;

typedef struct smp *alamatsimpul;	//deklarasi pointer simpul
//simpul
typedef struct smp{
	char nama[100];
	alamatsimpul sibling;
	alamatsimpul child;
}simpul;

//pohon
typedef struct{
	simpul *root;
}tree;

//prosedur dan fungsi pohon
void makeTree(char [],tree *);
void addChild(char [], simpul **);
void delChild(char [],simpul **);
simpul *findSimpul(char [],simpul *);
void printTreePreOrder(simpul *,int ,int );

//prosedur dan fungsi pengopreasian
void inisialisasi(int );
void caripanjangkata(simpul* ,int );
int cari_hastag(char []);
void pemisah(char []);
void delete_anak(simpul **);
void cari_ortu(char [], char [][100],simpul *,int );