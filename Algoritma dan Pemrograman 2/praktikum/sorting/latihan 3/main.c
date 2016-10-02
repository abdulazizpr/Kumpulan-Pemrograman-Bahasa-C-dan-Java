#include <stdio.h>
#include <string.h>

typedef struct{
	char nama[100];
	int nilai;
}bungkusan;

void tampil(int n,bungkusan* mahasiswa){
	
	int i;
	for(i=0;i<n;i++){
		printf("%s %d\n",mahasiswa[i].nama,mahasiswa[i].nilai);
	}
	
}

void bubblesort(int n,bungkusan* mahasiswa){
	int i,tukar;
	
	bungkusan temp;
	do{
		tukar=0;
		
		for(i=0;i<n-1;i++){
			if(strcmp(mahasiswa[i].nama,mahasiswa[i+1].nama)==1){
				temp=mahasiswa[i];
				mahasiswa[i]=mahasiswa[i+1];
				mahasiswa[i+1]=temp;
				tukar=1;
			}
		}
		
	}while(tukar==1);
	
	printf("\n");
	tampil(n,mahasiswa);
	
}

int main(){
	
	int n,i,j;
	scanf("%d",&n);
	
	bungkusan mahasiswa[n];
	for(i=0;i<n;i++){
		scanf("%s",&mahasiswa[i].nama);
		scanf("%d",&mahasiswa[i].nilai);
	}
	
	bubblesort(n,mahasiswa);
	
	return 0;
}