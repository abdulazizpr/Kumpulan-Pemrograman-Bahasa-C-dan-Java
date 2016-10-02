#include "header.h"

int main(){
	
	int n,i;
	
	/*input*/
	printf("Masukan banyak angka : ");
	scanf("%d",&n);
	
	int angka[n];
	printf("Masukan angka : \n");
	for(i=0;i<n;i++){
		scanf("%d",&angka[i]);
	}
	
	insertion(angka,n);
	
	return 0;
}