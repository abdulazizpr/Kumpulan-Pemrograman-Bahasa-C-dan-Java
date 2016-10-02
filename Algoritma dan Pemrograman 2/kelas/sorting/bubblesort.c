#include <stdio.h>

int main(){
	
	int tabInt[5]={34,67,23,28,98};
	int i, temp, tukar;
	
	printf("Sebelum di urut : ");
	for(i=0;i<5;i++){
		printf("%d ",tabInt[i]);
	}
	printf("\n");
	
	do{
		//inisialisasi nilai tukar sebelum ada pertukaran diset false
		tukar=0;
		
		//perulangan dan memeriksa apakah ada pertukaran
		for(i=0;i<5-1;i++){
			//jika ada nilai di pertukaran
			if(tabInt[i]>tabInt[i+1]){
				//menukar posisi elemen
				temp=tabInt[i];
				tabInt[i]=tabInt[i+1];
				tabInt[i+1]=temp;
				tukar=1;
			}
			
		}
		
	}while(tukar==1);
	
	printf("Setelah di urut : ");
	for(i=0;i<5;i++){
		printf("%d ",tabInt[i]);
	}
	printf("\n");
	
	return 0;
}