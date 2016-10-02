#include "header.h"

/*
Saya Abdul Aziz Priatna(1307123) tidak melakukan kecurangan seperti yang telah dispesifikasikan pada 
mata kuliah Algoritma dan Pemograman 2 dalam mengerjakan UTS, jika saya melakukan kecurangan
maka Allah/Tuhan adalah saksi saya, dan saya bersedia menerima hukumanNya. Aamiin.
*/

int main(){
	
	int n,m,o,i;
	char pilihan[100];//pilihan sorting
	scanf("%s",&pilihan);
	
	scanf("%d",&n);//banykanya bungkusan tabel1
	bungkusan tabel1[n];
	for(i=0;i<n;i++){
		scanf("%s",&tabel1[i].kata1);
		scanf("%s",&tabel1[i].kata2);
		tabel1[i].jumlah=pasangankonsonanvokal(i,tabel1);//penampungan jumlahpasanganvokalkonsonan
	}
	scanf("%d",&m);//banyaknya bungkusan tabel2
	bungkusan tabel2[m];
	for(i=0;i<m;i++){
		scanf("%s",&tabel2[i].kata1);
		scanf("%s",&tabel2[i].kata2);
		tabel2[i].jumlah=pasangankonsonanvokal(i,tabel2);//penampungan jumlahpasanganvokalkonsonan
	}
	
	scanf("%d",&o);//banykanya bungkusan tabel3
	bungkusan tabel3[o];
	for(i=0;i<o;i++){
		scanf("%s",&tabel3[i].kata1);
		scanf("%s",&tabel3[i].kata2);
		tabel3[i].jumlah=pasangankonsonanvokal(i,tabel3);//penampungan jumlahpasanganvokalkonsonan
	}
	
	if(strcmp(pilihan,"selectionsort")==0){//jika pilihannya selectionsort maka panggil prosedur selectionsort
		selectionsort(n,tabel1);
		selectionsort(m,tabel2);
		selectionsort(o,tabel3);
	}else if(strcmp(pilihan,"quicksort")==0){//jika pilihannya quicksort maka panggil prosedur quicksort
		quicksort(0,n-1,tabel1);
		quicksort(0,m-1,tabel2);
		quicksort(0,o-1,tabel3);
	}else if(strcmp(pilihan,"bubblesort")==0){//jika pilihannya bubblesort maka panggil prosedur bubblesort
		bubblesort(n,tabel1);
		bubblesort(m,tabel2);
		bubblesort(o,tabel3);
	}else if(strcmp(pilihan,"insertionsort")==0){//jika pilihannya insertionsort maka panggil prosedur insertionsort
		insertionsort(n,tabel1);
		insertionsort(m,tabel2);
		insertionsort(o,tabel3);
	}
	
	int nau1=n+m;
	int nau2=n+m+o;
	bungkusan tabel_urut1[nau1];//untuk menggabungkan tabel1 dan tabel2
	bungkusan tabel_urut2[nau2];//untuk menggabungkan tabel_urut2 dan tabel3
	
	merge(tabel1,tabel2,tabel_urut1,n,m);//prosedur menggabungkan tabel1 dan tabel2 dan digabung di tabel_urut1
	merge(tabel_urut1,tabel3,tabel_urut2,nau1,o);//prosedur menggabungkan tabel_urut1 dan tabel3 dan digabung di tabel_urut2
	
	//output
	for(i=0;i<nau2;i++){
		printf("%d\n",tabel_urut2[i].jumlah);
	}
	
	return 0;
}