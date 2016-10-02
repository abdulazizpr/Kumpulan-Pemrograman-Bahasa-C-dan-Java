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

void addFirst(char kata[],int nilai,list *L){
	
	elemen *baru;
	baru = (elemen *) malloc (sizeof (elemen));
	strcpy(baru->elmt.kata, kata);
	baru->elmt.nilai = nilai;
	
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

void addAfter(elemen *prev,char kata[],int nilai,list *L){
	
	elemen *baru;
	baru = (elemen *) malloc (sizeof (elemen));
	strcpy(baru->elmt.kata, kata);
	baru->elmt.nilai = nilai;
	
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

void addLast(char kata[],int nilai,list *L){
	
	//jika list adalah list kosong
	if((*L).first == NULL) addFirst(kata,nilai,L);
	else{	
		//jika list tidak kosong
		elemen *prev = (*L).tail;		
		addAfter(prev, kata,nilai, L);
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
		elemen *depan = L.first;		//inisialisasi
		elemen *belakang = L.tail;		//inisialisasi
		
		int i = 0;
		while(depan != belakang && i<countElment(L)/2){
			
			printf("%s\n",depan->elmt.kata);
			printf("%s\n",belakang->elmt.kata);
			
			depan = depan->next;
			belakang = belakang->prev;
			i++;
			
		}
	}
	//proses jika list kosong
	else printf("List Kosong\n");
}

int jumlah_ascii(char kata[]){
	
	int temp,i;
	int hitung=0;
	for(i=0;i<strlen(kata);i++){
		temp=kata[i];
		hitung = hitung + temp;
	}
	
	return hitung;
}

void sort_depan(list *L){
	
	if((*L).first != NULL){
		
		int tukar;
		elemen *prev;
		elemen *now;
		elemen *next;
			
		do{
			prev = NULL;			
			now = (*L).first;		
			next = now->next;		
			
			tukar = 0;		
			
			while(next != NULL){
				//jika elemen hasil penjualan yang sekarang kurang dari hasil_penjualan selanjutnya
				if(now->elmt.nilai > next->elmt.nilai){
					//maka tukar elemen pertama yg selanjutnya dengan setelah yg selanjutnya
					now->next = next->next;
					next->next = now;	//dan elemen setelah yg selanjutnya menjadi elemen yg sekarang
					
					//jika ada di awal maka elemen awal menjadi elemen yang selanjutnya
					if(now == (*L).first) (*L).first = next;
					else prev->next = next; //jika tidak, elemen sebelum setelahnya menjadi elemen selanjutnya
					
					now = next;	//elemen sekarang menjadi elemen selanjutnya
					tukar = 1;	//ulang jika ada yang ditukar lagi
				}
				
				//iterasi
				prev = now;	//elemen sebelumnya menjadi sekarang
				now = next;	//elemen sekarang menjadi selanjutnya
				next = next->next; // elemen selanjutnya menjadi elemen yang setelah selanjutnya
			}
			
		}while(tukar==1);
		
	}
}

void sort_belakang(list *L){
	
	if((*L).first != NULL){
		
		int tukar;
		elemen *prev;
		elemen *now;
		elemen *next;
			
		do{
			prev = NULL;			//inisialisasi keadaan awal
			now = (*L).tail;		//elemen pertama menjadi yang sekarang
			next = now->prev;		//elemen selanjutnya menjadi elemen yang sekarang itu mempunyai elemen selanjutnya
			
			tukar = 0;		//inisialisasi pertukaran
			
			while(next != NULL){
				//jika elemen hasil penjualan yang sekarang kurang dari hasil_penjualan selanjutnya
				if(now->elmt.nilai < next->elmt.nilai){
					//maka tukar elemen pertama yg selanjutnya dengan setelah yg selanjutnya
					now->prev = next->prev;
					next->prev = now;	//dan elemen setelah yg selanjutnya menjadi elemen yg sekarang
					
					//jika ada di awal maka elemen awal menjadi elemen yang selanjutnya
					if(now == (*L).tail) (*L).tail = next;
					else prev->prev = next; //jika tidak, elemen sebelum setelahnya menjadi elemen selanjutnya
					
					now = next;	//elemen sekarang menjadi elemen selanjutnya
					tukar = 1;	//ulang jika ada yang ditukar lagi
				}
				
				//iterasi
				prev = now;	//elemen sebelumnya menjadi sekarang
				now = next;	//elemen sekarang menjadi selanjutnya
				next = next->prev; // elemen selanjutnya menjadi elemen yang setelah selanjutnya
			}
			
		}while(tukar==1);
		
	}
}

void delAll(list *L){
	
	if(countElment(*L) != 0){
		int i;
		for(i=countElment(*L);i>=1;i--) delLast(L);
	}
	
}