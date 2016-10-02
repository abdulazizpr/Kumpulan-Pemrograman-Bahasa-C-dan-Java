#include "header.h"

void putar(int i,int a,int b,bungkusan* tabel){
	int j,k;
	bungkusan temp[100];//variabel buat menampung hasil pemutaran
	
	//proses pemutaran kearah kanan
	for(j=0;j<a;j++){
		for(k=0;k<b;k++){
			temp[i].arr1[j][k]=tabel[i].arr1[b-k-1][j];
		}
	}
	
	//proses pencopian ulang matriks
	for(j=0;j<a;j++){
		for(k=0;k<b;k++){
			tabel[i].arr1[j][k]=temp[i].arr1[j][k];
		}
	}
	
	
}

void selectionsort(int n,bungkusan* tabel){
	
	int i,j,minIndeks;
	bungkusan temp;
	for(i=0;i<n-1;i++){
		
		/*inisialisasi indeks minimum*/
		minIndeks = i;
		/*perulangan mencari nilai minimum sebanyak i+1 sampai elemen array*/
		
		for(j=i+1;j<n;j++){
			if(tabel[minIndeks].arr1[1][1]>tabel[j].arr1[1][1]) minIndeks = j;
		}
		
		//menukar posisi elemen
		temp=tabel[i];
		tabel[i]=tabel[minIndeks];
		tabel[minIndeks]=temp;
		
	}
		
}

void insertionsort(int n,bungkusan* tabel){
	
	int i,j;
	bungkusan temp;
	
	for(i=1;i<n;i++){
		temp=tabel[i];
		j=i-1;
		while(temp.arr1[1][1]<tabel[j].arr1[1][1] && j>=0){
			/*jika data array lebih kecil dari data sisip
			maka data array digeser ke belakang*/
			tabel[j+1]=tabel[j];
			j--;
		}
		/*menempatkan data sisip pada array*/
		tabel[j+1]=temp;
		
	}

}


void quicksort(int l,int r,bungkusan* tabel){
	
	int i,j;
	bungkusan temp;
	i=l, j=r;
	
	do{
		
		while(tabel[i].arr1[1][1]<tabel[r].arr1[1][1] && i<=j){
			//mencegah i berjalan terlalu jauh melewati batas j
			i++;
		}
		while(tabel[j].arr1[1][1]>tabel[l].arr1[1][1] && i<=j){
			//mencegah i berjalan terlalu jauh melewati batas i
			j--;
		}
		
		if(i<j){
			temp=tabel[i];
			tabel[i]=tabel[j];
			tabel[j]=temp;
			i++;
			j--;
		}
		
	}while(i<j);
	
	if(l<j){
		quicksort(l,j,tabel);
	}
	if(i<r){
		quicksort(i,r,tabel);
	}
	
}

void merge(bungkusan* tabel1,bungkusan* tabel2,bungkusan* tabel_urut,int n,int m){
		
	int index1=0;
	int index2=0;
	int index3=0;
	
	while(index1<n && index2<m){
		if(tabel1[index1].arr1[1][1]<tabel2[index2].arr1[1][1]){
			tabel_urut[index3]=tabel1[index1];
			index1++;
			index3++;
		}else if(tabel1[index1].arr1[1][1]>tabel2[index2].arr1[1][1]){
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
	
	
}
