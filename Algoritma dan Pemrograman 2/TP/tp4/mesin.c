#include "header.h"

void tulis(){
	
	//proses output
	for(i=0;i<n;i++){
		//output
		printf("%s %s %d\n",kueh[i].toko,kueh[i].makanan,kueh[i].harga);
	}
	
}

void quicksort(int l,int r){
	
	//variabel
	int i,j;
	bungkusan temp;
	i=l;
	j=r;
	
	do{
		strcpy(temp.makanan,kueh[(l+r)/2].makanan);//pengkopian string dari pivot tengah
		temp.harga=kueh[(l+r)/2].harga;//pengkopian integer dari tengah
		while((strcmp(kueh[i].makanan,temp.makanan)==-1)||((strcmp(kueh[i].makanan,temp.makanan)==0)&&(kueh[i].harga<temp.harga))){
			i++;//pengecekan terus maju hingga bertemu titik j
		}
		while((strcmp(kueh[j].makanan,temp.makanan)==1)||((strcmp(kueh[j].makanan,temp.makanan)==0)&&(kueh[j].harga>temp.harga))){
			j--;//pengecekan terus mundur hingga bertemu titik i
		}
		if(i<=j){//jika lebih kecil atau sama dengan j
			//maka ia akan bertukar tempat
			temp=kueh[i];
			kueh[i]=kueh[j];
			kueh[j]=temp;
			i++;//terus maju
			j--;//terus mundur
		}
	}while(i<j);
	
	if(l<j){//jika l kurang dari j
		quicksort(l,j);//maka ia melakukan sorting lagi dari kiri ke kanan
	}
	if(i<r){//jika i kurang dari r
		quicksort(i,r);//maka ia melakukan sorting lagi dari kanan ke kiri
	}

}
