#include <stdio.h>
#include <string.h>

typedef struct{
	char kata[100];
	int jumlah_a;
}bungkusan

int indeks;
int panjangkata;
char ckata[50];

void start(char []);
void inc(char []);
char* getkata();
int eop(char []);
