#include <stdio.h>

void bintang(int n){
	if(n>0){
		printf("*");
		bintang(n-1);
	}
}

void spasi(int n){
	if(n>0){
		printf(" ");
		spasi(n-1);
	}
}

void diamonatas(int n,int m,int o){
	if(m>0 && o<n){
		bintang(m);
		spasi(o);
		spasi(o);
		bintang(m);
		printf("\n");
		diamonatas(n,m-1,o+1);
	}
}

void diamonbawah(int n,int m,int o){
	if(m>0 && o<=n){
		bintang(o);
		spasi(m-1);
		spasi(m-1);
		bintang(o);
		printf("\n");
		diamonbawah(n,m-1,o+1);
	}
}

int main(){
	
	int n;
	scanf("%d",&n);
	diamonatas(n,n,0);
	diamonbawah(n,n,1);
	
	
	return 0;
}