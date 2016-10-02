#include <stdio.h>

void tampil(int n,int* arr){
	
	int i,j;
	
	printf("isi array setelah di sorting : ");
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	
}

void insertionsort(int n,int* arr){
	
	int i,j,data_sisip;
	
	for(i=1;i<n;i++){
		data_sisip=arr[i];
		j=i-1;
		while(data_sisip<arr[j] && j>=0){
			/*jika data array lebih kecil dari data sisip
			maka data array digeser ke belakang*/
			arr[j+1]=arr[j];
			j=j-1;
		}
		/*menempatkan data sisip pada array*/
		arr[j+1]=data_sisip;
		
	}

	tampil(n,arr);
}




int main(){
	
	int n,i,j;
	printf("Masukan banyaknya array : ");
	scanf("%d",&n);
	
	int tabInt[n];
	printf("isi array sebelum di sorting : \n");
	for(i=0;i<n;i++){
		scanf("%d",&tabInt[i]);
	}
	
	insertionsort(n,tabInt);		
	
	return 0;
}