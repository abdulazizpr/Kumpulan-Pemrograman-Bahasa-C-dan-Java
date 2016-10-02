#include "header.h"

int main(){
	
	int n,m,i;
	char pilihan[100];
		scanf("%s",pilihan);
		scanf("%d",&n);
	int angka1[n];
		for(i=0;i<n;i++){
			scanf("%d",&angka1[i]);
		}
/////////////////////////////////////////////////////////		
		scanf("%d",&m);
	int angka2[m];
		for(i=0;i<m;i++){
			scanf("%d",&angka2[i]);
		}
		
	int angkaurut[n+m];
	
	merge(pilihan,angka1,angka2,angkaurut,n,m);
			
	return 0;
}