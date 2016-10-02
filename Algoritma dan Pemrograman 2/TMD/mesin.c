#include "header.h"

//time untuk animasi
void wait(float x) {
    time_t start;
    time_t current;
    time(&start);
    do
        time(&current);
    while (difftime(current,start) < x);
}

//prosedur warna
void setcolor(unsigned short color){ //fungsi untuk pemberian warna
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE); //membuat objek hCon
	SetConsoleTextAttribute(hCon,color); //program untuk merubah warna
}

/////////////////////////////////////////////mesin crud/////////////////////////////////////////////////////////

//untuk baca file
void baca_data(){
	int i;
	n=0;
	
	FILE* fsumber;
	fsumber=fopen("tpola.txt","r");			//cara akses membuka file nya
	
	//proses read file
	fscanf(fsumber,"%s %d %d\n",&pola[n].nama_pola,&pola[n].x,&pola[n].y);		//cara readnya
	
	
	//di cek apakah dummy atau tidak
	while(strcmp(pola[n].nama_pola,"##")!=0){
		n++;
		fscanf(fsumber,"%s %d %d\n",&pola[n].nama_pola,&pola[n].x,&pola[n].y);
	}
	
	fclose(fsumber);  //cara menutup akses file
}

//prosedur menampilkan tabel
void tampil_tabel(){
	
	int i,j,l=0,p=0;
	printf("Isi pola saat ini : \n");
	printf("---------------------------------\n");
	if(n==0){//jika datanya kosong
		printf("|\tMaaf data kosong\t|\n");//maka menampilkan output ini
	}else{//jika tidak
		printf("|nama\t\t|x\t|y\t|\n");//maka tampilkan semua yang ada ke dalam tabel
		printf("---------------------------------\n");
		for(i=0;i<n;i++){
			printf("|%s\t\t|%d\t|%d\t|\n",pola[i].nama_pola,pola[i].x,pola[i].y);
		}
	}
	printf("---------------------------------\n");
	
} 

//prosedur insert data
void insert(bungkusan baru){
	
	if(strcmp(baru.nama_pola,pola[0].nama_pola) < 0){//jika perbandingannya kurang dari 0
		//rekaman baru didepan
		//geser semua isi array kebelakang
		int i;
		for(i=n-1;i>=0;i--){
			pola[i+1]=pola[i];
		}
		
		//jumlah data bertambah
		n++;
		
		//isi data diawal
		pola[0]=baru;
		
	}else if(strcmp(baru.nama_pola,pola[n-1].nama_pola) > 0){//jika perbandingannya lebih dari 0
		//rekaman baru dibelakang
		strcpy(pola[n].nama_pola,baru.nama_pola);
		pola[n].x=baru.x;
		pola[n].y=baru.y;
		n++;
	}else{//jika tidak
		//rekaman baru ditengah
		int i = 0;
		int stop = 0;//untuk mencari indeksnya
		
		//cari posisi
		while(i<n && stop == 0){
			if(strcmp(pola[i].nama_pola, baru.nama_pola) > 0){
				stop = 1;
			}else{
				i++;
			}	
		}
		
		//geser data
		int j;
		for(j=n-1;j>=i;j--){
			pola[j+1]=pola[j];
		}
		
		//masukkan data ke indeks i
		pola[i]=baru;
		n++;
	}
}

//fungsi pencarian
int cari(bungkusan baru){
	int i=0,x=0;
	int status = 0;
	while(status==0 && i<n){//jika ada nama pola yang sama dan koordinat x dan y sudah ada
		if(strcmp(baru.nama_pola,pola[i].nama_pola)==0 && baru.x==pola[i].x && baru.y==pola[i].y){
			status=1;//maka status sama dengan 1(ketemu)
		}else{//jika tidak
			i++;//maka iterasi sampai ketemu
		}
	}
	
	return status;	//lempar nilai status
}

