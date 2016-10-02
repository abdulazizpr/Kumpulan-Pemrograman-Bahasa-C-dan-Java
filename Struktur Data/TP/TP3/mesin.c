#include "header.h"

void createList(list *L){
	
	(*L).first = -1;
	(*L).tail = -1;
	int i;
	
	//proses menginisialisasi isi array
	for(i=0;i<banyak;i++) {
		(*L).data[i].prev = -2;
		(*L).data[i].next = -2;
	}	
}

int countElement(list L){
	
	int hasil = 0;
	if(L.first != -1){			//list tidak kosong
		
		int elmt;
		elmt = L.first;			//inisialisasi
		
		while(elmt != -1){
			hasil++;						//proses
			elmt = L.data[elmt].next;		//iterasi
		}
		
	}
	
	return hasil;
	
}

int emptyElement(list L){
	
	int hasil = -1;
	
	if(countElement(L) < 10){
		
		int ketemu = 0;
		int i = 0;
		
		while(ketemu==0 && i<banyak){
			if(L.data[i].next == -2){
				hasil = i;
				ketemu = 1;
			}
			
			else i++;
		}
		
	}
	
	return hasil;
	
}

void addFirst(char tempat[],int berat_ikan,list *L){
	
	if(countElement(*L) < banyak){
		int baru = emptyElement(*L);
		
		strcpy((*L).data[baru].elmt.tempat, tempat);
		(*L).data[baru].elmt.berat_ikan=berat_ikan;
		
		if((*L).first == -1){				//jika list kosong
			(*L).data[baru].prev = -1;		
			(*L).data[baru].next = -1;
			(*L).tail = baru;
		}else{								//jika list tidak kosong
			(*L).data[baru].prev = -1;
			(*L).data[baru].next = (*L).first;
			(*L).data[(*L).first].prev = baru;
		}
		
		(*L).first = baru;
	}
	else printf("sudah tidak dapat ditambahkan\n");			//proses jika array penuh
	
}

void addAfter(int prev,char tempat[],int berat_ikan,list *L){
	
	if(countElement(*L) < banyak){
		int baru = emptyElement(*L);
		
		strcpy((*L).data[baru].elmt.tempat, tempat);
		(*L).data[baru].elmt.berat_ikan = berat_ikan;
		
		if((*L).data[prev].next != -1){			//jika baru bukan elemen terakhir
			(*L).data[baru].prev = prev;
			(*L).data[baru].next = (*L).data[prev].next;
			(*L).data[(*L).data[baru].next].prev = baru;
		}else{
			(*L).data[baru].prev = prev;
			(*L).data[baru].next = -1;
			(*L).tail = baru;
		}
		
		(*L).data[prev].next = baru;
	}
	else printf("sudah tidak dapat ditambahkan\n");			//proses jika array penuh
	
}

void addLast(char tempat[],int berat_ikan,list *L){
	
	if((*L).first == -1) addFirst(tempat, berat_ikan, L);		//proses jika list masih kosong
	else{													//proses jika list telah berisi elemen	
		if(countElement(*L) < banyak){						//proses jika array belum penuh
			
			int prev = (*L).tail;
			addAfter(prev, tempat, berat_ikan, L);
			
		}
		else printf("sudah tidak dapat ditambahkan\n");	//proses jika array penuh
	}
	
}

void delFirst(list *L){
	
	if((*L).first != -1){	
		int hapus = (*L).first;
		
		if(countElement(*L) == 1){								//jika satu elemen
			(*L).first = -1;				
			(*L).tail = -1;				
		}else{													//jika banyak elemen
			(*L).first = (*L).data[(*L).first].next;			
			(*L).data[(*L).first].prev = -1;
		}
		
		//elemen awal sebelumnya dikosongkan
		(*L).data[hapus].prev = -2;	
		(*L).data[hapus].next = -2;	
	}
	else printf("list kosong\n");	
	
}

void delAfter(int prev,list *L){
	int hapus = (*L).data[prev].next;
	
	if(hapus != -1){
		if((*L).data[hapus].next == -1){		//jika dibelakang
			(*L).tail = prev;
			(*L).data[prev].next = -1;			
		}else{									//jika ditengah
			(*L).data[prev].next = (*L).data[hapus].next;					
			(*L).data[(*L).data[hapus].next].prev = prev;					
		}
		
		(*L).data[hapus].prev = -2;		//penghapusan elemen
		(*L).data[hapus].next = -2;		//penghapusan elemen
	}
}

void delLast(list *L){
	
	if((*L).first != -1){
		
		if(countElement(*L) == 1) delFirst(L);				//jika satu elemen
		else{
			int prev = (*L).data[(*L).tail].prev;
			delAfter(prev, L);							//elemen sebelum elemen terakhir menjadi elemen terakhir
		}
	}
	else printf("list kosong\n");					//proses jika list kosong
	
}

void printElemen(list L){
	
	if(L.first != -1){
		//inisialisasi	
		int elmt = L.first;
		int i = 1;
		
		while(elmt != -1){
			
			printf("%s %d\n",L.data[elmt].elmt.tempat,L.data[elmt].elmt.berat_ikan);
			
			//iterasi
			elmt = L.data[elmt].next;
			i++;
		}			
	}
	else printf("list kosong\n");
}

void delAll(list *L){
	
	int i;
	for(i=countElement(*L);i>=1;i--) delLast(L);	
}

//prosedur untuk mencari jalan2 yang dikunjungi
void hasiljalan2(list L1,list L2){
	
	if(L2.first != -1){
		int elmt;
		int cari = L2.first;
		int awal;
		int akhir;
		int total_tangkap = 0;
		
		while(cari != -1){
			int status = 0;
			int status2 = 0;
			
			//mecari tempat awal
			elmt = L1.first;
			while(elmt != -1 && status==0){
				if(strcmp(L1.data[elmt].elmt.tempat,L2.data[cari].elmt.tempat)==0){
					awal = elmt;
					status = 1;
				}
				elmt = L1.data[elmt].next;
			}
			
			//mencari tempat akhir
			elmt = L1.first;
			while(elmt != -1 && status2==0){
				if(strcmp(L1.data[elmt].elmt.tempat,L2.data[L2.data[cari].next].elmt.tempat)==0){
					akhir = elmt;
					status2 = 1;
				}
				elmt = L1.data[elmt].next;
			}
			
			//jika awal lebih kecil dari akhir(berarti dari kanan ke kiri)
			if(awal<akhir){
				while(awal != akhir){
					printf("%s %d\n",L1.data[awal].elmt.tempat,L1.data[awal].elmt.berat_ikan);
					total_tangkap += L1.data[awal].elmt.berat_ikan;	//menjumlahkan total ikan yang didapat
					
					awal = L1.data[awal].next;//berjalan ke kanan
				}
			}else if(awal==akhir){//atau awal sama dengan akhir
				
				printf("%s %d\n",L1.data[awal].elmt.tempat,L1.data[awal].elmt.berat_ikan);
				total_tangkap += L1.data[awal].elmt.berat_ikan;//jumlahkan total ikan yang didapat
				
			}else{//jika tidak (dari kanan ke kiri)
				while(awal != akhir){
					printf("%s %d\n",L1.data[awal].elmt.tempat,L1.data[awal].elmt.berat_ikan);
					total_tangkap += L1.data[awal].elmt.berat_ikan;//jumlahkan total ikan yang didapat
					
					awal = L1.data[awal].prev;//berjalan ke kiri
				}
			}
			
			//iterasi
			awal = akhir;
			cari = L2.data[cari].next;
		}
		//total ikan yang didapat
		printf("%d\n",total_tangkap);
	}
	
}