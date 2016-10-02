#include <stdio.h>
#include <string.h>

//variabel global
int indeks;
char cc;
char prev,now,next1,next2;
int spasi;

//prosedur mesin karakater
void START(char pita[]);
void INC(char pita[]);
void ADV(char pita[]);
char GETCC();
int EOP();

//prosedur pengecekan 2 spasi diantara karakater
void cek(char pita[]);
