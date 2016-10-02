#include "header.h"

int main(){
	
	char pilihan[100];
	int n,m,i;
	scanf("%s",pilihan);
	scanf("%d",&n);
	bungkusan tabel1[n];
	
	for(i=0;i<n;i++){
		scanf("%s",&tabel1[i].nama);
		scanf("%s",&tabel1[i].kartu);
		tabel1[i].tampung=cekkartu(i,tabel1);
	}
	
	scanf("%d",&m);
	bungkusan tabel2[m];
	
	for(i=0;i<m;i++){
		scanf("%s",&tabel2[i].nama);
		scanf("%s",&tabel2[i].kartu);
		tabel2[i].tampung=cekkartu(i,tabel2);
	}
	
	if(strcmp(pilihan,"selectionsort")==0){
		selectionsort(n,tabel1);
		selectionsort(m,tabel2);
	}else if(strcmp(pilihan,"insertionsort")==0){
		insertionsort(n,tabel1);
		insertionsort(m,tabel2);
	}else if(strcmp(pilihan,"bubblesort")==0){
		bubblesort(n,tabel1);
		bubblesort(m,tabel2);
	}else if(strcmp(pilihan,"quicksort")==0){
		quicksort(0,n-1,tabel1);
		quicksort(0,m-1,tabel2);
	}
	
	bungkusan tabelurut[n+m];
	
	merge(tabel1,tabel2,tabelurut,n,m);
	
	return 0;
}