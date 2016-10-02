#include "header.h"

void tampil(int n,int m,bungkusan* tabel){
	int i;
	for(i=0;i<n+m;i++){
		printf("%s %s\n",tabel[i].nama,tabel[i].kartu);
	}
	
}

int cekkartu(int i,bungkusan* tabel){
	
	int j;
	int temp;
	for(j=0;j<strlen(tabel[i].kartu);j++){
		if(tabel[i].kartu[j]=='A'){
			temp=1;
		}else if(tabel[i].kartu[j]=='2'){
			temp=2;
		}else if(tabel[i].kartu[j]=='3'){
			temp=3;
		}else if(tabel[i].kartu[j]=='4'){
			temp=4;
		}else if(tabel[i].kartu[j]=='5'){
			temp=5;
		}else if(tabel[i].kartu[j]=='6'){
			temp=6;
		}else if(tabel[i].kartu[j]=='7'){
			temp=7;
		}else if(tabel[i].kartu[j]=='8'){
			temp=8;
		}else if(tabel[i].kartu[j]=='9'){
			temp=9;
		}else if(tabel[i].kartu[j]=='1' || tabel[i].kartu[j]=='0'){
			temp=10;
		}else if(tabel[i].kartu[j]=='J'){
			temp=11;
		}else if(tabel[i].kartu[j]=='Q'){
			temp=12;
		}else if(tabel[i].kartu[j]=='K'){
			temp=13;
		}
	}
	
	return temp;
}

void selectionsort(int n,bungkusan* arr){
	
	int i,j,minIndeks;
	bungkusan temp;
	for(i=0;i<n-1;i++){
		
		/*inisialisasi indeks minimum*/
		minIndeks = i;
		/*perulangan mencari nilai minimum sebanyak i+1 sampai elemen array*/
		
		for(j=i+1;j<n;j++){
			if(arr[minIndeks].tampung>arr[j].tampung) minIndeks = j;
		}
		
		//menukar posisi elemen
		temp=arr[i];
		arr[i]=arr[minIndeks];
		arr[minIndeks]=temp;
		
	}
		
}

void insertionsort(int n,bungkusan* arr){
	
	int i,j;
	bungkusan temp;
	
	for(i=1;i<n;i++){
		temp=arr[i];
		j=i-1;
		while(temp.tampung<arr[j].tampung && j>=0){
			/*jika data array lebih kecil dari data sisip
			maka data array digeser ke belakang*/
			arr[j+1]=arr[j];
			j--;
		}
		/*menempatkan data sisip pada array*/
		arr[j+1]=temp;
		
	}

}

void bubblesort(int n,bungkusan* tabInt){
	
	int i,tukar;
	bungkusan temp;
	
	do{
		//inisialisasi nilai tukar sebelum ada pertukaran diset false
		tukar=0;
		
		//perulangan dan memeriksa apakah ada pertukaran
		for(i=0;i<n-1;i++){
			//jika ada nilai di pertukaran
			if(tabInt[i].tampung>tabInt[i+1].tampung){
				//menukar posisi elemen
				temp=tabInt[i];
				tabInt[i]=tabInt[i+1];
				tabInt[i+1]=temp;
				tukar=1;
			}
			
		}
		
	}while(tukar==1);
	
}

void quicksort(int l,int r,bungkusan* tabInt){
	
	int i,j;
	bungkusan temp;
	i=l, j=r;
	
	do{
		
		while(tabInt[i].tampung<tabInt[r].tampung && i<=j){
			//mencegah i berjalan terlalu jauh melewati batas j
			i++;
		}
		while(tabInt[j].tampung>tabInt[l].tampung && i<=j){
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

void merge(bungkusan tabel1[],bungkusan tabel2[],bungkusan tabel_urut[],int n,int m){
		
	int index1=0;
	int index2=0;
	int index3=0;
	
	while(index1<n && index2<m){
		if((tabel1[index1].tampung<tabel2[index2].tampung)||(tabel1[index1].tampung==tabel2[index2].tampung && strcmp(tabel1[index1].nama,tabel2[index2].nama)==-1)){
			tabel_urut[index3]=tabel1[index1];
			index1++;
			index3++;
		}else if((tabel1[index1].tampung>tabel2[index2].tampung)||(tabel1[index1].tampung==tabel2[index2].tampung && strcmp(tabel1[index1].nama,tabel2[index2].nama)==-1)){
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
	
	int i;
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
