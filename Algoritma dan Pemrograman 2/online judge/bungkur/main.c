#include "header.h"

int main(){
	
	int n,m,i,j,batas;
	char pilihan[100];
	scanf("%s",&pilihan);
		scanf("%d",&n);
		
		bungkusan tabel1[n];
		for(i=0;i<n;i++){
			for(j=0;j<4;j++){
				scanf("%d",&tabel1[i].isi[j]);
			}
			scanf("%d",&tabel1[i].pengali);
		}
		
		scanf("%d",&batas);
		scanf("%d",&m);
		
		bungkusan tabel2[m];
		for(i=0;i<m;i++){
			for(j=0;j<4;j++){
				scanf("%d",&tabel2[i].isi[j]);
			}
			scanf("%d",&tabel2[i].pengali);
		}
		
		int hasil[100];
		if(strcmp(pilihan,"selectionsort")==0){
			for(i=0;i<n;i++){
				selectionsort1(i,4,tabel1);
				tabel1[i].isi[3]*=tabel1[i].pengali;
			}
			for(i=0;i<m;i++){
				selectionsort1(i,4,tabel2);
				tabel2[i].isi[3]*=tabel2[i].pengali;
			}
			selectionsort2(n,tabel1);
			selectionsort2(m,tabel2);
		}else if(strcmp(pilihan,"insertionsort")==0){
			for(i=0;i<n;i++){
				insertionsort1(i,4,tabel1);
				tabel1[i].isi[3]*=tabel1[i].pengali;
			}
			for(i=0;i<m;i++){
				insertionsort1(i,4,tabel2);
				tabel2[i].isi[3]*=tabel2[i].pengali;
			}
			insertionsort2(n,tabel1);
			insertionsort2(m,tabel2);
		}
		else if(strcmp(pilihan,"quicksort")==0){
			for(i=0;i<n;i++){
				quicksort1(i,0,4-1,tabel1);
				tabel1[i].isi[3]*=tabel1[i].pengali;
			}
			for(i=0;i<m;i++){
				quicksort1(i,0,4-1,tabel2);
				tabel2[i].isi[3]*=tabel2[i].pengali;
			}
			quicksort2(0,n-1,tabel1);
			quicksort2(0,m-1,tabel2);
		}
		
		bungkusan tabel3[n+m];
		merge(tabel1,tabel2,tabel3,n,m);
		
		for(i=0;i<n+m;i++){
			for(j=0;j<4;j++){
				printf("%d",tabel3[i].isi[j]);
				if(j<4-1){
					printf(" ");
				}
			}
			printf("\n");
		}
		
	return 0;
}