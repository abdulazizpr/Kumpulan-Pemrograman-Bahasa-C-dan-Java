#include <stdio.h>
#include <string.h>

//deklarasi bungkusan
typedef struct{
	char nim[10];
	char nama[10];
	float nilai;
}mahasiswa;

void searching(mahasiswa* ilkom,int n,char* cari_nim){
	int ketemu=0;
	int i=0;
	
	//proses pencarian
	while(i<n && ketemu==0){
		if(strcmp(ilkom[i].nim,cari_nim)==0){
			ketemu=1;
		}else{
			i++;
		}
	}
	
	//output
	if(ketemu==1){
		printf("-----data ditemukan-----\n");
		printf("nim   : %s\n",ilkom[i].nim);
		printf("nama  : %s\n",ilkom[i].nama);
		printf("nilai : %.2f\n",ilkom[i].nilai);
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
	searching(ilkom,n,cari_nim);
	
	return 0;
}