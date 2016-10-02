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

void addFirstB(char nama_nopeserta[],list *L){
	
	eBaris *baru;
	baru = (eBaris *) malloc (sizeof (eBaris));
	strcpy(baru->elmt.nama_nopeserta, nama_nopeserta);
	
	baru->col = NULL;
	
	if((*L).first == NULL) baru->next = NULL;
	else baru->next = (*L).first; 
	
	(*L).first = baru;
	baru = NULL;
	
}

void addFirstK(char penilaian[],int nilai,eBaris *L){
	
	eKolom *baru;
	baru = (eKolom *) malloc (sizeof (eKolom));
	strcpy(baru->elmt.penilaian, penilaian);
	baru->elmt.nilai = nilai;
	
	if((*L).col == NULL) baru->next = NULL;
	else baru->next = (*L).col; 
	
	(*L).col = baru;
	baru = NULL;
	
}

void addAfterB(eBaris *prev,char nama_nopeserta[]){
	
	eBaris *baru;
	baru = (eBaris *) malloc (sizeof (eBaris));
	strcpy(baru->elmt.nama_nopeserta, nama_nopeserta);

	baru->col = NULL;
	
	if(prev->next == NULL) baru->next = NULL;
	else baru->next = prev->next;
	
	prev->next = baru;
	baru = NULL;

}

void addAfterK(eKolom *prev,char penilaian[],int nilai){
	
	eKolom *baru;
	baru = (eKolom *) malloc (sizeof (eKolom));
	strcpy(baru->elmt.penilaian, penilaian);
	baru->elmt.nilai = nilai;
	
	if(prev->next == NULL) baru->next = NULL;
	else baru->next = prev->next;
	
	prev->next = baru;
	baru = NULL;

}

void addLastB(char nama_nopeserta[],list *L){
	
	//jika list adalah list kosong
	if((*L).first == NULL) addFirstB(nama_nopeserta,L);
	else{	
		//jika list tidak kosong
		//mencari elemen terakhir list
		
		eBaris *prev = (*L).first;
		//mencari elemen terakhir list
		while(prev->next != NULL) prev = prev->next; //iterasi
		
		addAfterB(prev, nama_nopeserta);
	}
	
}

