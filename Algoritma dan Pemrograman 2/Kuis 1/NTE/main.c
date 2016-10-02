#include "header.h"

int main(){
	
	int i,m,n;
	scanf("%d %d",&m,&n);//ordo matriks
	
	isi angka[m*n];//deklarasi matriks masukan
	
	int hasil[m][n];//matriks keluaran
	
	for(i=0;i<m*n;i++){
		scanf("%d %d %d",&angka[i].a,&angka[i].b,&angka[i].c);
	}
	
	caritengah(m,n,angka,hasil);
	
	printhasil(m,n,hasil);
	
	
	return 0;
}