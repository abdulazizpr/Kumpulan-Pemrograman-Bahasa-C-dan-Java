#include "header.h"

void createList(list *L){ 
	(*L).first = NULL;
	(*L).tail = NULL;
}

int countElment(list L){
	
	int hasil = 0;
	
	if(L.first != NULL){		//list tidak kosong
		
		elemen *elmt;
		
		elmt = L.first;         //inisialisasi
		
		while(elmt != NULL){	//proses
			hasil++;
			elmt = elmt->next;	//iterasi
		}
	}
	
	return hasil;
}

void addFirst(char nama_depan[],char nama_belakang[],list *L){
	
	elemen *baru;
	baru = (elemen *) malloc (sizeof (elemen));
	strcpy(baru->elmt.nama_depan, nama_depan);
	strcpy(baru->elmt.nama_belakang, nama_belakang);
	
	if((*L).first == NULL) {		//jika list kosong
		baru->prev =  NULL;
		baru->next = NULL;
		(*L).tail = baru;		
	}else {							//jika list tidak kosong
		(*L).first->prev = baru;
		baru->prev =  NULL;
		baru->next = (*L).first;
	} 
	
	(*L).first = baru;
	baru = NULL;
	
}

void addAfter(elemen *prev,char nama_depan[],char nama_belakang[],list *L){
	
	elemen *baru;
	baru = (elemen *) malloc (sizeof (elemen));
	strcpy(baru->elmt.nama_depan, nama_depan);
	strcpy(baru->elmt.nama_belakang, nama_belakang);
	
	if(prev->next != NULL){		//jika baru bukan elemen terakhir
		baru->next = prev->next;
		baru->next->prev = baru;
	}else{
		baru->next = NULL;
		(*L).tail = baru;
	} 
	
	baru->prev = prev;
	prev->next = baru;
	baru = NULL;
}

void addLast(char nama_depan[],char nama_belakang[],list *L){
	
	//jika list adalah list kosong
	if((*L).first == NULL) addFirst(nama_depan,nama_belakang,L);
	else{	
		//jika list tidak kosong
		elemen *prev = (*L).tail;		
		addAfter(prev, nama_depan, nama_belakang, L);
	}
	
}

void delFirst(list *L){
	
	if((*L).first != NULL){			//jika bukan list kosong
		elemen *hapus = (*L).first;
		
		if(countElment(*L)==1){
			(*L).first = NULL;
			(*L).tail = NULL;
		}else{
			(*L).first = (*L).first->next; 
			hapus->next = NULL;
		}
		
		free(hapus);
	}
	
}

void delAfter(elemen *prev,list *L){
	
	elemen *hapus = prev->next;
	if(hapus != NULL){
		if(hapus->next == NULL){
			(*L).tail = prev;
			prev->next = NULL;
		}else{ 
			prev->next = hapus->next;
			hapus->next->prev = prev;
			hapus->prev = NULL;
			hapus->next = NULL;
		}	
		free(hapus);
	}
	
}

void delLast(list *L){			
	
	if((*L).first != NULL){
		//jika list tidak list kosong
		if(countElment(*L) == 1) delFirst(L);	//list hanya satu elemen
		else{
			elemen *prev = (*L).tail->prev;		
			delAfter(prev, L);
		}
	}
	
}


void printElement(list L){
	
	if(L.first != NULL){			//jika list tidak kosong
		elemen *elmt = L.first;		//inisialisasi
		
		int tengah = countElment(L)/2;
		int j;
		int i = 0,k,x;
		int huruf[100];
		int jumlah_depan[100];
		int hasil_pertama[100];
		while(elmt != NULL){
			//proses
			//printf("%s %s\n",elmt->elmt.nama_depan,elmt->elmt.nama_belakang);
				
			x = 0;
			for(j=0;j<strlen(elmt->elmt.nama_depan);j++){
				huruf[x] = elmt->elmt.nama_depan[j];
				x++;
			}
			
			jumlah_depan[i] = 0;
			for(k=0;k<x;k++){
				jumlah_depan[i]+=huruf[k];
			}
			
			if(strcmp(elmt->elmt.nama_belakang,"****")==0){
				hasil_pertama[i] = jumlah_depan[i] * 1;
			}else{
				int jumlah = 0;
				for(j=0;j<strlen(elmt->elmt.nama_belakang);j++){
					if(elmt->elmt.nama_belakang[j]==elmt->elmt.nama_depan[0]){
						jumlah++;
					}
				}
				
				hasil_pertama[i] = jumlah_depan[i] * jumlah;
			}
			
			i++;
			elmt = elmt->next;
		}
		
		char pertama[100];
		char kedua[100];
		
		sprintf(pertama,"%d",hasil_pertama[0]);
		sprintf(kedua,"%d",hasil_pertama[1]);
		
		if(pertama[0]==kedua[0] && pertama[strlen(pertama)-1]==kedua[strlen(kedua)-1]) printf("jodoh\n");
		else printf("bukan jodoh\n");
		
		
	}
	//proses jika list kosong
	else printf("List Kosong\n");
}

void delAll(list *L){
	
	if(countElment(*L) != 0){
		int i;
		for(i=countElment(*L);i>=1;i--) delLast(L);
	}
	
}