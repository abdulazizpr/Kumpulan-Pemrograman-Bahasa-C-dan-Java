#include <stdio.h>

int faktorial(int n){
	//printf("n = %d\n",n);
	if(n==0 || n==1){
		return 1;
	}else{
		return (n*faktorial(n-1));
	}
}

int main(){
	
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	
	int matriks[n][m];
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d",&matriks[i][j]);
		}
	}
	
	long long int matriks2[n][m];
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			matriks2[i][j]=faktorial(matriks[i][j]);
			printf("%lld",matriks2[i][j]);
			if(j<m-1){
				printf(" ");
			}
		}
		printf("\n");
	}
	
	return 0;
}