void addLastK(char penilaian[],int nilai,eBaris *L){
	
	//jika list adalah list kosong
	if((*L).col == NULL) addFirstK(penilaian,nilai,L);
	else{	
		//jika list tidak kosong
		//mencari elemen terakhir list
		
		eKolom *prev = (*L).col;
		//mencari elemen terakhir list
		while(prev->next != NULL) prev = prev->next; //iterasi
		
		addAfterK(prev, penilaian, nilai);
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
			printf("%d. %s\n",i,elmt->elmt.nama_nopeserta);

			/* eKolom *eCol = elmt->col;
			while(eCol != NULL){
				printf("-%s %d\n",eCol->elmt.penilaian,eCol->elmt.nilai);
				eCol = eCol->next;
			}
			 */
			i++;			
			elmt = elmt->next;
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

//fungsi mencari baris
eBaris *cariB(char nama_nopeserta[],list L){
	
	if(L.first != NULL){
		
		eBaris *tunjuk = L.first;
		int status = 0;
		
		while(tunjuk != NULL && status==0){
			if(strcmp(tunjuk->elmt.nama_nopeserta,nama_nopeserta)==0){//jika no pesertanya sama
				status = 1;//maka berhenti
			}else{
				tunjuk = tunjuk->next;//iterasi
			}
		}
		
		//lempar pointer tunjuk
		return tunjuk;
		
	}
	
}

eKolom *cariK(char penilaian[],eBaris L){
	
	eKolom *cari = NULL;
	if(L.col != NULL){	
		eKolom *maju = L.col;
		
		while(maju != NULL){
			if(strcmp(maju->elmt.penilaian,penilaian)==0){//jika penilaian sama dengan yang dicari
				cari = maju;//maka cari sama dengan maju
			}	
			maju = maju->next;
		}
	}
	
	//lempar cari
	return cari;
}

//prosedur update
void update(char nama_nopeserta[],char penilaian[],int nilai,list *L){
	if((*L).first != NULL){
		eBaris *tunjuk = (*L).first;
		int statusB = 0;
		int statusK = 0;
		while(tunjuk != NULL && statusB==0){
			if(strcmp(tunjuk->elmt.nama_nopeserta,nama_nopeserta)==0){//jika no pesertanya sama
				eKolom *eCol = tunjuk->col;//inisialisasi untuk kolom
				while(eCol != NULL && statusK==0){
					if(strcmp(eCol->elmt.penilaian,penilaian)==0){//jika penilaiannya sama
						eCol->elmt.nilai = nilai;//maka nilai diganti dengan nilai yang baru
						statusK = 1;//tanda berhenti
					}else{
						eCol = eCol->next;
					}					
				}
				statusB = 1;//tanda berhenti
			}else{
				tunjuk = tunjuk->next;
			}			
		}
	}	
}

void delete(char nama_nopeserta[],char penilaian[],list *L){
	if((*L).first != NULL){
		eBaris *tunjuk = (*L).first;
		int statusB = 0;
		int statusK = 0;
		while(tunjuk != NULL && statusB==0){
			if(strcmp(tunjuk->elmt.nama_nopeserta,nama_nopeserta)==0){//jika no pesertanya sama
				eKolom *eCol = tunjuk->col;
				eKolom *prev = NULL;
				//mencari elemen sebelumnya
				while(eCol->next != NULL && strcmp(eCol->elmt.penilaian,penilaian) != 0){
					prev = eCol;//inisialisasi untuk nilai sebelumnya
					eCol = eCol->next;					
				}
				//jika penilaiannya sama
				if(strcmp(eCol->elmt.penilaian,penilaian)==0){
					//jika bukan diawal maka delAfterK
					if(prev != NULL) delAfterK(prev);
					else delFirstK(tunjuk);
				}
				//tanda berhenti baris
				statusB = 1;
			}else{
				tunjuk = tunjuk->next;
			}			
		}	
	}	
}

void hapustidaklengkap(list *L){
	
	if((*L).first != NULL){
		
		eBaris *maju = (*L).first;
		eBaris *sebelum = NULL;
		
		while(maju != NULL){
			if(countElementK(*maju) != 3){//jika tiap baris elemennya tidak sama dengan 3		
				delAllK(maju);//pertama hapus dulu kolomnya agar tidak terjadi zombie :(
				if(sebelum != NULL){//jika bukan diawal
					delAfterB(sebelum);//maka hapus dengan delAfterB
					maju = (*L).first;//refresh setelah delAfterB
				}else{
					delFirstB(L);//hapus dengan delFirstB
				}				
			}
			//iterasi
			sebelum = maju;
			maju = maju->next;
		}
		
	}
	
}

int hitungkolom(list L){
	
	if(L.first!=NULL){
		
		eBaris *elmt = L.first;
		int hitung = 0;
		while(elmt != NULL){
			if(countElementK(*elmt)==3){//jika ada 3 kolom
				hitung++;//maka hitung per baris
			}
			elmt = elmt->next;
		}
		
		return hitung;
		
	}
	
}

void sort(list *L){
	
	if((*L).first != NULL){
		int tukar;
		eBaris *prev;
		eBaris *now;
		eBaris *next;	
		do{
			prev = NULL;			//inisialisasi keadaan awal
			now = (*L).first;		//baris pertama menjadi yang sekarang
			next = now->next;		//baris selanjutnya menjadi elemen yang sekarang itu mempunyai elemen selanjutnya
			
			tukar = 0;		//inisialisasi pertukaran
			
			while(next != NULL){
				//jika ada nilai yang sama maka urutkan berdasarkan nilai yang lainnya
				if((now->col->elmt.nilai < next->col->elmt.nilai)){
					//maka tukar baris pertama yg selanjutnya dengan setelah yg selanjutnya
					now->next = next->next;
					next->next = now;	//dan baris setelah yg selanjutnya menjadi baris yg sekarang
					
					//jika ada di awal maka baris awal menjadi baris yang selanjutnya
					if(now == (*L).first) (*L).first = next;
					else prev->next = next; //jika tidak, baris sebelum setelahnya menjadi elemen selanjutnya
					
					now = next;	//elemen sekarang menjadi elemen selanjutnya
					tukar = 1;	//ulang jika ada yang ditukar lagi
				}else{
					if((now->col->elmt.nilai == next->col->elmt.nilai) &&(now->col->next->elmt.nilai < next->col->next->elmt.nilai)){
						//maka tukar baris pertama yg selanjutnya dengan setelah yg selanjutnya
						now->next = next->next;
						next->next = now;	//dan baris setelah yg selanjutnya menjadi baris yg sekarang
						
						//jika ada di awal maka baris awal menjadi baris yang selanjutnya
						if(now == (*L).first) (*L).first = next;
						else prev->next = next; //jika tidak, baris sebelum setelahnya menjadi elemen selanjutnya
						
						now = next;	//elemen sekarang menjadi elemen selanjutnya
						tukar = 1;	//ulang jika ada yang ditukar lagi
					}else{
						if((now->col->next->elmt.nilai == next->col->next->elmt.nilai) && (now->col->next->next->elmt.nilai > next->col->next->next->elmt.nilai)){
							//maka tukar baris pertama yg selanjutnya dengan setelah yg selanjutnya
							now->next = next->next;
							next->next = now;	//dan baris setelah yg selanjutnya menjadi baris yg sekarang
							
							//jika ada di awal maka baris awal menjadi baris yang selanjutnya
							if(now == (*L).first) (*L).first = next;
							else prev->next = next; //jika tidak, baris sebelum setelahnya menjadi elemen selanjutnya
							
							now = next;	//elemen sekarang menjadi elemen selanjutnya
							tukar = 1;	//ulang jika ada yang ditukar lagi
						}
					}
				}
				
				//iterasi
				prev = now;	//elemen sebelumnya menjadi sekarang
				now = next;	//elemen sekarang menjadi selanjutnya
				next = next->next; // elemen selanjutnya menjadi elemen yang setelah selanjutnya
			}
			
		}while(tukar==1);//ulang jika tukar sama denga 1
		
	}
}
