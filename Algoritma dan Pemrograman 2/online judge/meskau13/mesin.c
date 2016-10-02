#include "header.h"

void insertionsort(int n,bungkusan* arr){
	
	int i,j;
	bungkusan data_sisip;
	
	for(i=1;i<n;i++){
		data_sisip=arr[i];
		j=i-1;
		while(data_sisip.jumlah_a>arr[j].jumlah_a || data_sisip.jumlah_a==arr[j].jumlah_a){
			/*jika data array lebih kecil dari data sisip
			maka data array digeser ke belakang*/
			arr[j+1]=arr[j];
			j=j-1;
		}
		/*menempatkan data sisip pada array*/
		arr[j+1]=data_sisip;
		
	}

}

void STARTKATA(char pita[]){

	indeks = 0;
	panjangkata = 0;
	
	while(pita[indeks] == ' ') indeks++;	//ketemu spasi dilewat
	
	while((pita[indeks] != ' ') && (pita[indeks] != '.'))
	{
		ckata[panjangkata] = pita[indeks];
		indeks++;
		panjangkata++;
	}
	ckata[panjangkata] = '\0';

}

void RESETKATA(){

	panjangkata = 0 ;
	ckata[panjangkata] = '\0';
	
}

void INCKATA(char pita[]){

	panjangkata = 0;
	
	while(pita[indeks] == ' ') indeks++;	//ketemu spasi dilewat

	while((pita[indeks] != ' ') && (pita[indeks] != '.'))
	{
		ckata[panjangkata] = pita[indeks];
		indeks++;
		panjangkata++;
	}
	ckata[panjangkata] = '\0';
	
}

char* GETCKATA(){
	return ckata;
}

int GETPANJANGKATA(){
	return panjangkata;
}

int EOPKATA(char pita[]){
	
	if(pita[indeks] == '.')	return 1;
	else return 0;
	
}