#include "header.h"

int main(){
	
	int n,m,i;
		printf("Masukan data pertama\t: ");
		scanf("%d",&n);
	int angka1[n];
		printf("Masukan data\t: \n");
		for(i=0;i<n;i++){
			scanf("%d",&angka1[i]);
		}
/////////////////////////////////////////////////////////		
		printf("Masukan data kedua\t: ");
		scanf("%d",&m);
	int angka2[m];
		printf("Masukan data\t: \n");
		for(i=0;i<m;i++){
			scanf("%d",&angka2[i]);
		}
		
	int angkaurut[n+m];
	
	merge(angka1,angka2,angkaurut,n,m);
	
	printf("Data terurut\t: ");
	for(i=0;i<n+m;i++){
		printf("%d ",angkaurut[i]);
	}
			
	return 0;
}