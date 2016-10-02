#include "header.h"

int main(){
	
	//deklarasi pohon
	tree T;
	
	int n,m,i,j;
	scanf("%d",&n);//banyaknya input
	
	char input[100];
	simpul *node;
	
	for(i=0;i<n;i++){
		scanf("%s",&input);//inputan
		pemisah(input);//untuk memisahkan ortu dan anak
		if(strcmp(ortu,"null")==0){//jika ortunya null
			makeTree(anak,&T);//maka buat pohon awalnya
		}else{
			simpul *node = findSimpul(ortu,T.root);//cari ortunya
			
			if(node != NULL){//jika tidak null
				addChild(anak,&node);//maka tambahkan anaknya sesuai node ortu yang dicari
			}
		}
	}
	
	scanf("%d",&m);//banyaknya input penelusuran
	
	char cari[m][100];//deklarasikan ke dalam array
	for(i=0;i<m;i++){
		scanf("%s",&cari[i]);//input simpul yang dicari
	}
	
	inisialisasi(n);//menginisialisasi array menjadi 0 sebanyak masukan
	caripanjangkata(T.root,0);//cari panjang kata di tiap level
	printTreePreOrder(T.root,0,0);//lalu print pohon secara preorder
	printf("\n");
	
	char orang_tua[100][100];
	jumlah_hapus = 0;//inisialisasi variabel global untuk mencari jumlah_hapus
	for(i=0;i<m;i++){
		cari_ortu(cari[i],orang_tua,T.root,0);//cari penelusuran ortu dan tampilkan kunjungannya
	}
	
	for(i=0;i<jumlah_hapus;i++){
		simpul *find = findSimpul(temp[i],T.root);//lalu cari simpulnya
		if(find->child != NULL){//jika punya anak
			delete_anak(&find);//maka hapus kunjungan dari level pertama
			if(find != NULL){//jika yang di cari belum null
				delChild(temp[i],&T.root);//maka hapus anak di level pertama
			}
		}else{
			delChild(temp[i],&T.root);//lalu hapus simpul level pertama
		}
	}
	
	printf("\n");
	//lalu print lagi secara preorder
	inisialisasi(n);//menginisialisasi array menjadi 0 sebanyak masukan
	caripanjangkata(T.root,0);//cari panjang kata di tiap level
	printTreePreOrder(T.root,0,0);//lalu print pohon secara preorder
	
	return 0;
}