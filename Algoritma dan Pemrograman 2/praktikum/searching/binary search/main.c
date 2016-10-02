#include <stdio.h>
#include <string.h>

//deklarasi bungkusan
typedef struct{
	char nim[10];
	char nama[10];
	float nilai;
}mahasiswa;

void sorting(mahasiswa* ilkom,int n){
	int i,j,minindeks;
	mahasiswa temp;
	
	//prosedur pengurutan
	for(i=0;i<n;i++){
		minindeks=i;
		for(j=i+1;j<n;j++){
			if(strcmp(ilkom[j].nim,ilkom[minindeks].nim)==-1){
				minindeks=j;
			}
		}
		temp=ilkom[i];
		ilkom[i]=ilkom[minindeks];
		ilkom[minindeks]=temp;
	}
	
}

void binary_search(mahasiswa* ilkom,int n,char* cari_nim){
	int ketemu=0;
	int i=0;
	int j=n-1;
	int k;
	
	//proses pencarian
	while(ketemu==0 && i<=j){
		k=(i+j)/2;
		if(strcmp(ilkom[k].nim,cari_nim)==0){
			ketemu=1;
		}else{
			if(strcmp(ilkom[k].nim,cari_nim)==-1){
				j=k-1;
			}else{
				i=k+1;
			}
			
		}
	}
	
	//output
	if(ketemu==1){
		printf("-----data ditemukan-----\n");
		printf("nim   : %s\n",ilkom[k].nim);
		printf("nama  : %s\n",ilkom[k].nama);
		printf("nilai : %.2f\n",ilkom[k].nilai);
	}else{
		printf("data not found\n");
	}
	
}

int main(){
	
	int n,i;
	char cari_nim[10];
	
	//inputan
	scanf("%d",&n);
	mahasiswa ilkom[n];
	
	for(i=0;i<n;i++){
		scanf("%s %s %f",&ilkom[i].nim,&ilkom[i].nama,&ilkom[i].nilai);
	}
	
	//inputan
	scanf("%s",&cari_nim);
	
	//masuk ke prosedur
	sorting(ilkom,n);
	
	/* for(i=0;i<n;i++){
		printf("%s %s %.2f\n",ilkom[i].nim,ilkom[i].nama,ilkom[i].nilai);
	} */
	binary_search(ilkom,n,cari_nim);
	
	return 0;
}