#include "header.h"

void createList(list *L){ (*L).first = NULL;}

int countElement(list L){
	
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

void addFirst(char nama_sales[],int hasil_penjualan,list *L){
	
	elemen *baru;
	baru = (elemen *) malloc (sizeof (elemen));
	strcpy(baru->elmt.nama_sales, nama_sales);
	baru->elmt.hasil_penjualan = hasil_penjualan;

	if((*L).first == NULL) baru->next = NULL;
	else baru->next = (*L).first; 
	
	(*L).first = baru;
	baru = NULL;
	
}

void addAfter(elemen *prev,char nama_sales[],int hasil_penjualan,list *L){
	
	elemen *baru;
	baru = (elemen *) malloc (sizeof (elemen));
	strcpy(baru->elmt.nama_sales, nama_sales);
	baru->elmt.hasil_penjualan = hasil_penjualan;
	
	if(prev->next == NULL) baru->next = NULL;
	else baru->next = prev->next;
	
	prev->next = baru;
	baru = NULL;

}

void addLast(char nama_sales[],int hasil_penjualan,list *L){
	
	//jika list adalah list kosong
	if((*L).first == NULL) addFirst(nama_sales,hasil_penjualan,L);
	else{	
		//jika list tidak kosong
		//mencari elemen terlast list
		
		elemen *prev = (*L).first;
		//mencari elemen terlast list
		while(prev->next != NULL) prev = prev->next; //iterasi
		
		addAfter(prev, nama_sales, hasil_penjualan, L);
	}
	
}

void delFirst(list *L){
	
	if((*L).first != NULL){			//jika bukan list kosong
		elemen *hapus = (*L).first;
		
		if(countElement(*L)==1) (*L).first = NULL;
		else {
			(*L).first = (*L).first->next; 
			hapus->next = NULL;
		}
		
		free(hapus);
	}
	
}

void delAfter(elemen *prev,list *L){
	
	elemen *hapus = prev->next;
	if(hapus != NULL){
		if(hapus->next == NULL) prev->next = NULL;
		else{ 
			prev->next = hapus->next;
			hapus->next = NULL;
		}	
		free(hapus);
	}
	
}

void delLast(list *L){			
	
	if((*L).first != NULL){
		//jika list tidak list kosong
		if(countElement(*L) == 1) delFirst(L);	//list hanya satu elemen
		else{
			//mencari elemen terlast
			elemen *last = (*L).first;
			elemen *prev;
			
			while(last->next != NULL){
				//iterasi
				prev = last;
				last = last->next;
			}
			
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
	
			printf("%s %d\n",elmt->elmt.nama_sales,elmt->elmt.hasil_penjualan);
			//iterasi
			elmt = elmt->next;
		}
	}
	//proses jika list kosong
	else printf("List Kosong\n");
}

void delAll(list *L){
	
	if(countElement(*L) != 0){
		int i;
		for(i=countElement(*L);i>=1;i--) delLast(L);
	}
	
}

void sort(list *L){
	
	if((*L).first != NULL){
		
		int tukar;
		elemen *prev;
		elemen *now;
		elemen *next;
			
		do{
			prev = NULL;			//inisialisasi keadaan awal
			now = (*L).first;		//elemen pertama menjadi yang sekarang
			next = now->next;		//elemen selanjutnya menjadi elemen yang sekarang itu mempunyai elemen selanjutnya
			
			tukar = 0;		//inisialisasi pertukaran
			
			while(next != NULL){
				//jika elemen hasil penjualan yang sekarang kurang dari hasil_penjualan selanjutnya
				if(now->elmt.hasil_penjualan < next->elmt.hasil_penjualan){
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

int bonus(int hasil_penjualan){
	
	int hasil;
	if(hasil_penjualan>=100000 && hasil_penjualan<200000){//jika hasil penjual lebih/sama dengan 100000 && hasil_penjualan kurang dari 200000
		hasil = (10*hasil_penjualan)/100; 
	}else if(hasil_penjualan>=200000 && hasil_penjualan<300000){//jika hasil penjual lebih/sama dengan 200000 && hasil_penjualan kurang dari 300000  
		hasil = (15*hasil_penjualan)/100; 
	}else if(hasil_penjualan>=300000){//jika hasil penjual lebih/sama dengan 300000
		hasil = (20*hasil_penjualan)/100; 
	}else{//jika tidak ada
		hasil = 0;	//maka hasil sama dengan 0
	}
	
	return hasil;
}


void kumulatif_senior(list *L){
	
	if((*L).first != NULL){
		elemen *elmt = (*L).first;
		int hasil_bonus;
		
		while(elmt != NULL){
			hasil_bonus = bonus(elmt->elmt.hasil_penjualan);	//ambil hasil bonus dari fungsi bonus
			elmt->elmt.hasil_penjualan = elmt->elmt.hasil_penjualan + hasil_bonus;	//kalkulasikan dengan penghasila sebelumnya
			elmt = elmt->next;		//iterasi
		}
		
	}
	
}

void add_sort_junior(char nama_sales[],int hasil_penjualan,list *L){
	
	if((*L).first != NULL){
		if((*L).first->elmt.hasil_penjualan < hasil_penjualan) addFirst(nama_sales,hasil_penjualan,L);	//jika data awal hasil penjualan awal kurang dari hasil_penjualan yang baru maka lakukan addFirst;
		else{//jika tida
			elemen *awal = (*L).first;
			elemen *prev;	//untuk menampung index sebelumnya
			int status = 0;
		
			while(awal->next != NULL && status==0){
				if(awal->next->elmt.hasil_penjualan < hasil_penjualan){ //jika data hasil penjualan selanjutnya kurang dari hasil_penjualan yang baru maka lakukan addFirst;
					prev = awal; //maka pointer sebelumnya sama dengan pointer awal;
					status = 1;
				}
				awal = awal->next;
			}
			
			//jika status 1 maka lakukan addAfter dengan mengambil pointer sebelumnya
			if(status==1) addAfter(prev,nama_sales,hasil_penjualan,L);
		}
		
	}
	
}

void hapus_sales(char hapus[],list *L){
	
	if((*L).first != NULL){
		if(strcmp((*L).first->elmt.nama_sales,hapus)==0) delFirst(L);	//jika data diawal sama dengan data yang akan dihapus maka lakukan delFirst;
		else{//jika tidak cari index
			elemen *awal = (*L).first;			//inisialisasi
			elemen *prev;						//untuk menampung elemen sebelumnya
			
			int status = 0;						//inisialisasi jika tidak berhenti
			while(awal->next != NULL && status==0){	//berulang selama awal yg selanjutnya tidak null dan status masih 0
				if(strcmp(awal->next->elmt.nama_sales,hapus)==0){	//jika data setelah awal sama dengan data yang akan dihapus
					prev = awal;	//maka elemen awal menjadi elemen sebelumnya
					status = 1;		//status 1(berhenti)
				}
				awal = awal->next;	//iterasi
			}
			
			//jika status 1 maka delAfter dengan elemen sebelumnya
			if(status==1) delAfter(prev,L);
		}
	}
	
}

