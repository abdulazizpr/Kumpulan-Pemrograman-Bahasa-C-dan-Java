#include <stdio.h>

int main(){

	int n,i,j;
	scanf("%d",&n);
	
	//wilayah 1(satu baris)
		//spasi
		for(j=1;j<=n;j++){
			printf(" ");
		}
		//*
		for(j=1;j<=n;j++){
			printf("*");
		}
		//spasi
		for(j=1;j<=n+1;j++){
			printf(" ");
		}
		//spasi
		for(j=1;j<n-2;j++){
			printf(" ");
		}
		//*
		for(j=1;j<=n;j++){
			printf("*");
		}
	printf("\n");

	for(i=1;i<n;i++){//wilayah 2
		//spasi
		for(j=i;j<n-1;j++){
			printf(" ");
		}
		//*
		for(j=1;j<i+1;j++){
			printf("*");
		}
		//*
		for(j=0;j<=n;j++){
			printf("*");
		}
		//spasi
		for(j=1;j<=n+1;j++){
			printf(" ");
		}
		//spasi
		for(j=1;j<i+1;j++){
			printf(" ");
		}
		//spasi
		for(j=1;j<n-2;j++){
			printf(" ");
		}
		//*
		for(j=1;j<=n;j++){
			printf("*");
		}
	printf("\n");	
	}
	
	for(i=1;i<n;i++){//wilayah 3
		//spasi
		for(j=1;j<=n;j++){
			printf(" ");
		}
		//spasi
		for(j=1;j<i;j++){
			printf(" ");
		}
		//*
		for(j=1;j<=n;j++){
			printf("*");
		}
		for(j=i;j<n;j++){
			printf(" ");
		}
		for(j=i;j<n-1;j++){
			printf(" ");
		}
		//*
		for(j=1;j<=n;j++){
			printf("*");
		}
	printf("\n");
	}

	//wilayah 4
	//spasi
		for(j=1;j<=n+2;j++){
			printf(" ");
		}
		//spasi
		for(j=1;j<n-2;j++){
			printf(" ");
		}
		//*
		for(j=1;j<=n+2;j++){
			printf("*");
		}
		for(j=1;j<n-2;j++){
			printf("*");
		}
	printf("\n");	
	
	for(i=1;i<=n;i++){//wilayah 5
		//spasi
		for(j=i;j<=n;j++){
			printf(" ");
		}
		//*
		for(j=1;j<=n;j++){
			printf("*");
		}
		//spasi
		for(j=1;j<i;j++){
			printf(" ");
		}
		//spasi
		for(j=1;j<=n;j++){
			printf(" ");
		}
		//spasi
		for(j=1;j<n-2;j++){
			printf(" ");
		}
		//spasi
		for(j=1;j<i;j++){
			printf(" ");
		}
		//*
		for(j=1;j<=n;j++){
			printf("*");
		}
	printf("\n");	
	}

return 0;
}
