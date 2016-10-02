#include <stdio.h>
#include <string.h>

int n;					//variabel global untuk inputan banyaknya list

typedef struct{			//container
	char nama[100];
	char no_pegawai[7];
	int gaji_pokok;
	int bonus_gaji;
	int total_gaji;
}data;

typedef struct{			//elemen
	data elmt;	
	int next;
}elemen;

typedef struct{			//list
	int first;
	elemen data[100];
}list;

//library yg dibutuhkan
int bonus(char [],char [],int );
void createList(list *);
int countElement(list );
int emptyElement(list );
void addFirst(char [],char [],int ,list *);
void addAfter(int ,char [],char [],int , list *);
void addLast(char [],char [],int ,list *);
void delFirst(list *);
void delAfter(int ,list *);
void delLast(list *);
void delAll(list *);
void printElemen(list );
void bubble_sort(list *);
void delPegawai(list *);
void kumulatif(char [],list *);