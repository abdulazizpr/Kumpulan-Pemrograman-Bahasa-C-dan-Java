#include "header.h"

void createList(list *L){
	
	(*L).first = -1;
	int i;
	
	//proses menginisialisasi isi array
	for(i=0;i<n;i++) (*L).data[i].next = -2;
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
		
		while(ketemu==0 && i<n){
			if(L.data[i].next == -2){
				hasil = i;
				ketemu = 1;
			}
			
			else i++;
		}
		
	}
	
	return hasil;
	
}

void addFirst(int pembilang,int penyebut,list *L){
	
	if(countElement(*L) < n){
		int baru = emptyElement(*L);
		
		(*L).data[baru].elmt.pembilang=pembilang;
		(*L).data[baru].elmt.penyebut=penyebut;
		
		if((*L).first == -1) (*L).data[baru].next = -1;		//jika list kosong
		else (*L).data[baru].next = (*L).first;				//jika list tidak kosong
		
		(*L).first = baru;
	}
	else printf("sudah tidak dapat ditambahkan\n");			//proses jika array penuh
	
}

void addAfter(int prev,int pembilang,int penyebut,list *L){
	
	if(countElement(*L) < n){
		int baru = emptyElement(*L);
		
		(*L).data[baru].elmt.pembilang=pembilang;
		(*L).data[baru].elmt.penyebut=penyebut;
		
		if((*L).data[prev].next == -1) (*L).data[baru].next = -1;			//jika list sebelum ditengah
		else (*L).data[baru].next = (*L).data[prev].next;					//jika list ditengah
		
		(*L).data[prev].next = baru;
	}
	else printf("sudah tidak dapat ditambahkan\n");			//proses jika array penuh
	
}

void addLast(int pembilang,int penyebut,list *L){
	
	if((*L).first == -1) addFirst(pembilang, penyebut,L);		//proses jika list masih kosong
	else{													//proses jika list telah berisi elemen	
		if(countElement(*L) < n){						//proses jika array belum penuh
			
			int prev = (*L).first;
			
			while((*L).data[prev].next != -1) prev = (*L).data[prev].next;	//iterasi
			addAfter(prev, pembilang, penyebut, L);
		}
		else printf("sudah tidak dapat ditambahkan\n");	//proses jika array penuh
	}
	
}

void delFirst(list *L){
	
	if((*L).first != -1){	
		int hapus = (*L).first;
		
		if(countElement(*L) == 1) (*L).first = -1;				//jika satu elemen
		else (*L).first = (*L).data[(*L).first].next;			//jika banyak elemen
		
		(*L).data[hapus].next = -2;	//elemen awal sebelumnya dikosongkan
	}
	else printf("list kosong\n");	
	
}

void delAfter(int prev,list *L){
	int hapus = (*L).data[prev].next;
	
	if(hapus != -1){
		if((*L).data[hapus].next == -1) (*L).data[prev].next = -1;			//jika sebelum ditengah
		else (*L).data[prev].next = (*L).data[hapus].next;					//jika ditengah
		
		(*L).data[hapus].next = -2;		//penghapusan elemen
	}
}

void delLast(list *L){
	
	if((*L).first != -1){
		
		if(countElement(*L) == 1) delFirst(L);				//jika satu elemen
		else{
			int hapus = (*L).first;
			int prev;
			
			while ((*L).data[hapus].next != -1){		//iterasi
				prev = hapus;
				hapus = (*L).data[hapus].next;
			}
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
			
			printf("%d ",L.data[elmt].elmt.pembilang);
			printf("%d\n",L.data[elmt].elmt.penyebut);
			
			//iterasi
			elmt = L.data[elmt].next;
		}			
	}
	else printf("list kosong\n");
}

void cek(int pembagi,list *L){
	
	if((*L).first != -1){
		
		int elmt = (*L).first;
		int elmt2 = (*L).first;
		int temp;
		int prev = -1;
	
	
		jumlah1 = 0;
		jumlah2 = 0;
		while(elmt != -1){
			
			if((*L).data[elmt].elmt.penyebut%pembagi==0){	
				tampung1[jumlah1] = (*L).data[elmt].elmt.pembilang;
				tampung2[jumlah1] = (*L).data[elmt].elmt.penyebut;
				jumlah1++;
			}else{
				tampung3[jumlah2] = (*L).data[elmt].elmt.pembilang;
				tampung4[jumlah2] = (*L).data[elmt].elmt.penyebut;
				jumlah2++;
			}
			
			elmt = (*L).data[elmt].next;
		}	

		delAll(L);
		int i;
		for(i=0;i<jumlah1;i++){
			addLast(tampung1[i],tampung2[i],L);
		}
		
		for(i=0;i<jumlah2;i++){
			addLast(tampung3[i],tampung4[i],L);
		}
	}
	else printf("list kosong\n");
}

void delAll(list *L){
	
	int i;
	for(i=countElement(*L);i>=1;i--){
		delLast(L);
	}
	
}