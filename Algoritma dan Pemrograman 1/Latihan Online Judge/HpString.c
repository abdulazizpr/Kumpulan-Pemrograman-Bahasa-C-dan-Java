#include <stdio.h>
#include <string.h>

/*
Saya Abdul Aziz Priatna(1307123) tidak melakukan kecurangan seperti yang telah dispesifikasikan pada mata kuliah 
Algoritma dan Pemrograman I dalam mengerjakan TP7, jika saya melakukan kecurangan maka Allah/Tuhan adalah saksi saya, 
dan saya bersedia menerima hukumanNya. Aamiin.
*/

int main(){
	
	//variabel
	int i,j,k,status=0,spasi=0,jumlahhapus;
	char kalimat[100], hapus[100];
	
	//inputan
	scanf("%s",&kalimat);//inputan kalimat
	scanf("%s",&hapus);//inputan hapus
	
	//proses
	for(i=0;i<strlen(kalimat);i++){
		//mencari kalimat yang akan di hapus
		for(j=0 ; j<strlen(kalimat) ; j++){
			jumlahhapus=0;
			if(kalimat[j]==hapus[0]){//jika kalimat sebanyak j sama dengan hapus di indeks 0
				jumlahhapus++;//maka jumlahhapus akan bertambah	
				k=1;//inisialisasi mengecek kata hapus
				while(k<strlen(hapus)){//syarat k lebih kecil dari banyaknya hapus
					if(kalimat[j+k]==hapus[k]){//jika kalimat sebanyak baris j+k sama dengan hapus sebanyak k
						jumlahhapus++;//maka jumlahhapus terus bertambah 
					}
					k++;//maka k akan terus mencari
				}
			}
			if(jumlahhapus==strlen(hapus)){//jika jumlahhapus sama dengan banyaknya hapus
				k=j+strlen(hapus);//inisialisasi untuk penghapusan
				while(k<=strlen(kalimat)){//k lebih kecil sama dengan banyaknya kalimat 
					kalimat[k-strlen(hapus)]=kalimat[k];//maka kalimat indeks k akan dikurangi sebanyak banyaknya hapus
					k++;//k akan terus mencari
				}
				j--;//maka j terus dikurangi
			}
		}
	}
	
	//nge print lurus
	printf("%s\n",kalimat);//output
	if(strlen(kalimat)%2==0){//jika banyaknya kalimat genap
		for(i=0;i<strlen(kalimat)/2;i++){								//maka akan membentuk pola seperti ini
			for(j=0;j<spasi;j++){										//x	       x
				printf(" ");											// x      x
			}															//  x    x
			printf("%c",kalimat[i]);									//   x  x
			for(j=spasi;j<(strlen(kalimat)/2)-1;j++){					//    xx
				printf(" ");
			}
			for(j=spasi;j<(strlen(kalimat)/2)-1;j++){
				printf(" ");
			}
			printf("%c\n",kalimat[strlen(kalimat)-i-1]);
			spasi++;
		}
	}else{//jika tidak
		for(i=0;i<strlen(kalimat)/2;i++){								//maka akan membentuk pola seperti ini
			for(j=0;j<spasi;j++){										//x       x
				printf(" ");											// x     x
			}															//  x   x
			printf("%c",kalimat[i]);									//   x x
			for(j=spasi;j<(strlen(kalimat)/2)-1;j++){					//    x
				printf(" ");
			}
			printf(" ");
			for(j=spasi;j<(strlen(kalimat)/2)-1;j++){
				printf(" ");
			}
			printf("%c\n",kalimat[strlen(kalimat)-i-1]);
			spasi++;
		}
		for(i=0;i<strlen(kalimat)/2;i++){
			printf(" ");
		}
		printf("%c\n",kalimat[strlen(kalimat)/2]);
	}

return 0;
}
