#include "header.h"

//konversibiner ke desimal
int konversibiner(int a,bungkusan* tabel){
	int i;
	int panjang=strlen(tabel[a].binner);
	int multiplier;
	int jumlah=0;
	
	if(panjang==9){
		multiplier=256;
		for(i=0;i<9;i++){
			if(tabel[a].binner[i]=='1'){
				jumlah = jumlah + multiplier;
			}
			multiplier/=2;
		}
	}else if(panjang==8){
		multiplier=128;
		for(i=0;i<9;i++){
			if(tabel[a].binner[i]=='1'){
				jumlah = jumlah + multiplier;
			}
			multiplier/=2;
		}
	}	
	return jumlah;
}

//penjumlahan biner antara tabel 1 dan tabel lainnya
char* penjumlahanbiner(int a,bungkusan* tabel1,bungkusan* tabel2){
	int i,x=7;
	int panjang=8;
	int kali=1;
	int jumlah=0;
	char hasil[8];
	int status=0;
	
	for(i=panjang-1;i>=0;i--){
		//jika tabel1 = 1 dan tabel2 = 0
		if(tabel1[a].binner[i]=='1' && tabel2[a].binner[i]=='0'){
			if(status==1){//maka jika statusnya 1
				hasil[x]='0';//maka hasilnya 0
				status=1;//status 1
			}else{//jika tidak
				hasil[x]='1';//maka hasilnya 1
				status=0;//status 0
			}
			x--;
		}else if(tabel1[a].binner[i]=='0' && tabel2[a].binner[i]=='0'){
			if(status==1){
				hasil[x]='1';
				status=0;
			}else{
				hasil[x]='0';
				status=0;
			}
			x--;
		}else if(tabel1[a].binner[i]=='0' && tabel2[a].binner[i]=='1'){
			if(status==1){
				hasil[x]='0';
				status=1;
			}else{
				hasil[x]='1';
				status=0;
			}
			x--;
			//status=1;
		}else if(tabel1[a].binner[i]=='1' && tabel2[a].binner[i]=='1'){
			if(status==1){
				hasil[x]='1';
				status=1;
			}else{
				hasil[x]='0';
				status=1;
			}
			x--;
		}
		
	}
	
	
	return hasil;
}

//prosedur sorting menggunakan selection sort
void sorting(bungkusan* tabel,int n){
	int i,j,minindeks;
	bungkusan temp;
	
	//prosedur pengurutan
	for(i=0;i<n;i++){
		minindeks=i;
		for(j=i+1;j<n;j++){
			if(tabel[j].desimal<tabel[minindeks].desimal){
				minindeks=j;
			}
		}
		temp=tabel[i];
		tabel[i]=tabel[minindeks];
		tabel[minindeks]=temp;
	}
	
}

//prosedur penggabungan tabel
void merge(bungkusan tabel1[],bungkusan tabel2[],bungkusan tabel_urut[],int n,int m){
	
	int index1=0;
	int index2=0;
	int index3=0;
	
	while(index1<n && index2<m){
		if(tabel1[index1].desimal<tabel2[index2].desimal){
			tabel_urut[index3]=tabel1[index1];
			index1++;
			index3++;
		}else if(tabel1[index1].desimal>tabel2[index2].desimal){
			tabel_urut[index3]=tabel2[index2];
			index2++;
			index3++;
		}else{
			tabel_urut[index3]=tabel1[index1];
			index1++;
			index3++;
			tabel_urut[index3]=tabel2[index2];
			index2++;
			index3++;
		}
	}
	
	int i=0;
	for(i=index1;i<n;i++){
		tabel_urut[index3]=tabel1[i];
		index3++;
	}
	for(i=index2;i<m;i++){
		tabel_urut[index3]=tabel2[i];
		index3++;
	}
}

//proses pencarian menggunakan binary_search
void binary_search(bungkusan* tabel,int n,int cari_desimal){	
	int ketemu=0;
	int i=0;
	int j=n-1;
	int k;
	
	//proses pencarian
	while(ketemu==0 && i<=j){
		k=(i+j)/2;
		if(cari_desimal==tabel[k].desimal){
			ketemu=1;
		}else{
			if(cari_desimal<tabel[k].desimal){
				j=k-1;
			}else{
				i=k+1;
			}
			
		}
	}
	
	//jika ketemu 1
	if(ketemu==1){
		//maka tampilkan hasil urut binnernya
		for(i=0;i<n;i++){
			for(j=0;j<8;j++){
				printf("%c",tabel[i].binner[j]);
			}
			printf("\n");
		}
		printf("data ditemukan\n");
		printf("%d\n",k+1);//dan di indeks berapa dia ditemukan
	}else{//jika tidak
		//maka data not found
		printf("data not found\n");
	}
	
}