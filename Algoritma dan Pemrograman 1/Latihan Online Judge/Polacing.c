#include <stdio.h>

/*
Saya Abdul Aziz Priatna(1307123) tidak melakukan kecurangan seperti yang telah dispesifikasikan pada mata kuliah 
Algoritma dan Pemrograman I dalam mengerjakan TP4, jika saya melakukan kecurangan maka Allah/Tuhan adalah saksi saya, 
dan saya bersedia menerima 
hukumanNya. Aamiin.
*/

int main(){

	int n, i, j;//variabel
		scanf("%d",&n);//inputan
	
	//proses
	for(i=1;i<=n;i++){//wilayah 1
		//spasi
		for(j=i;j<n+2;j++){
			printf(" ");
		}
		//*
		for(j=0;j<i;j++){
			printf("*");
		}
		//*
		for(j=0;j<i;j++){
			printf("*");
		}
		//spasi
		for(j=n-i;j>0;j--){
			printf(" ");
		}
		//spasi
		for(j=1;j<=(n*3)-3;j++){
			printf(" ");
		}
		//spasi
		for(j=n-i;j>0;j--){
			printf(" ");
		}
		//*
		for(j=0;j<i;j++){
			printf("*");
		}
		//*
		for(j=0;j<i;j++){
			printf("*");
		}
	printf("\n");	
	}
	
	for(i=1;i<=n;i++){//wilayah 2
		//*
		for(j=1;j<=(n*7)+1;j++){
			printf("*");
		}
	printf("\n");
	}
	
	for(i=1;i<=n;i++){//wilayah 3
		//spasi
		for(j=0;j<i-1;j++){
			printf(" ");
		}
		//*
		for(j=i;j<=n;j++){
			printf("*");
		}
		//*
		for(j=1;j<=(n*5)+1;j++){
			printf("*");
		}
		//*
		for(j=i;j<=n;j++){
			printf("*");
		}
	printf("\n");	
	}
	
	for(i=1;i<=n;i++){//wilayah 4
		//spasi
		for(j=1;j<=n*2;j++){
			printf(" ");
		}
		//spasi
		for(j=0;j<i+1;j++){
			printf(" ");
		}
		//*
		for(j=i;j<=n;j++){
			printf("*");
		}
		//*
		for(j=1;j<n-2;j++){
			printf("*");
		}
		//*
		for(j=i;j<=n;j++){
			printf("*");
		}
	printf("\n");
	}

return 0;
}
