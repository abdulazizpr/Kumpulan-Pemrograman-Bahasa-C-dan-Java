#include "header.h"

//prosedur menampilkan hasil sorting
void tampil(int n,dota* karakter){
	int i;
	
	for(i=0;i<n;i++){
		//output
		printf("%s %s %s\n",karakter[i].tipe,karakter[i].nama,karakter[i].skill);
	}
	
}

//prosedur sorting
void insertionsort(int n,dota* karakter){
	int i,j;
	
	dota temp;//untuk menampung semua nilai bungkusan
	
	for(i=1;i<n;i++){
		
		temp=karakter[i];//menempatkan karakter ke dalam temp 
		
		j=i-1;//inisialisasi
		//pengurutan berdasarkan tipe secara descending(1)
		while((strcmp(temp.tipe,karakter[j].tipe)==1 
		||(strcmp(temp.tipe,karakter[j].tipe)==0 && strcmp(temp.nama,karakter[j].nama)==1)) 
		&& (j>=0)){
		//jika ada tipe yang sama maka melakukan pengurutan berdasarkan nama secara descending(1)	
			karakter[j+1]=karakter[j];//menampung karakter setelahnya	
			j--;//iterasi berkurang
		}
		
		//menempatkan temp
		karakter[j+1]=temp;
		
	}
	
	//lalu tampilkan di prosedur tampil
	tampil(n,karakter);
	
}
