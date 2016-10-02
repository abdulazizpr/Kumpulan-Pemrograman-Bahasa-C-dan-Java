#include "header.h"

//ini halaman utama
int main(){
	
		int menu;
		char pilihan;
		system("cls");//membersihkan layar
		setcolor(15);
		printf("-------------------------------------------------------------------------\n");
		printf("|\t\t\tTUGAS MASA DEPAN ALPRO 2\t\t\t|\n");
		printf("|\t\tCreated by : Abdul Aziz Priatna(1307123)\t\t|\n");
		printf("-------------------------------------------------------------------------\n");
			//tampilan menu
			printf("Menu :\n");
			printf("1. Operasi rekaman pola\n");
			printf("2. Simulasi Animasi\n");
			printf("3. Keluar\n");
			printf("Masukan menu : ");
		
		scanf("%d",&menu);//inputan pilihan menu
		
		
		switch(menu){
			case 1  : rekaman_pola();//ke halaman rekaman pola
			break;
			
			case 2  : inputpolaanimasi();//ke halaman input pola animasi
			break;
			
			case 3  : system("exit");//close program
			break;
			
			default : {
				//tampilan error handling
				printf("\n");
				printf("Maaf pilihan yang anda masukan tidak ada\n\n");
				printf("Kembali ke menu utama (y/t) : ");
				scanf(" %c",&pilihan);
				if(pilihan=='y'||pilihan=='Y'){
					main();
				}else{
					system("exit");
				}
			}
			break;		
		}
		
	return 0;
}

////////////////////////////////////////halaman rekaman pola////////////////////////////////////////////////////
//ini halaman rekaman pola
void rekaman_pola(){	
	
	baca_data();
	system("cls");
	tampil_tabel();//memanggil prosedur tampil tabel
	
	//tampilan menu rekaman pola
	printf("Menu operasi : \n");
	printf("\t1. Mengisi\n");
	printf("\t2. Menghapus\n");
	printf("\t3. Kembali ke menu utama\n");
	printf("Masukan menu : ");
	
	//inputan pilihan
	char pilihan;
	int menu;
	scanf("%d",&menu);
	printf("\n");
	
	//menggunakan switch case
	switch(menu){
		case 1 : {
			//insert data
			bungkusan baru;
			printf("nama\t: ");
			scanf("%s",&baru.nama_pola);//insert nama pola
			printf("x\t: ");
			scanf("%d",&baru.x);//insert koordinat x
			printf("y\t: ");
			scanf("%d",&baru.y);//insert koordinat y
			int status=cari(baru);
			
			if(baru.x<=2 && baru.y<=2){//jika koordinat kurang atau sama dengan 2
				if(status==1){//jika statusnya 1
					printf("Maaf koordinat x = %d dan y = %d di %s sudah ada\n\n",baru.x,baru.y,baru.nama_pola);
					printf("Apakah ingin melanjutkannya (y/t): ");
					scanf(" %c",&pilihan);//pilihan konfirmasi
					if(pilihan=='y'||pilihan=='Y'){
						rekaman_pola();
					}else{
						system("exit");
					}
				}else{
					insert(baru);//masuk ke prosedur insert
					simpan();//lalu simpan data di prosedur simpan dengan sequential file
					rekaman_pola();//lalu refresh ke halaman rekaman pola
				}
			}else{//jika tidak
				printf("Maaf koordinat yg di inputkan hanya bisa sampai 2\n\n",baru.x,baru.y,baru.nama_pola);
				printf("Apakah ingin melanjutkannya (y/t): ");
				scanf(" %c",&pilihan);//pilihan konfirmasi
				if(pilihan=='y'||pilihan=='Y'){
					rekaman_pola();
				}else{
					system("exit");
				}
			}	
		}break;
	
		case 2 : {
			//hapus data
			char nama_pola[100];
			printf("nama\t: ");
			scanf("%s",&nama_pola);//input nama pola yang akan di hapus
			hapus(nama_pola);//masuk ke prosedur hapus
			simpan();//lalu simpan data di prosedur simpan dengan sequential file
			rekaman_pola();//lalu refresh ke halaman rekaman pola
		}break;
	
		case 3 :main();//kembali ke menu utama
		break;
	
		default : {//jika pilihan salah
			printf("Maaf pilihan tidak adak\n\n");
			printf("Apakah ingin melanjutkannya (y/t): ");
				scanf(" %c",&pilihan);//pilihan konfirmasi
				if(pilihan=='y'||pilihan=='Y'){
					rekaman_pola();
				}else{
					system("exit");
				}
		}
		break;		
	}
	
}

////////////////////////////////////////halaman rekaman pola////////////////////////////////////////////////////

/////////////////////////////////////Halaman Simulasi Animasi///////////////////////////////////////////////////

//halaman pola animasi
void inputpolaanimasi(){
	
	int tebal,i,status=0,x=1,j;
	baca_data();
	char pita[999];
	char hasil[100][100];
	
	system("cls");
	printf("Kalimat pola\t: ");scanf(" %998[^\n]s",&pita);//input kalimat
	printf("Ketebalan\t: ");scanf("%d",&tebal);//input tebal
	
	//memulai start kata
	STARTKATA(pita);
	for(i=0;i<n;i++){
		if(strcmp(GETCKATA(),pola[i].nama_pola)==0){//jika nama pola sama dengan kata yang ada dalam kalimat pita
			if(strcmp(GETCKATA(),pola[i+1].nama_pola)!=0){//jika nama pola setelahnya tidak sama dengan kata yang ada dalam kalimat pita(jadi setelahnya tidak di hitung)
				strcpy(hasil[x],GETCKATA());//maka masukan kata yang di dapat ke dalam hasil
				x++;//x terus bertambah
			}
		}
	}
	
	//berulang selama tidak eop
	while(EOPKATA(pita)==0){
		INCKATA(pita);//maju satu kata
			for(i=0;i<n;i++){
				if(strcmp(GETCKATA(),pola[i].nama_pola)==0){//jika nama pola sama dengan kata yang ada dalam kalimat pita
					if(strcmp(GETCKATA(),pola[i+1].nama_pola)!=0){{//jika nama pola setelahnya tidak sama dengan kata yang ada dalam kalimat pita(jadi setelahnya tidak di hitung)
						strcpy(hasil[x],GETCKATA());
						x++;//x terus bertambah
					}
				}
			}
		}
	}
	
	system("cls");//menggunakan system cls untuk membersihkan layar agar bisa tampil pola per baris sesuai inputan pita yang didapat
	for(i=1;i<x;i++){//mulai dari indeks 1 karena indeks awal isinya spasi jadi tidak ditampilkan
		simulasianimasi(hasil[i],tebal);//masuk ke prosedur simulasianimasi setiap indeks
		system("cls");//bersihkan layar
	}
	
	main();	
}
/////////////////////////////////////Halaman Simulasi Animasi///////////////////////////////////////////////////


