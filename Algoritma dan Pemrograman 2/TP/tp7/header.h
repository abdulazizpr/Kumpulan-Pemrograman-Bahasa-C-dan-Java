#include <stdio.h>
#include <string.h>

//bungkusan laporan
typedef struct{
	char kode_barang[10];
	char nama_barang[100];	
	int harga_barang;
	int jumlah_yang_terjual;
	int total;
}laporan;

int total_harga(int ,laporan* );							//fungsi total_harga
void sorting(int ,int ,laporan* );							//prosedur sorting
void merge(laporan [],laporan [],laporan [],int ,int );		//penggabungan 2 tabel
