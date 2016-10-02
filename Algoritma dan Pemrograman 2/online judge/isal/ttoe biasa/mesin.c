#include "header.h"

void status(tiktak prog[100]){
	int i,j;
	char matriks[100][100];
	for(i=0;i<6;i++){
		if(prog[i].nama[1]=='1'){
			matriks[prog[i].x][prog[i].y]='O';
		}else{
			matriks[prog[i].x][prog[i].y]='X';
		}
	}
	int c1;
	int c2;
	int status=0;
	if(status==0){
		for(i=0;i<3;i++){
			c1=0;
			c2=0;
			for(j=0;j<3;j++){
				if(matriks[i][j]=='O'){
					c1++;
				}else if(matriks[i][j]=='X'){
					c2++;
				}
			}
			if(c1==3){
				status=1;
				printf("P1\n");
			}else if(c2==3){
				status=1;
				printf("P2\n");
			}
		}
	}
	if(status==0){
		for(i=0;i<3;i++){
			c1=0;
			c2=0;
			for(j=0;j<3;j++){
				if(matriks[j][i]=='O'){
					c1++;
				}else if(matriks[j][i]=='X'){
					c2++;
				}
			}
			if(c1==3){
				status=1;
				printf("P1\n");
			}else if(c2==3){
				status=1;
				printf("P2\n");
			}
		}
	}
	if(status==0){
		j=0;
		c1=0;
		c2=0;
		for(i=0;i<3;i++){
			if(matriks[i][j]=='O'){
				c1++;
			}else if(matriks[i][j]=='X'){
				c2++;
			}
			j++;
		}
	
		if(c1==3){
			status=1;
			printf("P1\n");
		}else if(c2==3){
			status=1;
			printf("P2\n");
		}
	}
	if(status==0){
		j=0;
		c1=0;
		c2=0;
		for(i=2;i>=0;i--){
			if(matriks[i][j]=='O'){
				c1++;
			}else if(matriks[i][j]=='X'){
				c2++;
			}
			j++;
		}
		if(c1==3){
			status=1;
			printf("P1\n");
		}else if(c2==3){
			status=1;
			printf("P2\n");
		}
	}
	if(status!=1){
		printf("tidak ada\n");
	}
}