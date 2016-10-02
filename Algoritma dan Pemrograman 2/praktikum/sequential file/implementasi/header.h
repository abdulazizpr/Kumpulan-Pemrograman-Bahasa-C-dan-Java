#include <stdio.h>
#include <string.h>

//bungkusan data mahasiswa
typedef struct{
	char nim[15];
	char nama[25];
	char kelas[5];
}mahasiswa;

//variabel global
mahasiswa data[999];
int n;

//proses
void readFile(); 			//untuk baca file
void writeFile();			//untuk write file

int findData(char[15]);		//untuk mencari data
void insertData(mahasiswa);	//untuk input data
void deleteData(char[15]);	//untuk hapus data
void updateData(char[15]);	//untuk ubah data