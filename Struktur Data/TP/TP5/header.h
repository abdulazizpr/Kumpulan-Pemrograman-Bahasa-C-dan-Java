#include <stdio.h>
#include <string.h>
#include <malloc.h>

/*
Saya Abdul Aziz Priatna tidak melakukan kecurangan seperti yang telah dispesifikasikan
pada mata kuliah Strurktur Data dalam mengerjakan TP5, jika saya melakukan kecurangan
maka Allah/Tuhan adalah saksi saya, dan saya bersedia menerima hukumanNya. Aamiin.

(L0LLCW) Lomba Cipta Web


Pembuat Soal: Tim Asisten Pemrograman

Batas Waktu Eksekusi	3 Detik
Batas Memori	3 MB

Pada suatu perlombaan Cipta Web, sistem penilaian seorang Juri untuk menentukan peserta 
yang menjadi pemenang menggunakan 3 data utama dengan sistem rangking. Di awal, Juri 
hanya memasukan data peserta saja yang berisikan nama dan nomor peserta. Kemudian 
setelah berjalannya presentasi peserta lomba, Juri dapat memasukan dan mengelola data 
penilaian peserta. Data penilaian antara lain, UX dan Desain (UXD), Coding (CODE), dan 
Presentasi (PRES).

Gunakanlah List Of List untuk mengelola data peserta dan penilaian lomba Cipta Web tersebut. 
List besar digunakan untuk data nama dan nomor peserta dan list kecil untuk data penilaian 
lomba.

Untuk memasukkan data penilaian, gunakan perintah: 
INSERT(spasi)Nama_NoPeserta(spasi)JenisData(spasi)NilaiData.
(Bisa dilakukan jika belum ada datanya)

Untuk mengubah data penilaian, gunakan perintah:
UPDATE(spasi)Nama_NoPeserta(spasi)JenisData(spasi)NilaiData.
(Bisa dilakukan jika ada datanya)

Untuk menghapus data penilaian, gunakan perintah:
DELETE(spasi)Nama_NoPeserta(spasi)JenisData.
(Bisa dilakukan jika ada datanya)

Peserta akan di-rangking berdasarkan data penilaian Juri. Prioritas penilaiannya yaitu 
nilai UX dan Desain, nilai Coding, dan nilai Presentasi. Tampilkan urutan rangking, 
nama dan nomor urut peserta berurut dari rangking tertinggi ke rangking terkecil. 
Peserta yang tidak memiliki data penilaian yang lengkap tidak ditampilkan.


Format Input:
N, banyak peserta (1 < N < 50)
N baris nama _ no peserta
M, banyak proses (1 < M < 100)
M baris perintah

Format Output:
Ranking siswa. nama _ no peserta. 
Contoh Masukan

4
Iip_008
Wiwid_012
Arif_014
Fitri_005
20
INSERT Iip_008 UXD 90
INSERT Iip_008 PRES 80
INSERT Iip_008 CODE 76
UPDATE Iip_008 UXD 87
INSERT Arif_014 UXD 80
DELETE Iip_008 CODE
INSERT Arif_014 CODE 90
UPDATE Arif_014 CODE 88
INSERT Wiwid_012 UXD 90
UPDATE Iip_008 PRES 90
INSERT Wiwid_012 CODE 87
UPDATE Wiwid_012 CODE 89
UPDATE Wiwid_012 UXD 87
INSERT Arif_014 PRES 90
INSERT Fitri_005 UXD 89
INSERT Fitri_005 CODE 88
INSERT Fitri_005 PRES 80
INSERT Wiwid_012 PRES 86
UPDATE Fitri_012 PRES 89
UPDATE Fitri_012 CODE 90

Contoh Keluaran

1. Fitri_005
2. Wiwid_012
3. Arif_014
*/

//bungkusan baris
typedef struct{
	char nama_nopeserta[50];
}peserta;

//bungkusan kolom
typedef struct{
	char penilaian[50];
	int nilai;
	int total;
}data;

typedef struct eklm *alamatekolom;
typedef struct eklm{
	data elmt;
	alamatekolom next;
}eKolom;

typedef struct ebr *alamatebaris;
typedef struct ebr{
	peserta elmt;
	eKolom *col;
	alamatebaris next;
}eBaris;

typedef struct{
	eBaris *first;
}list;

//operasi list of list
void createList(list *);
int countElementB(list );
int countElementK(eBaris );
void addFirstB(char [],list *);
void addFirstK(char [],int ,eBaris *);
void addAfterB(eBaris *,char []);
void addAfterK(eKolom *,char [],int );
void addLastB(char [],list *);
void addLastK(char [],int ,eBaris *);
void delFirstB(list *);
void delFirstK(eBaris *);
void delAfterB(eBaris *);
void delAfterK(eKolom *);
void delLastB(list *L);
void delLastK(eBaris *);
void printElement(list L);
void delAllB(list *);
void delAllK(eBaris *);

//opreasi CRUD
eBaris *cariB(char [],list );
eKolom *cariK(char [],eBaris );
void update(char [],char [],int ,list *);
void delete(char [],char [],list *);
void sort(list *);
int hitungkolom(list );
void hapustidaklengkap(list *);