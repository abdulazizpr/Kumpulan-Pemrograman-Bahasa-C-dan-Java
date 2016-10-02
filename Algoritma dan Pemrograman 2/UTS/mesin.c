#include "header.h"

//fungsi hitung jumlah pasangankonsonanvokal
int pasangankonsonanvokal(int i,bungkusan* tabel){
	
	int j,jumlahvokalkonsonan1=0,jumlahvokalkonsonan2=0;
	for(j=0;j<strlen(tabel[i].kata1);j++){
		if((tabel[i].kata1[j]!='a'||tabel[i].kata1[j]!='i'||tabel[i].kata1[j]!='u'||tabel[i].kata1[j]!='e'||tabel[i].kata1[j]!='o')&&
		(tabel[i].kata1[j+1]=='a'||tabel[i].kata1[j+1]=='i'||tabel[i].kata1[j+1]=='u'||tabel[i].kata1[j+1]=='e'||tabel[i].kata1[j+1]=='o')){
			jumlahvokalkonsonan1++;
		}
	}
	
	for(j=0;j<strlen(tabel[i].kata2);j++){
		if((tabel[i].kata2[j]!='a'||tabel[i].kata2[j]!='i'||tabel[i].kata2[j]!='u'||tabel[i].kata2[j]!='e'||tabel[i].kata2[j]!='o')&&
		(tabel[i].kata2[j+1]=='a'||tabel[i].kata2[j+1]=='i'||tabel[i].kata2[j+1]=='u'||tabel[i].kata2[j+1]=='e'||tabel[i].kata2[j+1]=='o')){
			jumlahvokalkonsonan2++;
		}
	}
	
	int temp;
	temp=jumlahvokalkonsonan1+jumlahvokalkonsonan2;
	
	
	return temp;
	
}

//prosedur selectionsort
void selectionsort(int n,bungkusan* arr){
	
	int i,j,minIndeks;
	bungkusan temp;
	for(i=0;i<n-1;i++){
		
		/*inisialisasi indeks minimum*/
		minIndeks = i;
		/*perulangan mencari nilai minimum sebanyak i+1 sampai elemen array*/
		
		for(j=i+1;j<n;j++){
			if(arr[minIndeks].jumlah<arr[j].jumlah) minIndeks = j;
		}
		
		//menukar posisi elemen
		temp=arr[i];
		arr[i]=arr[minIndeks];
		arr[minIndeks]=temp;
		
	}
		
}

//prosedur insertionsort
void insertionsort(int n,bungkusan* arr){
	
	int i,j;
	bungkusan temp;
	
	for(i=1;i<n;i++){
		temp=arr[i];
		j=i-1;
		while(temp.jumlah>arr[j].jumlah && j>=0){
			/*jika data array lebih kecil dari data sisip
			maka data array digeser ke belakang*/
			arr[j+1]=arr[j];
			j--;
		}
		/*menempatkan data sisip pada array*/
		arr[j+1]=temp;
		
	}

}

//prosedur bubblesort
void bubblesort(int n,bungkusan* tabInt){
	
	int i,tukar;
	bungkusan temp;
	
	do{
		//inisialisasi nilai tukar sebelum ada pertukaran diset false
		tukar=0;
		
		//perulangan dan memeriksa apakah ada pertukaran
		for(i=0;i<n-1;i++){
			//jika ada nilai di pertukaran
			if(tabInt[i].jumlah<tabInt[i+1].jumlah){
				//menukar posisi elemen
				temp=tabInt[i];
				tabInt[i]=tabInt[i+1];
				tabInt[i+1]=temp;
				tukar=1;
			}
			
		}
		
	}while(tukar==1);
	
}

//prosedur quicksort
void quicksort(int l,int r,bungkusan* tabInt){
	
	int i,j;
	bungkusan temp;
	i=l, j=r;
	
	do{
		
		while(tabInt[i].jumlah>tabInt[r].jumlah && i<=j){
			//mencegah i berjalan terlalu jauh melewati batas j
			i++;
		}
		while(tabInt[j].jumlah<tabInt[l].jumlah && i<=j){
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

//prosedur penggabungan tabel
void merge(bungkusan tabel1[],bungkusan tabel2[],bungkusan tabel_urut[],int n,int m){
		
	int index1=0;
	int index2=0;
	int index3=0;
	
	while(index1<n && index2<m){
		if(tabel1[index1].jumlah>tabel2[index2].jumlah){
			tabel_urut[index3]=tabel1[index1];
			index1++;
			index3++;
		}else if(tabel1[index1].jumlah<tabel2[index2].jumlah){
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