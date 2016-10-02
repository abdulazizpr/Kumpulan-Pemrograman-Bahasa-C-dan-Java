#include "header.h"

//fungsi rekrusif fibbonaci
int deretfibbonaci(int i,int a,int b){
	
	int temp;
	
	if(i==0){			//basis pertama
		temp=a;
	}else if(i==1){		//basis kedua
		temp=b;
	}else{
		temp=deretfibbonaci(i-1,a,b)+deretfibbonaci(i-2,a,b);//lalu lempar fungsi secara berulang2 hingga berhenti di basis tersebut
	}
	
	return temp;		//lempar fungsi temp ke prosedur lemparfipbb
} 

//prosedur untuk melempar fungsi fibbonaci
void lemparfibb(int n,int m,int matriks1[n][m],int matriks2[n][m],int matriks3[n][m],int matriks4[n][m],int hasil[n][m], int deret[100]){
	
	int i,j,k;
	
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			for(k=0;k<matriks3[i][j];k++){
				//melakukan penampungan deret di prosedur lemparfibb
				deret[k]=deretfibbonaci(k,matriks1[i][j],matriks2[i][j]);//melakukan penampungan deret fibbonaci
			}
			if(deret[matriks3[i][j]-1]>=matriks4[i][j]){//jika deret sebelum akhir lebih besar sama dengan matriks4
				hasil[i][j]=deret[matriks3[i][j]-1];//maka hasil akan menampung nilai deret di indeks matriks3[i][j]-1
			}else{//jika tidak
				hasil[i][j]=matriks4[i][j];//maka hasil akan menampung nilai matriks4
			}
		}
	}
	
}



//prosedur untuk menampilkan hasil
void tampilhasil(int n,int m,int hasil[n][m]){
	
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			printf("%d",hasil[i][j]);//output hasil
			if(j<m-1){
				printf(" ");
			}
		}
		printf("\n");
	}
}
