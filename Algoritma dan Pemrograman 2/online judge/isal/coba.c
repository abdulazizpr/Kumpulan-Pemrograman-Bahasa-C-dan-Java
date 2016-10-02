#include <stdio.h>
#include <string.h>

int main(){

	char player[100][100];
	char simbol[100];
	int x, y, n, i, j, k=2;
	int tanda1[100][100];
	int kanan1[100];
	int kanan2[100];
	int bawah1[100];
	int bawah2[100];
	int dgkanan1 = 0;
	int dgkanan2 = 0;
	int dgkiri1 = 0;
	int dgkiri2 = 0;
	int menang;

	for(n=0; n<6; n++){
		scanf("%s", &player[n]);
		if(strcmp(player[n],"P1")){
			scanf("%s", &simbol);
			scanf("%d", &x);
			scanf("%d", &y);
			tanda1[x][y] = 1;
		}
		if(strcmp(player[n],"P2")){
			scanf("%s", &simbol);
			scanf("%d", &x);
			scanf("%d", &y);
			tanda1[x][y] = 2;
		}
	}

	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			if(tanda1[i][j]==1){
				kanan1[i]+=1;
				bawah1[j]+=1;
			}
			if(tanda1[i][j]==2){
				kanan2[i]+=2;
				bawah2[j]+=2;
			}
		}
		if(tanda1[i][i]==1){
			dgkanan1+=1;
		}
		if(tanda1[i][i]==2){
			dgkanan2+=2;
		}
		if(tanda1[i][k]==1){
			dgkiri1+=1;
		}
		if(tanda1[i][k]==2){
			dgkiri2+=2;
		}
		k--;
	}

	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			if(kanan1[i]==3 || bawah1[j]==3){
				menang = 1;
			}
			if(kanan2[i]==6 || bawah2[j]==6){
				menang = 2;
			}
		}
	}

	if(menang==1 || dgkanan1==3 || dgkiri1==3){
		printf("P2\n");
	}
	else if(menang==2 || dgkanan2==6 || dgkiri2==6){
		printf("P1\n");
	}
	else{
		printf("tidak ada\n");
	}


	return 0;
}
