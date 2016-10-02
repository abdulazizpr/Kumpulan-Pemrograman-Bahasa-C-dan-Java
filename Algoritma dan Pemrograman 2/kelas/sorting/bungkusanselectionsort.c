#include <stdio.h>

typedef struct{
	int x,y;
}bungkusan;

void tampil(int n,bungkusan* arr){
	
	int i,j;
	
	printf("isi bungkusan x setelah di sorting : ");
	for(i=0;i<n;i++){
		printf("%d ",arr[i].x);
	}
	
	printf("\n");
	
	printf("isi bungkusan y setelah di sorting : ");
	for(i=0;i<n;i++){
		printf("%d ",arr[i].y);
	}
	printf("\n");
	
}

void selectionsort(int n,bungkusan* arr){
	
	int i,j,temp,minIndeks,temp2,minIndeks2;
	
	for(i=0;i<n-1;i++){
		
		/*inisialisasi indeks minimum*/
		minIndeks = i;
		minIndeks2 = i;
		/*perulangan mencari nilai minimum sebanyak i+1 sampai elemen array*/
		
		for(j=i+1;j<n;j++){
			if(arr[minIndeks].x>arr[j].x && arr[minIndeks2].y>arr[j].y){
				minIndeks = j;
				minIndeks2 = j;
			}	
		}
		
		//menukar posisi elemen
		temp=arr[i].x;
		temp2=arr[i].y;
		arr[i].x=arr[minIndeks].x;
		arr[i].y=arr[minIndeks].y;
		arr[minIndeks].x=temp;
		arr[minIndeks].y=temp2;
		
	}
	
	tampil(n,arr);	
}

int main(){
	
	int n,i,j;
	printf("Masukan banyaknya array : ");
	scanf("%d",&n);
	
	bungkusan tabInt[n];
	printf("Isi array sebelum di sorting : \n");
	for(i=0;i<n;i++){
		printf("Masukan bungkusan x : ");
		scanf("%d",&tabInt[i].x);
		printf("Masukan bungkusan y : ");
		scanf("%d",&tabInt[i].y);
	}
	
	selectionsort(n,tabInt);
	
	return 0;
}