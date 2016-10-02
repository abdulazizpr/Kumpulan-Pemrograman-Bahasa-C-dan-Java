#include "header.h"

int main(){
	int status=0;
	int status1=0;
	int i,j,n,m;
	char K,B;
	int a[100];
	int b[100];
	while(status!=1){
		scanf("%c",&K);
		if (K=='K'){
			status=1;
		}
	}
	
	if(status==1){
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
	}
	while(status1!=1){
		scanf("%c",&B);
		if (B=='B'){
			status1=1;
		}
	}
	if(status1==1){
		scanf("%d",&m);
		for(i=0;i<m;i++){
			scanf("%d",&b[i]);
		}
	}
	long long int hasilk[n];
	long long int hasilb[m];
	for(i=0;i<n;i++){
		hasilk[i]=faktor(a[i]);
	}
	for(i=0;i<m;i++){
		hasilb[i]=faktor(b[i]);
	}
	long long int matriks[n][m];
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			matriks[j][i]=hasilk[j]*hasilb[i];
			printf("%lld\n",matriks[j][i]);
		}
	}

	
	return 0;
}