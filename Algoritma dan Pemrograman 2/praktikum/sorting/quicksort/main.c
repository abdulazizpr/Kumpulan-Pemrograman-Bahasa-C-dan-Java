#include <stdio.h>
#include <string.h>

char tabInt[100][100];
int n;

void quicksort(int l,int r){
	
	int i,j;
	char temp[100];
	char z[100];
	i=l;
	j=r;
	
	do{
		strcpy(z,tabInt[(l+r)/2]);
		while(strcmp(tabInt[i],z)==-1){
			i++;
		}
		while(strcmp(tabInt[j],z)==1){
			j--;
		}
		if(i<=j){
			strcpy(temp,tabInt[i]);
			strcpy(tabInt[i],tabInt[j]);
			strcpy(tabInt[j],temp);
			i++;
			j--;
		}
	}while(i<j);
	
	if(l<j){
		quicksort(l,j);
	}
	if(i<r){
		quicksort(i,r);
	}
	
	
}

void tulis(){
	int i;
	for(i=0;i<n;i++){
		printf("%s\n",tabInt[i]);
	}
}

int main(){
	
	int i;
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		scanf("%s",&tabInt[i]);
	}
	
	quicksort(0,n-1);
	printf("\n");
	tulis();
	
	return 0;
}
