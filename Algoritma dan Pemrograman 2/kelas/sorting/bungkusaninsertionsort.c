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

void insertionsort(int n,bungkusan* arr){
	
	int i,j,data_sisip,data_sisip2;
	
	for(i=1;i<n;i++){
		data_sisip=arr[i].x;
		data_sisip2=arr[i].y;
		j=i-1;
		while((data_sisip<arr[j].x && data_sisip2<arr[j].y) && j>=0){
			/*jika data array lebih kecil dari data sisip
			maka data array digeser ke belakang*/
			arr[j+1].x=arr[j].x;
			arr[j+1].y=arr[j].y;
			j=j-1;
		}
		/*menempatkan data sisip pada array*/
		arr[j+1].x=data_sisip;
		arr[j+1].y=data_sisip2;
		
	}

	tampil(n,arr);
}


int main(){
	
	int n,i,j;
	printf("Masukan banyaknya array : ");
	scanf("%d",&n);
	
	bungkusan tabInt[n];
	printf("isi array sebelum di sorting : \n");
	for(i=0;i<n;i++){
		printf("Masukan bungkusan x : ");
		scanf("%d",&tabInt[i].x);
		printf("Masukan bungkusan y : ");
		scanf("%d",&tabInt[i].y);
	}
	
	insertionsort(n,tabInt);		
	
	return 0;
}