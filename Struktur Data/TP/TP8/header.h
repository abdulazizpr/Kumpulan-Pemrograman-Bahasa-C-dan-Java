#include <stdio.h>
#include <string.h>
#include <malloc.h>

/*
Saya Abdul Aziz Priatna tidak melakukan kecurangan seperti yang telah dispesifikasikan
pada mata kuliah Strurktur Data dalam mengerjakan TP8, jika saya melakukan kecurangan
maka Allah/Tuhan adalah saksi saya, dan saya bersedia menerima hukumanNya. Aamiin.


	
(tp813) Pohon Biner


Pembuat Soal: Asisten

Batas Waktu Eksekusi	5 Detik
Batas Memori	1 MB

Pohon Biner dibawah ini menggambarkan silsilah dari masyarakat Bandung yang melakukan program seperti Pay It Forward. Pay it Forward yaitu sebuah konsep membalas sebuah kebaikan dengan melakukan kebaikan ke orang lain.

Diberikan N (Integer) banyak Kasus dan setiap kasus memiliki S (String). Anda diminta untuk mencari asal pemberi kebaikan, generasi, dan jumlah kebaikan yang telah tersebar

Asal pemberi kebaikan adalah elemen yang berada tepat di atas elemen yang ditemukan.

Generasi adalah level dari elemen yang ditemukan

Jumlah kebaikan yang dihitung mulai dari root hingga elemen yang ditemukan

Lihat gambar di bawah ini:


Format Masukan

N : banyak kasus
N baris Kasus
	S: String nama yang dicari.
Format Keluaran

N baris (Asal, Generasi, Jumlah) dipisahkan dengan spasi
Contoh Masukan

4
Akbar
Nesa 
Euis
Hadi

Contoh Keluaran

Atik 4 66
Hadi 2 25
Ando 3 52
Null 1 10


*/

typedef struct{
	char nama[100];
	int angka;
}kontainer;

typedef struct smp *alamatsimpul;
typedef struct smp{
	kontainer data;
	alamatsimpul left;
	alamatsimpul right;
}simpul;

typedef struct{
	simpul *root;
}tree;

int jumlahsimpul;

void makeTree(char [],int ,tree *);
void addRight(char [],int ,simpul **);
void addLeft(char [],int ,simpul **);
void delRight(simpul **);
void delLeft(simpul **);
void printTreePreOrder(simpul *);
void printTreeInOrder(simpul *);
void printTreePostOrder(simpul *);
void printTreeLevelOrderNext(simpul *);
void printTreeLevelOrder(simpul *);
void copyTree(simpul *,simpul **);
int isEqual(simpul *,simpul *);
int carinamasimpulortu(char [],simpul *);
void tampilortu(char [],simpul* );
void carigenerasi(int ,simpul* ,simpul *);
void jumlahsimpulcari(int ,simpul* ,simpul *);
simpul* findSimpul(char [],simpul* );