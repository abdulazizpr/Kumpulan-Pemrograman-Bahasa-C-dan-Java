#include <stdio.h>
#include <string.h>

typedef struct{
	int angka;
	char nama[100];
}bungkusan;

void tampil(bungkusan hanyir[100],int n){
	int i;
	
	for(i=0;i<n;i++){
		printf("%s %d\n",hanyir[i].nama,hanyir[i].angka);
	}
	
}

void sorting(bungkusan hanyir[100],int n){
	
	int i,j,minindeks;
	//char temp[50];
	
	bungkusan temp;
	/*proses pertukaran*/
	for(i=0;i<n-1;i++){
		minindeks=i;
		
		//untuk membandingkan
		for(j=i+1;j<n;j++){
			//mengurutkan dari a-z jika -1
			if(strcmp(hanyir[j].nama,hanyir[minindeks].nama)==-1){
				minindeks=j;
			}
		}
		//pertukaran
		temp=hanyir[i];
		hanyir[i]=hanyir[minindeks];
		hanyir[minindeks]=temp;
	}
	
	tampil(hanyir,n);
	
}

void selection(bungkusan hanyir[100],int n){
	
	int i,j,minindeks,temp;
	
	for(i=0;i<n-1;i++){
		//inisialisasi indeks minimum
		minindeks=i;
		
		bungkusan temp;
		/*untuk mencari nilai minimum*/
		for(j=i+1;j<n;j++){
			if(hanyir[j].angka<hanyir[minindeks].angka || (hanyir[j].angka==hanyir[minindeks].angka &&
			strcmp(hanyir[j].nama,hanyir[minindeks].nama)==-1)){
				minindeks=j;
			}
		}
		//pertukaran dengan nilai minimum
		temp=hanyir[i];
		hanyir[i]=hanyir[minindeks];
		hanyir[minindeks]=temp;
	}
	
	tampil(hanyir,n);
	
}

int main(){
	
	int n,i,j,pilihan;
	scanf("%d",&n);
	
	bungkusan hanyir[100];
	for(i=0;i<n;i++){
		scanf("%s %d",&hanyir[i].nama,&hanyir[i].angka);
	}
	
	scanf("%d",&pilihan);
	if(pilihan==1){
		sorting(hanyir,n);
	}else if(pilihan==2){
		selection(hanyir,n);
	}
	
	
	return 0;
}