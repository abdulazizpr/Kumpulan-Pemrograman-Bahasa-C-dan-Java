#include "header.h"

int main(){
	
	stack ozin,iip,ahmad,fitri,buang;//deklarasi stack
	
	//inisialisasi
	createEmpty(&ozin);
	createEmpty(&iip);
	createEmpty(&ahmad);
	createEmpty(&fitri);
	createEmpty(&buang);
	
	int n,i;
	scanf("%d",&n);//banyaknya inputan
	
	int pemain,angka,prioritas;
	char kartu[100];
	for(i=0;i<n;i++){
		scanf("%d %d %s",&pemain,&angka,&kartu);//input pemain, angka dan kartu
		
		if(strcmp(kartu,"hati")==0){//jika kartunya hati
			prioritas = 4;//maka prioritaskan ke 4
		}else if(strcmp(kartu,"tempe")==0){//jika kartunya tempe
			prioritas = 3;//maka prioritaskan ke 3
		}else if(strcmp(kartu,"keriting")==0){//jika kartunya keriting
			prioritas = 2;//maka prioritaskan ke 2
		}else if(strcmp(kartu,"sekop")==0){//jika kartunya sekop
			prioritas = 1;//maka prioritaskan ke 1
		}
		
		if(pemain==1){//jika pemain 1
			//jika angkanya antara 1 sampai 10(karena no kartu hanya sampai 10)
			if(angka>=1 && angka <=10) push(angka,kartu,prioritas,&ozin);//maka push ke stack ozin
		}else if(pemain==2){//jika pemain 2
			//jika angkanya antara 1 sampai 10(karena no kartu hanya sampai 10)
			if(angka>=1 && angka <=10) push(angka,kartu,prioritas,&iip);//maka push ke stack iip
		}else if(angka>=1 && pemain==3){//jika pemain 3
			//jika angkanya antara 1 sampai 10(karena no kartu hanya sampai 10)
			if(angka>=1 && angka <=10) push(angka,kartu,prioritas,&ahmad);//maka push ke ahmad
		}else if(pemain==4){//jika pemain 4
			//jika angkanya antara 1 sampai 10(karena no kartu hanya sampai 10)
			if(angka>=1 && angka <=10) push(angka,kartu,prioritas,&fitri);//maka push ke fitri
		}
	}
	
	//lalu buang kartunyna berdasarkan nilai terkecil
	buang_kartu(&ozin,&iip,&ahmad,&fitri,&buang);
	
	//lalu print hasil pembuangannya
	printStack(buang);
	
	return 0;
}