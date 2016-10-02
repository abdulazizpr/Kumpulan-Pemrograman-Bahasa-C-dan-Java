#include "header.h"

typedef struct{
	int x;
	int y;
}titik;

int main(){
	
	int i,j,k;
	titik koordinat1[100];
	titik koordinat2[100];
	char pemain[100][100];
	char tanda[100][100];
	int matriks1[100][100];
	int matriks2[100][100];
	
	for(i=0;i<6;i++){
		scanf("%s",&pemain[i]);
		if(strcmp(pemain[i],"P1")==0){
			scanf(" %c",&tanda[i]);
			scanf("%d",&koordinat1[i].x);
			scanf("%d",&koordinat2[i].y);
			matriks1[koordinat1[i].x][koordinat2[i].y]=1;
		}else if(strcmp(pemain[i],"P2")==0){
			scanf(" %c",&tanda[i]);
			scanf("%d",&koordinat1[i].x);
			scanf("%d",&koordinat2[i].y);
			matriks2[koordinat1[i].x][koordinat2[i].y]=2;
		}
		
	}
	
	tictac(koordinat1,koordinat2,pemain,tanda,matriks1,matriks2);	
	
	return 0;
}