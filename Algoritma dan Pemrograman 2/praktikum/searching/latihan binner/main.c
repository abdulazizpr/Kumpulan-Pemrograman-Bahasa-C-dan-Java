#include <stdio.h>
#include <string.h>

int cari_desimal(char biner[]){
	int i;
	int panjang=strlen(biner);
	int kali=1;
	int jumlah=0;
	
	for(i=panjang-1;i>=0;i--){
		if(biner[i]=='1'){
			jumlah = jumlah + kali;
		}
		kali = kali*2;
	}
	
	return jumlah;
}

int main(){
	
	int n,i,ketemu=0,tampung_biner,desimal;
	scanf("%d",&n);
	char biner[n][100];
	for(i=0;i<n;i++){
		scanf("%s",&biner[i]);
	}
	
	scanf("%d",&desimal);
	
	i=0;
	while(ketemu==0 && i<n){
		tampung_biner=cari_desimal(biner[i]);
		if(tampung_biner==desimal){
			ketemu=1;
		}else{
			i++;
		}
	}
	
	if(ketemu==1){
		printf("ada\n");
	}else{
		printf("tidak ada\n");
	}
	
	return 0;
}