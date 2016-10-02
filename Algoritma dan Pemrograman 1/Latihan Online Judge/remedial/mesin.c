#include "header.h"

//fungsi tambah
tes tambah(int m, char kata[m][100]){

	tes hasil;
	
	/*jika bertemu salah satu angka di dalam string, maka semuanya dijumlahkan sesuai angka tersebut
		di setiap indeksnya
	*/
	int i,j;
	for(i=0;i<m;i++){
		hasil.digit[i]=0;
		for(j=0;j<strlen(kata[i]);j++){
			if(kata[i][j]>='0' && kata[i][j]<='9'){
				hasil.digit[i]=hasil.digit[i]+(kata[i][j]-'0');
			}
		}
	}
	
	//melempar hasil
	return hasil;
}

//fungsi maximal
int maximal(int m, tes hasil){
	
	//lalu mencari nilai maximal
	int max=hasil.digit[0],i;
	
	for(i=0;i<m;i++){
		if(max<hasil.digit[i]){//jika max lebih kecil dari hasil.digit di setiap indeks
			max=hasil.digit[i];//maka nilai max sesuai dengan nilai hasil.digit di dalam indeks tersebut
		}
	}
	
	//melempar nilai max
	return max;
}	


//prosedur untuk mencari valid dan tidak valid
void validtidakvalid(int n, int angka[n],int m, char kata[m][100],tes hasil,int max){
	
	int i,j,status=0;
	for(j=0;j<m;j++){
		//mengecek apakah ada string yang hasil angkanya maximal sama dengan array of integer 
		for(i=0;i<n;i++){
			if(status==0){//jika statusnya sama dengan 0
				if(hasil.digit[j]==angka[i]){//jika hasil.digit di setiap indeks sama dengan angka di setiap angka di setiap indeks
					if(hasil.digit[j]==max){//maka jika hasil.digit di setiap indeks sama dengan nilai maximal
						printf("%s %d\n",kata[j],angka[i]);//maka tampilkan string dengan jumlah angka yang terbesar
						status=1;//dengan status=1(berarti ada)
					}
				}
			}
		}
	}
	
	if(status==0){//jika statusnya 0(berarti tidak ada)
		printf("tidak valid\n");//maka tidak valid
	}
	
	
}