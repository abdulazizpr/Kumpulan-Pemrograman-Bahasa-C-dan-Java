#include <stdio.h>
#include <string.h>

//bungkusan
typedef struct{
	char nama[100];//nama siswa
	int tanggal;//tanggal lahir
	char bulan[100];//bulan lahir
	int tahun;//tahun lahir
	int no_bulan;//no bulan
}kelas;


int cekbulan(int ,kelas* );//fungsi cek bulan
void sorting(kelas* ,int );//prosedur sorting
void merge(kelas* ,kelas* ,kelas* ,int ,int );//penggabungan tabel