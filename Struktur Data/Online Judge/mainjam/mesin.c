#include "header.h"

void createList(list *L){ (*L).first = NULL;}

int countElment(list L){
	
	int hasil = 0;
	
	if(L.first != NULL){		//list tidak kosong
		
		elemen *elmt;
		elmt = L.first;
		
		while(elmt != NULL){	//proses
			hasil++;
			elmt = elmt->next;
		}
	}
	
	return hasil;
}

int konversi(int jam, int menit, int detik){
	
	int jumlah_jam,jumlah_menit,jumlah_detik;
	jumlah_jam = jam * 3600;
	jumlah_menit = menit *60;
	jumlah_detik = jumlah_jam + jumlah_menit + detik;
	
	return jumlah_detik;
	
}

void sorting(bungkusan tabel[],int n){
	int i,j,minindeks;
	
	bungkusan temp;
	
	for(i=0;i<n-1;i++){
		//inisialisasi indeks minimum
		minindeks=i;
		/*untuk mencari nilai minimum*/
		for(j=i+1;j<n;j++){
			if(tabel[j].jam<tabel[minindeks].jam || tabel[j].jam==tabel[minindeks].jam && tabel[j].menit<tabel[minindeks].menit || tabel[j].menit==tabel[minindeks].menit && tabel[j].detik<tabel[minindeks].detik){
				minindeks=j;
			}
		}
		//pertukaran dengan nilai minimum
		temp=tabel[minindeks];
		tabel[minindeks]=tabel[i];
		tabel[i]=temp;
	}
	
}

void addFirst(int jam,int menit,int detik,int jumlah_detik,list *L){
	
	elemen *elmt;
	elmt = (elemen *) malloc (sizeof (elemen));
	elmt->elmt.jam = jam;
	elmt->elmt.menit = menit;
	elmt->elmt.detik = detik;
	elmt->elmt.jumlah_detik = jumlah_detik;
	
	elmt->next = (*L).first;
	(*L).first = elmt;
	elmt = NULL;
	
}

void printElement(list L){
	
	bungkusan tabel[100];
	
	if(L.first != NULL){			//jika list tidak kosong
		elemen *elmt = L.first;		//inisialisasi
		
		int i = 0;
		while(elmt != NULL){			
			tabel[i].jam = elmt->elmt.jam;			
			tabel[i].menit = elmt->elmt.menit;
			tabel[i].detik = elmt->elmt.detik;
			tabel[i].jumlah_detik = elmt->elmt.jumlah_detik;
			
			elmt = elmt->next;
			i++;
		}
		
		sorting(tabel,i);
		
		int j;
		for(j=0;j<i;j++){
			printf("%.2d:%.2d:%.2d\n",tabel[j].jam,tabel[j].menit,tabel[j].detik);
		}
		
	}
}