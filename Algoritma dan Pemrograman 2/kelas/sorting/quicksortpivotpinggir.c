#include <stdio.h>

int tabInt[10]={34, 67, 23, 28, 98, 15, 89, 67, 28, 18};

void tulis(){
	int i;
	for(i=0;i<10;i++){
		printf("%d ",tabInt[i]);
	}
	printf("\n");
}

void quicksortpivotpinggir(int l,int r){
	
	int i,j,temp;
	i=l, j=r;
	
	do{
		
		while(tabInt[i]<tabInt[r] && i<=j){
			//mencegah i berjalan terlalu jauh melewati batas j
			i++;
		}
		while(tabInt[j]>tabInt[l] && i<=j){
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
	printf("Hasil quicksort pivot pinggir  : ");
	tulis();
	
	if(l<j){
		quicksortpivotpinggir(l,j);
	}
	if(i<r){
		quicksortpivotpinggir(i,r);
	}
	
}

int main(){
	
	printf("Masukan angka : ");
	tulis();
	quicksortpivotpinggir(0,9);
	
	return 0;
}