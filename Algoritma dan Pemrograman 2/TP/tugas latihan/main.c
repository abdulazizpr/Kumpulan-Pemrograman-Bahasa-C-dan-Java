#include "header.h"

/*
Saya Abdul Aziz Priatna(1307123) tidak melakukan kecurangan seperti yang telah dispesifikasikan pada 
mata kuliah Algoritma dan Pemograman 2 dalam mengerjakan TP8/Tugas Latihan, jika saya melakukan kecurangan
maka Allah/Tuhan adalah saksi saya, dan saya bersedia menerima hukumanNya. Aamiin.
*/

int main(){
	
	readFile();															//pertama baca file dulu
	sorting();															//kemudian di sorting agar tampilannya terurut
	int menu;															//variabel untuk masukan menu
	
	atas:																//atas digunakan dengan menggunakan goto
	system("cls");														//pembersihan layar
	tampil_tabel();														//menampilkan semua data dengan desain tabel
	
	//tampilan menu
	printf("Pilihan menu : \n");										
	printf("\t1. Cari data\n");
	printf("\t2. Insert data\n");
	printf("\t3. Ubah data\n");
	printf("\t4. Hapus data\n");
	printf("\t5. Keluar\n");
	printf("Masukan pilihan : ");
	scanf("%d",&menu);//inputan menu
	
	char nim[100];
	switch(menu){
		case 1 : {		//mencari data
			
			printf("Masukan nim\t: ");
			scanf("%s",&nim);//masukan nim
			int status = findData(nim);//memanggil fungsi findData untuk mencari ada tidaknya data
			
			if(status==1){//jika statusnya 1
				printf("data ditemukan\n");//maka data ditemukan
			}else{//jika tidak
				printf("data tidak ditemukan\n");//maka data tidak ditemukan
			}
			system("pause");//menahan tampilan dengan system pause
			goto atas;//lalu kembali ke atas
			
		}break;
		
		case 2: {		//menginput data
			mahasiswa input;//deklarasi bungkusan input
			printf("Masukan nim\t: ");
			scanf("%s",&input.nim);				//inputan nim
			printf("Masukan nama\t: ");
			scanf("%s",&input.nama);			//inputan nama
			printf("Masukan kelas\t: ");
			scanf("%s",&input.kelas);			//inputan kelas
			insertData(input);					//masuk ke prosedur inputData untuk dimasukan ke dalam sequential file
			goto atas;							//kembali ke atas
		}break;
		
		case 3 :{		//mengubah data
			printf("Masukan nim\t: ");
			scanf("%s",&nim);					//inputan nim
			updateData(nim);					//masuk ke prosedur updateData untuk diubah datanya
			goto atas;
		}break;
		
		case 4 : {		//menghapus data
			printf("Masukan nim\t: ");
			scanf("%s",&nim);					//inputan nim
			deleteData(nim);					//masuk ke prosedur deleteData untuk menghapus data
			goto atas;
		}
		
		case 5 : system("exit");				//keluar
		break;
		
		default : {		//jika inputan selain di atas
			printf("Maaf masukan tidak ada\n");
			system("pause");
			goto atas;
		}
	}
	
}