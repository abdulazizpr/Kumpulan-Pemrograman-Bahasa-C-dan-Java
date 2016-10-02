#include <stdio.h>

int main(){

	int n,i,j;
	scanf("%d",&n);
	
	for(i=1;i<=n;i++){//wilayah 1
		for(j=0;j<i;j++){
			printf("*");
		}
		for(j=i;j<n;j++){
			printf("-");
		}
		for(j=1;j<=n*2;j++){
			printf("-");
		}
		for(j=i;j<n;j++){
			printf("-");
		}
		for(j=0;j<i;j++){
			printf("*");
		}
		printf("\n");
	}

return 0;	
}