#include <stdio.h>
/*
Saya Abdul Aziz Priatna(1307123) tidak melakukan kecurangan seperti yang telah dispesifikasikan pada mata kuliah 
Algoritma dan Pemrograman I dalam mengerjakan UTS, jika saya melakukan kecurangan maka Allah/Tuhan adalah saksi saya, 
dan saya bersedia menerima 
hukumanNya. Aamiin.
*/

int main(){
	
	//variabel
	int n,i;
	
	//inputan
	scanf("%d",&n);
	
	//banyaknya angka sebanyak indeks n
	int angka[n];
	
	//perulangan array
	for(i=0;i<n;i++){
		//banyaknya inputan angka sebanyak indeks i
		scanf("%d",&angka[i]);
	}
	
	//proses
		//mencari nilai maximal bagian depan
		int maximaldepan=angka[0];
		for(i=0;i<(n/2);i++){
			//jika nilai maximal depan lebih kecil dari angka sebanyak i
			if(maximaldepan<angka[i]){
				maximaldepan=angka[i];//maka nilai maximal depan sama dengan nilai angka sebanyak i
			}
		}
		
		//mencari nilai minimal bagian belakang
		int minimalbelakang=angka[n];
		for(i=(n-(n/2));i<n;i++){
			//jika nilai minimal belakang besar dari angka sebanyak i
			if(minimalbelakang>angka[i]){
				minimalbelakang=angka[i];////maka nilai minimal belakang sama dengan nilai angka sebanyak i
			}
		}
	
	
	//proses output
	if(maximaldepan==minimalbelakang){//jika nilai maximaldepan sama dengan nilai minimalbelakang
		//maka tampilkan valid
		printf("valid\n");//output valid
		printf("%d\n",maximaldepan);//output dengan nilai yang diinginkan sama
	}else{//jika tidak
		//maka tampilkan tidak valid
		printf("tidak valid\n");//output tidak valid
		printf("%d\n",maximaldepan);//output nilai maximaldepan yang diinginkan
		printf("%d\n",minimalbelakang);//output nilai minimaldepan yang diinginkan
	}
	
return 0;
}
