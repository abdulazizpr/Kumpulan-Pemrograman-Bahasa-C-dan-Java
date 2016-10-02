#include <stdio.h>
#include <string.h>

//variabel global
int indeks;
int panjangkata;
char ckata[50];
int underscore;

//prosedur mesin kata
void start(char []);
void inc(char []);
char* getkata();
int eop(char []);

//prosedur pengecekan apakah ada minimal 2 unduerscore diantara 2 kata
void cek();
