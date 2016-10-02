#include <stdio.h>

int main(){
	
	int matriks[100][100];
	int matriks2[100][100];
	int matriks3[100][100];
	
	
	int n,m,q,i,j,k;
	scanf("%d %d %d",&n,&m,&q);
	
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&matriks[i][j]);
		}
	}
	
	for(i=0;i<n;i++){
		for(j=0;j<q;j++){
			scanf("%d",&matriks2[i][j]);
		}
	}
	
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			matriks3[i][j]==0;
		}
	}
	
	return 0;
}