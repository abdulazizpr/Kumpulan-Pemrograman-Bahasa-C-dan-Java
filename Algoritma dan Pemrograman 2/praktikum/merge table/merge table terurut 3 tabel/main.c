#include "header.h"

int main(){
	
	int n,m,o,i;
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
/////////////////////////////////////////////////////////		
		printf("Masukan data ketiga\t: ");
		scanf("%d",&o);
	int angka3[o];
		printf("Masukan data\t: \n");
		for(i=0;i<o;i++){
			scanf("%d",&angka3[i]);
		}
		
	int angkaurut1[n+m];
	int angkaurut2[n+m+o];
	
	int nau1=n+m;
	int nau2=nau1+o;
	
	merge(angka1,angka2,angkaurut1,n,m);
	merge(angkaurut1,angka3,angkaurut2,nau1,o);
	
	printf("Data terurut\t: ");
	for(i=0;i<nau2;i++){
		printf("%d ",angkaurut2[i]);
	}
			
	return 0;
}