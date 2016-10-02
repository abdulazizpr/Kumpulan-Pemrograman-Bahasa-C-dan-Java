#include "header.h"

void createList(list *L){ (*L).first = NULL;}

int countElementB(list L){
	
	int hasil = 0;
	
	if(L.first != NULL){		//list tidak kosong
		
		eBaris *elmt;
		
		elmt = L.first;         //inisialisasi
		
		while(elmt != NULL){	//proses
			hasil++;
			elmt = elmt->next;	//iterasi
		}
	}
	
	return hasil;
}

int countElementK(eBaris L){
	
	int hasil = 0;
	
	if(L.col != NULL){		//list tidak kosong
		
		eKolom *elmt;
		
		elmt = L.col;         //inisialisasi
		
		while(elmt != NULL){	//proses
			hasil++;
			elmt = elmt->next;	//iterasi
		}
	}
	
	return hasil;
}

void addFirstB(int penyebut, list *L){
	
	eBaris *baru;
	baru = (eBaris *) malloc (sizeof (eBaris));
	baru->elmt.penyebut = penyebut;
	
	baru->col = NULL;
	
	if((*L).first == NULL) baru->next = NULL;
	else baru->next = (*L).first; 
	
	(*L).first = baru;
	baru = NULL;
	
}

void addFirstK(int pembilang,eBaris *L){
	
	eKolom *baru;
	baru = (eKolom *) malloc (sizeof (eKolom));
	baru->elmt.pembilang = pembilang;
	
	if((*L).col == NULL) baru->next = NULL;
	else baru->next = (*L).col; 
	
	(*L).col = baru;
	baru = NULL;
	
}


void addAfterB(eBaris *prev,int penyebut){
	
	eBaris *baru;
	baru = (eBaris *) malloc (sizeof (eBaris));
	baru->elmt.penyebut = penyebut;

	baru->col = NULL;
	
	if(prev->next == NULL) baru->next = NULL;
	else baru->next = prev->next;
	
	prev->next = baru;
	baru = NULL;

}

void addAfterK(eKolom *prev,int pembilang){
	
	eKolom *baru;
	baru = (eKolom *) malloc (sizeof (eKolom));
	baru->elmt.pembilang = pembilang;
	
	if(prev->next == NULL) baru->next = NULL;
	else baru->next = prev->next;
	
	prev->next = baru;
	baru = NULL;

}

void addLastB(int penyebut,list *L){
	
	//jika list adalah list kosong
	if((*L).first == NULL) addFirstB(penyebut,L);
	else{	
		//jika list tidak kosong
		//mencari elemen terakhir list
		
		eBaris *prev = (*L).first;
		//mencari elemen terakhir list
		while(prev->next != NULL) prev = prev->next; //iterasi
		
		addAfterB(prev, penyebut);
	}
	
}

void addLastK(int pembilang,eBaris *L){
	
	//jika list adalah list kosong
	if((*L).col == NULL) addFirstK(pembilang,L);
	else{	
		//jika list tidak kosong
		//mencari elemen terakhir list
		
		eKolom *prev = (*L).col;
		//mencari elemen terakhir list
		while(prev->next != NULL) prev = prev->next; //iterasi
		
		addAfterK(prev, pembilang);
	}
	
}

void delFirstB(list *L){
	
	if((*L).first != NULL){			//jika bukan list kosong
		eBaris *hapus = (*L).first;
		
		if(countElementB(*L)==1) (*L).first = NULL;
		else {
			(*L).first = (*L).first->next; 
			hapus->next = NULL;
		}
		
		free(hapus);
	}
	
}

void delFirstK(eBaris *L){
	
	if((*L).col != NULL){			//jika bukan list kosong
		eKolom *hapus = (*L).col;
		
		if(countElementK(*L)==1) (*L).col = NULL;
		else {
			(*L).col = (*L).col->next; 
			hapus->next = NULL;
		}
		
		free(hapus);
	}
	
}

void delAfterB(eBaris *prev){
	
	eBaris *hapus = prev->next;
	if(hapus != NULL){
		if(hapus->next == NULL) prev->next = NULL;
		else{ 
			prev->next = hapus->next;
			hapus->next = NULL;
		}	
		free(hapus);
	}
	
}

void delAfterK(eKolom *prev){
	
	eKolom *hapus = prev->next;
	if(hapus != NULL){
		if(hapus->next == NULL) prev->next = NULL;
		else{ 
			prev->next = hapus->next;
			hapus->next = NULL;
		}	
		free(hapus);
	}
	
}

void delLastB(list *L){			
	
	if((*L).first != NULL){
		//jika list tidak list kosong
		if(countElementB(*L) == 1) delFirstB(L);	//list hanya satu elemen
		else{
			//mencari elemen terakhir
			eBaris *last = (*L).first;
			eBaris *prev;
			
			while(last->next != NULL){
				//iterasi
				prev = last;
				last = last->next;
			}
			
			delAfterB(prev);
		}
	}
	
}

void delLastK(eBaris *L){			
	
	if((*L).col != NULL){
		//jika list tidak list kosong
		if(countElementK(*L) == 1) delFirstK(L);	//list hanya satu elemen
		else{
			//mencari elemen terakhir
			eKolom *last = (*L).col;
			eKolom *prev;
			
			while(last->next != NULL){
				//iterasi
				prev = last;
				last = last->next;
			}
			
			delAfterK(prev);
		}
	}
	
}

void printElement(list L){
	
	if(L.first != NULL){			//jika list tidak kosong
		eBaris *elmt = L.first;		//inisialisasi
		
		int i = 1;
		while(elmt != NULL){
			//proses
			printf("%d\n",elmt->elmt.penyebut);//tampilkan penyebut
			
			eKolom *eCol = elmt->col;
			while(eCol != NULL){
				//tampilkan pembilang
				printf("%d",eCol->elmt.pembilang);
				if(eCol->next != NULL){//jika setelahnya tidak null
					printf(" ");//print spasi
				}
				eCol = eCol->next;
			}
			printf("\n");//enter
			
			//iterasi
			elmt = elmt->next;
			i++;
		}
	}
	//proses jika list kosong
	else printf("List Kosong\n");
}

void delAllB(list *L){
	
	if(countElementB(*L) != 0){
		int i;
		for(i=countElementB(*L);i>=1;i--) delLastB(L);
	}
	
}

void delAllK(eBaris *L){
	
	if(countElementK(*L) != 0){
		int i;
		for(i=countElementK(*L);i>=1;i--) delLastK(L);
	}
	
}

eBaris *cari(int penyebut,list L){
	
	eBaris *sekarang = NULL;//default jika tidak ditemukan
	if(L.first != NULL){
		
		eBaris *maju = L.first;
		
		int status = 0;
		while(maju != NULL && status==0){
			if(maju->elmt.penyebut==penyebut){//jika ketemu
				status = 1;//berhenti
				sekarang = maju;//ambil baris
			}
			maju = maju->next;
		}
		
	}
	//lempar ke fungsi
	return sekarang;
}  

