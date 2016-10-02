#include "header.h"

//memproses perubahan matriks
nama proses(int b,int k,nama apa,int ubah,char perubahan[ubah][100],int x[ubah],int y[ubah]){
	
	int i,j,l,m;//variabel
	nama ini=apa;//mengcopy semua nilai matriks yang ada di dalam matriks bungkusan apa
	
	for(i=0;i<ubah;i++){
		if(strcmp(perubahan[i],"tukar")==0){//jika string perubahan sama dengan tukar
			for(j=0;j<k;j++){//maka baris x akan ditukar dengan baris y
				ini.matriks[y[i]][j]=ini.matriks2[x[i]][j];//lalu x dan y saling bertukar dengan cara mengcopy matriks1 ke matriks 2
				ini.matriks[x[i]][j]=ini.matriks2[y[i]][j];
			}
			for(l=0;l<b;l++){
				for(m=0;m<k;m++){
					ini.matriks2[l][m]=ini.matriks[l][m];//lalu dicopy lagi secara keseluruhan
				}
			}
		}else if(strcmp(perubahan[i],"kanan")==0){//jika ke kanan
			while(y[i]>k){//maka prosesnya sama seperti melakukan perubahan ke kiri hanya beda lawan arah saja
				y[i]--;
			}
			for(j=0;j<y[i];j++){
				for(l=0;l<k;l++){
					if(l-1<0){
						ini.matriks[x[i]][l]=ini.matriks2[x[i]][k-1];
					}else{
						ini.matriks[x[i]][l]=ini.matriks2[x[i]][l-1];
					}
				}
				for(l=0;l<b;l++){
					for(m=0;m<k;m++){
						ini.matriks2[l][m]=ini.matriks[l][m];
					}
				}
			}
		}else if(strcmp(perubahan[i],"kiri")==0){//jika string perubahan sama dengan kiri
			while(y[i]>k){//maka akan melakukan perulangan di baris x sebanyak y kali
				y[i]--;
			}
			for(j=0;j<y[i];j++){//melakukan perulangan pemutaran dari kanan ke kiri
				for(l=0;l<k;l++){
					if(l+1<k){//jika l+1 kurang dari banyaknya kolom
						ini.matriks[x[i]][l]=ini.matriks2[x[i]][l+1];//maka kolom tersebut akan ditambah 1
					}else{//jika tidak
						ini.matriks[x[i]][l]=ini.matriks2[x[i]][0];//maka matriks2 di kolom indeks 0 tetap(agar tidak terjadi perubahan nilai matriks)
					}
				}
				for(l=0;l<b;l++){
					for(m=0;m<k;m++){
						ini.matriks2[l][m]=ini.matriks[l][m];//lalu melakukan pengcopyan matriks seperti pada "tukar"
					}
				}
			}
		}	
	}
	
	return ini;//mengembalikan nilai ke main
	
}

//menampilkan isi matriks
void tampil(nama hasil,int b,int k){
	
	int i,j;
	
	
	for(i=0;i<b;i++){
		for(j=0;j<k;j++){
			printf("%d",hasil.matriks2[i][j]);
			if(j<k-1){//untuk menyela spaSI diantara angka-angka
				printf(" ");
			}
		}
		printf("\n");
	}
	
}