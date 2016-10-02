#include "header.h"

int main(){
	
	tree T;//deklarasi pohon
	makeTree("Hadi",10,&T);//buat akar pertama
	//buat anak dari hadi
	add("Hadi","Ando",20,&T.root);
		//buat anak dari ando
		add("Ando","Euis",22,&T.root);
		add("Ando","Otun",23,&T.root);
			//buat anak dari otun
			add("Otun","Dodi",30,&T.root);
			add("Otun","Ebta",12,&T.root);
	//buat anak dari hadi
	add("Hadi","Nesa",15,&T.root);
		//buat anak dari nesa
		add("Nesa","Yeni",25,&T.root);	
		add("Nesa","Atik",20,&T.root);	
			//buat anak dari atik
			add("Atik","Kiki",25,&T.root);	
			add("Atik","Akbar",21,&T.root);	
	
	int n,i;
	scanf("%d",&n);//banyaknya inputan yang dicari
	
	char nama[n][100];
	simpul * cari;
	for(i=0;i<n;i++){
		scanf("%s",&nama[i]);//input nama yang dicari
	}
	
	for(i=0;i<n;i++){
		tampilortu(nama[i],T.root);//tampilkan ortu yang dicari
		cari = findSimpul(nama[i],T.root);//mencari simpul
		carigenerasi(1,cari,T.root);//lalu hitung jumlah generasinya sampai anak yang dicari
		jumlahsimpulcari(T.root->data.angka,cari,T.root);//lalu jumlahkan simpul sampai anak yang dicari
	}
	
	
	return 0;
}