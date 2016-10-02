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

void addFirst(char kota[],int jarak,list *L){
	
	elemen *baru;
	baru = (elemen *) malloc (sizeof (elemen));
	strcpy(baru->elmt.kota, kota);
	baru->elmt.jarak = jarak;
	
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

void addAfter(elemen *prev,char kota[],int jarak,list *L){
	
	elemen *baru;
	baru = (elemen *) malloc (sizeof (elemen));
	strcpy(baru->elmt.kota, kota);
	baru->elmt.jarak = jarak;
	
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

void addLast(char kota[],int jarak,list *L){
	
	//jika list adalah list kosong
	if((*L).first == NULL) addFirst(kota,jarak,L);
	else{	
		//jika list tidak kosong
		elemen *prev = (*L).tail;		
		addAfter(prev, kota,jarak, L);
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
		
		int i = 1;
		while(elmt != NULL){
			//proses
			printf("%s %d\n",elmt->elmt.kota,elmt->elmt.jarak);
			
			//iterasi
			elmt = elmt->next;
			i++;
		}
		
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

void operasi_add(char terminal_baru[],char terminal_lama[],int jarak,list *L){
	
	if((*L).first != NULL){
		
		elemen *maju = (*L).first;
		elemen *sebelum;
		
		int status = 0;		//inisialisasi status pemberhintian
		int jarak_lama;
		int jarak_lama2;
		while(maju->next != NULL && status==0){
			if(strcmp(maju->elmt.kota,terminal_lama)==0){ //jika terminal_lama sama dengan yang ada di list
				if(maju->elmt.jarak > jarak){	//jika jarak di list lebih dari jarak baru
					jarak_lama = maju->elmt.jarak;	
					maju->elmt.jarak = jarak;	//maka jarak_lama sama dengan jarak baru
					jarak = jarak_lama - jarak;	//jarak lama dikurangi jarak baru
					sebelum = maju;				//ambil index sebelumnya
				}else{
					jarak_lama = maju->elmt.jarak;
					jarak_lama2 = maju->next->elmt.jarak;	//ambil jarak_lama setelahnya untuk dikurangi
					jarak = jarak - jarak_lama;				//jarak dikurangi jarak_lama
					maju->next->elmt.jarak = jarak;			//jarak_lama setelahnya sama dengan jarak baru
					jarak =  jarak_lama2 - jarak;			//jarak_lama2 setelahnya dikurangi jarak baru
					sebelum = maju->next;					//ambil index sebelum di setelahnya
				}
				status = 1;	//tanda berhenti
			}
			maju = maju->next;
		}
		
		//masukan secara addAfter dengan index sebelumnya
		addAfter(sebelum,terminal_baru,jarak,L);
	}
	
}

void operasi_del(char terminal[],list *L){
	
	if((*L).first != NULL){
			
		elemen *maju = (*L).first;
		
		elemen *sebelum;	//untuk mengambil index sebelumnya
		int status = 0;
		
		while(maju->next != NULL && status==0){
			if(strcmp(maju->next->elmt.kota,terminal)==0){	//jika list setelahnya sama dengan terminal
				maju->elmt.jarak+=maju->next->elmt.jarak;	//maka jumlahkan jarak sebelum dengan setelahnya
				sebelum = maju;	//ambil index sebelumnya
				status = 1;		//tanda berhenti
			}
			
			maju = maju->next;
		}
		
		//hapus secara delAfter dengan index sebelumnya
		delAfter(sebelum,L);
	}
	
}

elemen *cari(char cari[],list *L){
	
	if((*L).first != NULL){		
		
		elemen *maju = (*L).first;
		elemen *index;
		
		int status = 0;
		while(maju != NULL && status==0){
			if(strcmp(maju->elmt.kota,cari)==0){	//jika data yang di cari sama dengan ada yang di list
				index = maju;	//maka ambil index saat ini
				status = 1;		//tanda berhenti
			}
			maju = maju->next;
		}
		
		return index;	//lempar index ke fungsi
	}
	
	
}

int operasi_count(char pertama[],char terakhir[],list *L){
	
	if((*L).first != NULL){
		
		elemen *awal = cari(pertama,L);		//mencari elemen awal
		elemen *akhir = cari(terakhir,L);	//mencari elemen akhir
			
		int hasil = 0;
		while(awal != akhir){	//berulang selama awal tidak sama dengan akhir
			hasil+=awal->elmt.jarak;	//jumlahkan semua jarak dari awal sampe akhir
			awal = awal->next;	//iterasi
		}
		
		//lempar hasil ke fungsi
		return hasil;
	}
	
}