//prosedur delete
void hapus(char kata[]){
	
	//variabel
	int i=0,x=0,j;
	int status = 0;
	int index;
	char pilih;
	
	//berulang jika i lebih kecil dari n
	while(i<n){
		if(strcmp(kata,pola[i].nama_pola)==0){//jika kata sama dengan di data
			if(status==0){//jika statusnya 0
				status=1;//maka statusnya berubah menjadi 1
				printf("Anda yakin ingin menghapus data %s dari tabel (y/t) : ",pola[i].nama_pola);
				scanf(" %c",&pilih);//pilihan konfirmasi
			}
			if(pilih=='y' || pilih=='Y'){//jika pilihannya itu 'y'/'Y'
				if(i==n-1){//jika ada di belakang
					n--;//maka data berkurang
				}else{//jika tidak
					//geser semua data pola ke depan
					for(j=i;j<n-1;j++){
						pola[j]=pola[j+1];
					}
					n--;//data berkurang
				}
			}else{
				rekaman_pola();
			}
		}else{//jika tidak
			i++;//maka terus mencari
		}
	}

}

//prosedur penyimpanan
void simpan(){
	int i;
	//proses penulisan file kembali
	FILE *fsumber2;
	fsumber2=fopen("tpola.txt","w");		//ini buat di write
	for(i=0;i<n;i++){
		fprintf(fsumber2,"%s %d %d\n",pola[i].nama_pola,pola[i].x,pola[i].y);
	}
	
		//jangan lupa tambahkan record dummy 
		fprintf(fsumber2,"## # #\n");
	
	fclose(fsumber2);
}

/////////////////////////////////////////////mesin crud/////////////////////////////////////////////////////////


/////////////////////////////////////////mesin kata/////////////////////////////////////////////////////////////

void STARTKATA(char pita[]){//nyalakan mesin, dan masuk satu kata
	indeks = 0;
	panjangkata = 0;
	while(pita[indeks] == ' '){
		indeks++;
	}
	while((pita[indeks] != ' ') && (pita[indeks] != '.')){
		ckata[panjangkata] = pita[indeks];
		indeks++;
		panjangkata++;
	}
	ckata[panjangkata] = '\0';
}

void RESETKATA(){//membersihkan CKATA
	panjangkata = 0;
	ckata[panjangkata] = '\0';
}

void INCKATA(char pita[]){//maju satu kata
	panjangkata = 0;
	while(pita[indeks] == ' '){
		indeks++;
	}
	while((pita[indeks] != ' ') && (pita[indeks] != '.')){
		ckata[panjangkata] = pita[indeks];
		indeks++;
		panjangkata++;
	}
	ckata[panjangkata] = '\0';
}

char* GETCKATA(){//mengambil nilai CKATA
	return ckata;
}

int GETPANJANGKATA(){//mengambil nilai panjang kata
	return panjangkata;
}

int EOPKATA(char pita[]){//lampu menyala jika ketemu titik sebagai end of process
	if(pita[indeks] == '.'){
		return 1;
	}else{
		return 0;
	}
}

/////////////////////////////////////////mesin kata/////////////////////////////////////////////////////////////

//prosedur menampilkan animasi
void simulasianimasi(char kata[],int tebal){
	int i,j,k,l;
	
	//ukuran pola matriks 3x3
	char matriks[3][3];
	
	//inisialisasi warna
	int warna=10;
	
	baca_data();
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			matriks[i][j]=' ';//inisialisasi pola matriks dengan spasi
		}
	}
	
	for(i=0;i<n;i++){
		if(strcmp(pola[i].nama_pola,kata) == 0){//jika ada kata yang sama dengan nama pola
			matriks[pola[i].y][pola[i].x] = '0';//maka pola matriks diisi 0 sesuai koordinat nama pola
		}
	}
	
	wait(1.5);//tahan selama 1,5 detik
	for(i=0;i<3;i++){
		setcolor(warna);//mewarnai font dengan setcolor 
		for(l=0;l<tebal;l++){
			printf("\t\t\t\t\t");//agar bisa ditengah
			for(j=0;j<3;j++){
				for(k=0;k<tebal;k++){
					printf("%c",matriks[i][j]);//output pola matriks
				}
			}
			printf("\n");
		}
		warna=warna+2;//warna di +2 agar tampilnya bisa berbeda beda tiap baris
		wait(1.5);
	}
	
}
