#include "header.h"

void tictac(int matriks[100][100]){
	
	int i,j,k=2;
	int kanan1[100];
	int kanan2[100];
	int bawah1[100];
	int bawah2[100];
	int dgkanan1 = 0;
	int dgkanan2 = 0;
	int dgkiri1 = 0;
	int dgkiri2 = 0;
	int menang;
	
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(matriks[i][j]==1){
				kanan1[i]+=1;
				bawah1[j]+=1;
			}
			if(matriks[i][j]==2){
				kanan2[i]+=2;
				bawah2[j]+=2;
			}
		}
		if(matriks[i][i]==1){
			dgkanan1+=1;
		}
		if(matriks[i][i]==2){
			dgkanan2+=2;
		}
		if(matriks[i][k]==1){
			dgkiri1+=1;
		}
		if(matriks[i][k]==2){
			dgkiri2+=2;
		}
		k--;
	}
	
	int kalah;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(kanan1[i]==3 || bawah1[j]==3){
				kalah = 1;
			}
			if(kanan2[i]==6 || kanan2[j]==6){
				kalah = 2;
			}
		}
	}
	
	if(kalah==1 || dgkanan1==3 || dgkiri1==3){
		printf("P2\n");
	}else if(kalah==2 || dgkanan2==6 || dgkiri2==6){
		printf("P1\n");
	}else{
		printf("P1\n");
		printf("P2\n");
	}
	
	
}