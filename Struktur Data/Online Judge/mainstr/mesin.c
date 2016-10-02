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

int hasil_jumlah(char kata[100]){
	
	int i,hasil=0;
	for(i=0;i<strlen(kata);i++){
		if(kata[i]=='a'){
			hasil++;
		}
	}
	
	return hasil;
	
}

void addFirst(char kata[],int jumlah_a,list *L){
	
	elemen *elmt;
	elmt = (elemen *) malloc (sizeof (elemen));
	strcpy(elmt->elmt.kata, kata);
	elmt->elmt.jumlah_a = jumlah_a;
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
			if(tabel[j].jumlah_a<tabel[minindeks].jumlah_a){
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
			strcpy(tabel[i].kata, elmt->elmt.kata);			
			tabel[i].jumlah_a = elmt->elmt.jumlah_a;
			
			elmt = elmt->next;
			i++;
		}
		
		sorting(tabel,i);
		
		int j;
		for(j=0;j<i;j++){
			printf("%s\n",tabel[j].kata);
		}
		
	}
	
	
}