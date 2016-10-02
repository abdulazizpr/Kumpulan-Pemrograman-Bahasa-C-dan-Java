#include <stdio.h>

typedef struct{int x,y;}bungkusan;

void tampil(int n,bungkusan* tabInt){
	int i;
	
	printf("Isi bungkusan x setelah di sorting : ");
	for(i=0;i<n;i++){
		printf("%d ",tabInt[i].x);
	}
	printf("\n");
	printf("Isi bungkusan y setelah di sorting : ");
	for(i=0;i<n;i++){
		printf("%d ",tabInt[i].y);
	}
	printf("\n");
	
}

void bubblesort(int n,bungkusan* tabInt){
	
	bungkusan temp;
	int i,j,tukar;
	
	do{
		//inisialisasi nilai tukar sebelum ada pertukaran diset false
		tukar=0;
		
		//perulangan dan memeriksa apakah ada pertukaran
		for(i=0;i<n-1;i++){
			//jika ada nilai di pertukaran
			if(tabInt[i].x>tabInt[i+1].x && tabInt[i].y>tabInt[i+1].y){
				//menukar posisi elemen
				temp=tabInt[i];
				tabInt[i]=tabInt[i+1];
				tabInt[i+1]=temp;
				tukar=1;
			}
			
		}
		
	}while(tukar==1);
	
	tampil(n,tabInt);
}

int main(){
	int n,i,j;
	printf("Masukan banyanknya array : ");
	scanf("%d",&n);
	
	bungkusan tabInt[n];
	printf("Isi array sebelum di sorting : \n");
	for(i=0;i<n;i++){
		printf("Masukan bungkusan x : ");
		scanf("%d",&tabInt[i].x);
		printf("Masukan bungkusan y : ");
		scanf("%d",&tabInt[i].y);
	}
	
	bubblesort(n,tabInt);
	
	return 0;
}