#include <stdio.h>

typedef struct{int a,b;}bungkusan;

int main(){
	
	int n,m,i;
	scanf("%d",&n);
	scanf("%d",&m);
	bungkusan tabel1[n];
	bungkusan tabel2[m];
	bungkusan tabel3[n+m];
	
	printf("Masukan Tabel Bungkusan Pertama : \n");
	for(i=0;i<n;i++){
		scanf("%d %d",&tabel1[i].a,&tabel1[i].b);
	}
	
	printf("Masukan Tabel Bungkusan Kedua : \n");
	for(i=0;i<m;i++){
		scanf("%d %d",&tabel2[i].a,&tabel2[i].b);
	}
	
	for(i=0;i<n;i++){
		tabel3[i]=tabel1[i];
	}
	
	for(i=n;i<n+m;i++){
		tabel3[i]=tabel2[i-n];
	}
	
	printf("Hasil Merge Table : \n");
	for(i=0;i<n+m;i++){
		printf("%d %d\n",tabel3[i].a,tabel3[i].b);
	}
	
	return 0;
}