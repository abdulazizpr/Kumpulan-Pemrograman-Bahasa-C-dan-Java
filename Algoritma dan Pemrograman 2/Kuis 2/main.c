#include "header.h"

/*
Saya Abdul Aziz Priatna(1307123) tidak melakukan kecurangan seperti yang telah dispesifikasikan pada 
mata kuliah Algoritma dan Pemograman 2 dalam mengerjakan Kuis 2, jika saya melakukan kecurangan
maka Allah/Tuhan adalah saksi saya, dan saya bersedia menerima hukumanNya. Aamiin.
*/

int main(){
	
	//variabel untuk penentuan urut dan tidak urut
	char pilihanurut1[100];
	char pilihanurut2[100];
	
	//variabel untuk mencari huruf yang akan dijumlahkan
	char cari1;
	char cari2;
	
	int n,m,i,j,angkacari;
	scanf("%s",&pilihanurut1);//inputan urut atau tidak urut(td/t) pertama
	scanf(" %c",&cari1);//inputan huruf yang dicari pertama
	scanf("%d",&n);//banyaknya indeks pertama
	
	char kata1[n][100];
	for(i=0;i<n;i++){
		scanf("%s",&kata1[i]);//inputan banyaknya kata pertama
	}
	
	scanf("%s",&pilihanurut2);//inputan urut atau tidak urut(td/t) kedua
	scanf(" %c",&cari2);//inputan huruf yang dicari kedua
	scanf("%d",&m);//banyaknya indeks kedua
	
	char kata2[m][100];
	for(i=0;i<m;i++){
		scanf("%s",&kata2[i]);//inputan banyaknya kata pertama
	}
	
	scanf("%d",&angkacari);//mencari jumlah angka yang dicari
	bungkusan jumlahhuruf1;//deklarasi untuk menampung jumlahhuruf pertama
	bungkusan jumlahhuruf2;//deklarasi untuk menampung jumlahhuruf kedua
	
	jumlahhuruf1=jumlahhuruf(n,kata1,cari1);//menampung dari fungsi jumlahhuruf
	jumlahhuruf2=jumlahhuruf(m,kata2,cari2);
	
	//inisialisasi
	int ketemu1=0;
	int ketemu2=0;
	
	//cek pilihan pertama
	if(strcmp(pilihanurut1,"td")==0){//jika tidak teruruut
		ketemu1=sequential_search(jumlahhuruf1,n,angkacari);//maka searching menggunakan sequential_search
	}else if(strcmp(pilihanurut1,"t")==0){//atau jika terurut
		ketemu1=binary_search(jumlahhuruf1,n,angkacari);//maka searching menggunakan binary_search
	}
	
	//cek pilihan kedua
	if(strcmp(pilihanurut2,"td")==0){//jika tidak terurut
		ketemu2=sequential_search(jumlahhuruf2,m,angkacari);//maka searching menggunakan sequential_search
	}else if(strcmp(pilihanurut2,"t")==0){//atau jika terurut
		ketemu2=binary_search(jumlahhuruf2,m,angkacari);//maka searching menggunakan binary_search
	}
	
	
	//jika ketemu maka valid
	if(ketemu1==1){
		printf("valid\n");
	}else{//jika tidak maka tidak valid
		printf("tidak valid\n");
	}
	
	//jika ketemu maka valid
	if(ketemu2==1){
		printf("valid\n");
	}else{//jika tidak maka tidak valid
		printf("tidak valid\n");
	}
	
	return 0;
}