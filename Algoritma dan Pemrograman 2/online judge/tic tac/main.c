#include "header.h"

int main(){
	
	int i,j,k;
	titik koordinat;
	char pemain[100][100];
	char tanda[100];
	int matriks[100][100];
	
	for(i=0;i<6;i++){
		scanf("%s",&pemain[i]);
		if(strcmp(pemain[i],"P1")==0){
			scanf("%s",&tanda);
			scanf("%d",&koordinat.x);
			scanf("%d",&koordinat.y);
			matriks[koordinat.x][koordinat.y]=1;
		}else if(strcmp(pemain[i],"P2")==0){
			scanf("%s",&tanda);
			scanf("%d",&koordinat.x);
			scanf("%d",&koordinat.y);
			matriks[koordinat.x][koordinat.y]=2;
		}
		
	}
	
	tictac(matriks);	
	
	return 0;
}