#include "header.h"

//prosedur sorting
void sorting(){
	
	int i,tukar;
	mahasiswa temp;
	
	do{
		tukar=0;
		
		for(i=0;i<n-1;i++){
			//jika nim yang pertama lebih besar dari nim yang selanjutnya
			if(strcmp(data[i].nim,data[i+1].nim)==1){
				//maka terjadi proses pertukaran
				temp=data[i];
				data[i]=data[i+1];
				data[i+1]=temp;
				tukar=1;
			}
		}
		
	}while(tukar==1);
	
}

//prosedur baca file
void readFile(){
	
	n = 0;
	mahasiswa tmp;
	FILE *fdata;
	fdata = fopen("data/mahasiswa.dat","r");		//baca file dengan mode read
	
	do{
		fscanf(fdata,"%s %s %s",&tmp.nim, &tmp.nama, &tmp.kelas);				//membaca file 
		if(strcmp(tmp.nim,"##")!=0 &&strcmp(tmp.nama,"##")!=0 && strcmp(tmp.kelas,"##")!=0){//jika data tidak sama dengan dummy
			data[n]=tmp;//maka semua data tmp di copykan ke variabel data sebanyak n
			n++;//n terus bertambah
		}
	}while(strcmp(tmp.nim,"##")!=0 &&strcmp(tmp.nama,"##")!=0 && strcmp(tmp.kelas,"##")!=0);//berulang selama tidak ada dummy
	fclose(fdata);//tutup file
	
}

//prosedur write file
void writeFile(){
	int i;
	
	FILE *fdata;
	fdata = fopen("data/mahasiswa.dat","w");		//file dalam mode write
	
	for(i=0;i<n;i++){
		fprintf(fdata,"%s %s %s\n", data[i].nim, data[i].nama, data[i].kelas);//mencetak ke dalam file 
	}
	fprintf(fdata,"## ## ##\n");		//menambah dummy di akhir
	
	fclose(fdata);//tutup file
	
}

//prosedur menampilkan data ke dalam tabel
void tampil_tabel(){
	int i;
	printf("Isi tabel saat ini : \n");
	printf("--------------------------------------\n");
	printf("|%-10s|%-16s|%-8s|\n","NIM","Nama","Kelas");
	printf("--------------------------------------\n");
	for(i=0;i<n;i++){
	printf("|%-10s|%-16s|%-8s|\n",data[i].nim,data[i].nama,data[i].kelas);
	}
	printf("--------------------------------------\n");
}


//prosedur ubah data
void updateData(char nim[15]){
	readFile();					//baca file
	int i,j;
	int status=0;
	i=0;
	char nama[25];char kelas[15];
	while(i<n && status==0){
		if(strcmp(data[i].nim,nim)==0){//jika nim masukan sama dengan nim di daya
			status=1;//maka status 1
			
			//menampilkan isi data berdasarkan nim
			printf("Data ditemukan\n");
			printf("------Data Awal-------\n");
			printf("Nama\t: %s\n", data[i].nama);
			printf("Kelas\t: %s\n", data[i].kelas);
			printf("----------------------\n");
			
			//mengubah data
			printf("Masukan nama baru\t: ");
			scanf("%s",&nama);
			printf("Masukan kelas baru\t: ");
			scanf("%s",&kelas);
			
			//mengcopy data ke dalam file
			strcpy(data[i].nama, nama);
			strcpy(data[i].kelas, kelas);
			printf("Data berhasil diupdate\n");
			writeFile();//lalu simpan writeFile
		}else{//jika tidak ada
			i++;//maka i terus bertambah selama belum ketemu
		}
	}
	
	if(status==0){	//jika statusnya 0
		printf("Data tidak ditemukan");//maka data tidak ditemukan
	}
	
}

//prosedur hapus data
void deleteData(char nim[15]){
	
	readFile();						//baca file
	int i,j;
	int status = 0;
	i=0;
	char hapus[10];
	
	while(i<n && status==0){
		if(strcmp(data[i].nim,nim)==0){		//jika nim inputan dengan nim di data sama
			status=1;//maka status 1
			printf("Data ditemukan, Yakin hapus data? ya/tidak\n");
			scanf("%s",&hapus);//inputan konfirmasi jika ingin dihapus/tidak
			if(strcmp(hapus,"ya")==0){//jika iya
				for(j=i;j<n;j++){
					data[j] = data [j+1];//maka data geser kedepan
				}n--;//jumlah n terus berkurang
				writeFile();//lalu simpan dalam file
			}
		}else{//jika tidak
			i++;//maa iterasi terus bertambah jika data belum ditemukan
		}
	}
	
	if(status==0){//jika statusnya 0
		printf("Data tidak ditemukan\n");//maka data tidak ditemukan
	}
	
}

//fungsi cari data
int findData(char nim[15]){
	int status = 0;
	int i = 0;
	
	readFile();		//baca file
	
	while(status==0 && i<n){
		if(strcmp(data[i].nim,nim)==0){//jika nim masukan sama dengan nim di data
			status=1;//maka status 1
		}else{//jika tidak 
			i++;//iterasi terus bertambah jika data belum ditemukan
		}
	}
	
	return status;//lempar status;
}

//prosedur input data
void insertData(mahasiswa masukan){
	int i=0;
	int status = findData(masukan.nim);//pertama cari ada tidaknya nim tersebut
	
	if(status==0){//jika statusnya 0(berarti tidak ada)
		data[n]=masukan;//maka data akan dicopy oleh masukan
		n++;//indeksnya bertambah
		writeFile();//lalu simpan di dalam file
		printf("data berhasil ditambahkan\n");
	}else{//jika tidak
		//berarti nim tersebut ada di dalam data
		printf("NIM sudah terdaftarkan, data gagal ditambahkan\n");
	}
}