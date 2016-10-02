#include "header.h"

void tictac(titik koordinat1[100],titik koordinat2[100],char pemain[100][100],int matriks1[100][100],int matriks2[100][100]){
	
	int i,j,k;
	int hasil1[100];
	int hasil2[100];
	int hasil3[100];
	int hasil4[100];
	hasil1[0]=0;
	hasil2[0]=0;
	hasil3[0]=0;
	hasil4[0]=0;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(matriks1[i][j]==1){
				hasil1[i]++;
				hasil2[j]++;
			}else if(matriks2[i][j]==2){
				hasil3[i]++;
				hasil4[j]++;
			}
		}
	}
	
	int counter1=0;
	int counter2=0;
	int counter3=0;
	int counter4=0;
	if(matriks1[0][0]==1){
		counter1++;
		if(matriks1[1][1]==1){
			counter1++;
			if(matriks1[2][2]==1){
				counter1++;
			}
		}
	}else if(matriks1[0][2]==1){
		counter2++;
		if(matriks1[1][1]==1){
			counter2++;
			if (matriks1[2][0]==1){
				counter2++;
			}
		}
	}else if(matriks2[0][0]==2){
		counter3++;
		if(matriks2[1][1]==2){
			counter3++;
			if (matriks2[2][2]==2){
				counter3++;
			}
		}
	}else if(matriks2[0][2]==2){
		counter4++;	
		if(matriks2[1][1]==2){
			counter4++;
			if(matriks2[2][0]==2){
				counter4++;
			}
		}
	}
	
	int status;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(hasil1[i]==3 || hasil2[j]==3){
				status=1;
			}else if(hasil3[i]==3 || hasil4[j]==3){
				status=2;
			}
		}
	}
	
	// printf("%d\n",counter1);
	// printf("%d\n",counter2);
	// printf("%d\n",counter3);
	// printf("%d\n",counter4);
	if(status==1 || counter1==3 || counter2==3){
		printf("P1\n");
	}else if(status==2 || counter3==3 || counter4==3){
		printf("P2\n");
	}else{
		printf("tidak ada\n");
	}
	
	// if(hasil1==3){
		// printf("P1\n");
	// }else if(hasil2==12){
		// printf("P2\n");
	// }else{
		// printf("tidak ada\n");
	// }
	
	
}