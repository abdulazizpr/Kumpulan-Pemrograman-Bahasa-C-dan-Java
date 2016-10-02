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

int hasil_blk(double koma){
	
	int a,hasil;
	a = koma;
	hasil = (koma*100)-(a*100); 
	
	return hasil;
}

void addFirst(double koma,int blk_koma,list *L){
	
	elemen *elmt;
	elmt = (elemen *) malloc (sizeof (elemen));
	elmt->elmt.koma = koma;
	elmt->elmt.blk_koma = blk_koma;
	elmt->next = (*L).first;
	(*L).first = elmt;
	elmt = NULL;
	
}


void sorting(bungkusan tabel[],int n){
	int i,j,minindeks;
	
	bungkusan temp;
	
	for(i=0;i<n-1;i++){
		//inisialisasi indeks minimum
		minindeks=i;
		/*untuk mencari nilai minimum*/
		for(j=i+1;j<n;j++){
			if(tabel[j].blk_koma<tabel[minindeks].blk_koma){
				minindeks=j;
			}
		}
		//pertukaran dengan nilai minimum
		temp=tabel[minindeks];
		tabel[minindeks]=tabel[i];
		tabel[i]=temp;
	}
	
}

void printElement(list L){
	
	bungkusan tabel[100];
	
	if(L.first != NULL){			//jika list tidak kosong
		elemen *elmt = L.first;		//inisialisasi
		
		int i = 0;
		while(elmt != NULL){			
			tabel[i].koma = elmt->elmt.koma;			
			tabel[i].blk_koma = elmt->elmt.blk_koma;
			
			elmt = elmt->next;
			i++;
		}
		
		sorting(tabel,i);
		
		int j;
		for(j=0;j<i;j++){
			printf("%.2lf\n",tabel[j].koma);
		}
		
	}
}
	