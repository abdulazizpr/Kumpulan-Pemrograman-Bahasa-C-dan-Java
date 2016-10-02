#include <stdio.h>

int main(){
	
	int n,m;
	scanf("%d",&n);
	scanf("%d",&m);
	int tabel1[n];
	int tabel2[m];
	int tabel3[n+m];
	
	int i;
	for(i=0;i<n;i++){
		printf("Masukan angka : \n");
		scanf("%d",&tabel1[i]);
	}
	
	for(i=0;i<m;i++){
		printf("Masukan angka : \n");
		scanf("%d",&tabel2[i]);
	}
	
	for(i=0;i<n;i++){
		tabel3[i]=tabel1[i];
	}
	
	for(i=n;i<n+m;i++){
		tabel3[i]=tabel2[i-n];
	}
	
	printf("Hasil merge tabel : \n");
	for(i=0;i<n+m;i++){
		printf("%d\n",tabel3[i]);
	}
	
	
	
	return 0;
}