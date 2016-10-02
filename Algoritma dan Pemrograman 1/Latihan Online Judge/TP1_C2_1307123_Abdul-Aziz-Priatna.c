#include <stdio.h>

/*
Saya Abdul Aziz Priatna(1307123) tidak melakukan kecurangan seperti yang telah dispesifikasikan pada 
mata kuliah Algoritma dan Pemrograman I dalam mengerjakan TP 1, 
jika saya melakukan kecurangan maka Allah/Tuhan adalah saksi saya, dan 
saya bersedia menerima hukumanNya. Aamiin.
*/

int main(){

	//variabel inputan
	int n,x,y;
	
	//varibael pembagian makanan
	int sisa;
	int mknan_teman;
	
	//input
	scanf("%d",&n);//banyaknya makanan yg dibawa
	scanf("%d",&x);//banyaknya hari
	scanf("%d",&y);//banyaknya teman
	
	//proses
	sisa=n-(x*3);
	mknan_teman=sisa/y;
	
	//output
	//banyak makanan untuk teman
	printf("%d\n",sisa);
	//banyak makanan yg didapat setiap teman
	printf("%d\n",mknan_teman);
	
return 0;
}
