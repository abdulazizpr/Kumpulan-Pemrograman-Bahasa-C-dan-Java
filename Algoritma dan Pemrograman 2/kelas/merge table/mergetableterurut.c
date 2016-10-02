#include <stdio.h>

void tampil(int n,int* tabel){
	
	int i;
	
	printf("Hasil Merge Terurut : \n");
	for(i=0;i<n;i++){
		printf("%d\n",tabel[i]);
	}
	
}

void bublesort(int n,int* tabel){
	
	int i, temp, tukar;
	
	do{
		//inisialisasi nilai tukar sebelum ada pertukaran diset false
		tukar=0;
		
		//perulangan dan memeriksa apakah ada pertukaran
		for(i=0;i<n-1;i++){
			//jika ada nilai di pertukaran
			if(tabel[i]>tabel[i+1]){
				//menukar posisi elemen
				temp=tabel[i];
				tabel[i]=tabel[i+1];
				tabel[i+1]=temp;
				tukar=1;
			}
			
		}
		
	}while(tukar==1);
}

void mergeurut(int n,int m,int* tabel1,int* tabel2){
	
	bublesort(4,tabel1);
	bublesort(4,tabel2);
	
	int tabel3[8];
	int i,j,k,l;
	
	i=0;//counter 1
	j=0;//counter 2
	k=0;//counter 3
	while(i<4 && j<4){
		if(tabel1[i]<tabel2[j]){
			tabel3[k]=tabel1[i];
			i++;
			k++;
		}else if(tabel2[j]<tabel1[i]){
			tabel3[k]=tabel2[j];
			j++;
			k++;
		}else{
			tabel3[k]=tabel1[i];
			i++;
			k++;
			tabel3[k]=tabel2[j];
			j++;
			k++;
		}
	}
	
	//proses sisa
	if(i<4){
		for(l=i;l<4;l++){
			tabel3[k]=tabel1[l];
			k++;
		}
	}
	
	if(j<4){
		for(l=j;l<4;l++){
			tabel3[k]=tabel2[l];
			k++;
		}
	}
	
	tampil(k,tabel3);
}

int main(){
	
	int tabel1[4];
	int tabel2[4];
	int tabel3[8];
	int i,j,k,l;
	
	printf("Masukan Tabel 1 : \n");
	for(i=0;i<4;i++){
		scanf("%d",&tabel1[i]);
	}
	
	printf("Masukan Tabel 2 : \n");
	for(j=0;j<4;j++){
		scanf("%d",&tabel2[j]);
	}
	
	mergeurut(4,4,tabel1,tabel2);	
	
	return 0;
}