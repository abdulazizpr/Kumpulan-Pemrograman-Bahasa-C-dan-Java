#include "header.h"

void selectionsort1(int a,int n,bungkusan* tabel){
	
	int i,j,minIndeks;
	int temp;
	for(i=0;i<n-1;i++){
		
		/*inisialisasi indeks minimum*/
		minIndeks = i;
		/*perulangan mencari nilai minimum sebanyak i+1 sampai elemen array*/
		
		for(j=i+1;j<n;j++){
			if(tabel[a].isi[minIndeks]>tabel[a].isi[j]) minIndeks = j;
		}
		
		//menukar posisi elemen
		temp=tabel[a].isi[i];
		tabel[a].isi[i]=tabel[a].isi[minIndeks];
		tabel[a].isi[minIndeks]=temp;
		
	}
		
}

void selectionsort2(int n,bungkusan* tabel){
	
	int i,j,minIndeks;
	bungkusan temp;
	for(i=0;i<n-1;i++){
		
		/*inisialisasi indeks minimum*/
		minIndeks = i;
		/*perulangan mencari nilai minimum sebanyak i+1 sampai elemen array*/
		
		for(j=i+1;j<n;j++){
			if(tabel[minIndeks].isi[3]>tabel[j].isi[3]) minIndeks = j;
		}
		
		//menukar posisi elemen
		temp=tabel[i];
		tabel[i]=tabel[minIndeks];
		tabel[minIndeks]=temp;
		
	}
		
}

void insertionsort1(int a,int n,bungkusan* tabel){
	
	int i,j;
	int temp;
	
	for(i=1;i<n;i++){
		temp=tabel[a].isi[i];
		j=i-1;
		while(temp<tabel[a].isi[j] && j>=0){
			/*jika data array lebih kecil dari data sisip
			maka data array digeser ke belakang*/
			tabel[a].isi[j+1]=tabel[a].isi[j];
			j--;
		}
		/*menempatkan data sisip pada array*/
		tabel[a].isi[j+1]=temp;
		
	}

}

void insertionsort2(int n,bungkusan* tabel){
	
	int i,j;
	bungkusan temp;
	
	for(i=1;i<n;i++){
		temp=tabel[i];
		j=i-1;
		while(temp.isi[3]<tabel[j].isi[3] && j>=0){
			/*jika data array lebih kecil dari data sisip
			maka data array digeser ke belakang*/
			tabel[j+1]=tabel[j];
			j--;
		}
		/*menempatkan data sisip pada array*/
		tabel[j+1]=temp;
		
	}

}

void quicksort1(int a,int l,int r,bungkusan* tabel){
	
	int i,j;
	int temp;
	i=l, j=r;
	
	do{
		
		while(tabel[a].isi[i]<tabel[a].isi[r] && i<=j){
			//mencegah i berjalan terlalu jauh melewati batas j
			i++;
		}
		while(tabel[a].isi[j]>tabel[a].isi[l] && i<=j){
			//mencegah i berjalan terlalu jauh melewati batas i
			j--;
		}
		
		if(i<j){
			temp=tabel[a].isi[i];
			tabel[a].isi[i]=tabel[a].isi[j];
			tabel[a].isi[j]=temp;
			i++;
			j--;
		}
		
	}while(i<j);
	
	if(l<j){
		quicksort1(a,l,j,tabel);
	}
	if(i<r){
		quicksort1(a,i,r,tabel);
	}
	
}

void quicksort2(int l,int r,bungkusan* tabel){
	
	int i,j;
	bungkusan temp;
	i=l, j=r;
	
	do{
		
		while(tabel[i].isi[3]<tabel[r].isi[3] && i<=j){
			//mencegah i berjalan terlalu jauh melewati batas j
			i++;
		}
		while(tabel[j].isi[3]>tabel[l].isi[3] && i<=j){
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
		quicksort2(l,j,tabel);
	}
	if(i<r){
		quicksort2(i,r,tabel);
	}
	
}

void merge(bungkusan* tabel1,bungkusan* tabel2,bungkusan* tabel_urut,int n,int m){
		
	int index1=0;
	int index2=0;
	int index3=0;
	
	while(index1<n && index2<m){
		if(tabel1[index1].isi[3]<tabel2[index2].isi[3]){
			tabel_urut[index3]=tabel1[index1];
			index1++;
			index3++;
		}else if(tabel1[index1].isi[3]>tabel2[index2].isi[3]){
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