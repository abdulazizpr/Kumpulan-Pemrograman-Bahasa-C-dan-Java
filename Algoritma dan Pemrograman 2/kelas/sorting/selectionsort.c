#include <stdio.h>

void tampil(int n,int* arr){
	
	int i,j;
	
	printf("isi array setelah di sorting : ");
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	
}

void selectionsort(int n,int* arr){
	int i,j,temp,minIndeks;
	for(i=0;i<n-1;i++){
		
		/*inisialisasi indeks minimum*/
		minIndeks = i;
		/*perulangan mencari nilai minimum sebanyak i+1 sampai elemen array*/
		
		for(j=i+1;j<n;j++){
			if(arr[minIndeks]>arr[j]) minIndeks = j;
		}
		
		//menukar posisi elemen
		temp=arr[i];
		arr[i]=arr[minIndeks];
		arr[minIndeks]=temp;
		
	}
	
	tampil(n,arr);	
}

int main(){
	
	int n,i,j;
	printf("Masukan banyaknya array : ");
	scanf("%d",&n);
	
	int tabInt[n];
	printf("Isi array sebelum di sorting : \n");
	for(i=0;i<n;i++){
		scanf("%d",&tabInt[i]);
	}
	
	selectionsort(n,tabInt);
	
	return 0;
}