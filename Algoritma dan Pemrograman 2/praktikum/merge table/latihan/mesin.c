#include "header.h"

void tampil(int n,int m,int* tabel){
	int i;
	for(i=0;i<n+m;i++){
		printf("%d\n",tabel[i]);
	}
}

void bublesort(int tabel[],int n){
	int tampung,tukar,i;
	do{
		tukar=0;
		for(i=0;i<n;i++){
			if(tabel[i]>tabel[i+1]){
				tampung=tabel[i];
				tabel[i]=tabel[i+1];
				tabel[i+1]=tampung;
				tukar=1;
			}
		}
	}while(tukar==1);
	
}

void quicksort(int l,int r,int* tabInt){
	
	int i,j,temp;
	i=l, j=r;
	
	do{
		
		while(tabInt[i]<tabInt[r] && i<=j){
			//mencegah i berjalan terlalu jauh melewati batas j
			i++;
		}
		while(tabInt[j]>tabInt[l] && i<=j){
			//mencegah i berjalan terlalu jauh melewati batas i
			j--;
		}
		
		if(i<j){
			temp=tabInt[i];
			tabInt[i]=tabInt[j];
			tabInt[j]=temp;
			i++;
			j--;
		}
		
	}while(i<j);
	
	if(l<j){
		quicksort(l,j,tabInt);
	}
	if(i<r){
		quicksort(i,r,tabInt);
	}
	
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
		
}


void merge(char pilihan[100],int tabel1[],int tabel2[],int tabel_urut[],int n,int m){
	
	if(strcmp(pilihan,"bubblesort")==0){
		bublesort(tabel1,n);
		bublesort(tabel2,m);
	}else if(strcmp(pilihan,"quicksort")==0){
		quicksort(0,n-1,tabel1);
		quicksort(0,m-1,tabel2);
	}else if(strcmp(pilihan,"insertionsort")==0){
		insertionsort(n,tabel1);
		insertionsort(m,tabel2);
	}else if(strcmp(pilihan,"selectionsort")==0){
		selectionsort(n,tabel1);
		selectionsort(m,tabel2);
	}
	
	int index1=0;
	int index2=0;
	int index3=0;
	
	while(index1<n && index2<m){
		if(tabel1[index1]<tabel2[index2]){
			tabel_urut[index3]=tabel1[index1];
			index1++;
			index3++;
		}else if(tabel1[index1]>tabel2[index2]){
			tabel_urut[index3]=tabel2[index2];
			index2++;
			index3++;
		}else{
			tabel_urut[index3]=tabel1[index1];
			index1++;
			index3++;
			tabel_urut[index3]=tabel2[index2];
			index2++;
			index3++;
		}
	}
	
	int i=0;
	for(i=index1;i<n;i++){
		tabel_urut[index3]=tabel1[i];
		index3++;
	}
	for(i=index2;i<m;i++){
		tabel_urut[index3]=tabel2[i];
		index3++;
	}
	
	tampil(n,m,tabel_urut);
}