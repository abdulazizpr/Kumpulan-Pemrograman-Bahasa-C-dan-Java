#include <stdio.h>
#include <string.h>


int main(){

	int n,i,j,jumlahhuruf=0,x=0;
	scanf("%d",&n);
	
	char nama[n][100];
	char gabung[100];
	
	for(i=0;i<n;i++){
		scanf("%s",&nama[i]);
		for(j=0;j<strlen(nama[i]);j++){
			if(nama[i][j]>='a' & nama[i][j]<='z'){
				jumlahhuruf++;
			}
			gabung[x]=nama[i][j];
			x++;
		}
	}
	
	int sama=0;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(nama[i]==nama[j]){
				sama++;
			}
		}
	}
	
	int spasi=0;
	if(jumlahhuruf%2==0 && sama==0){
		for(i=0;i<x/2;i++){
			printf("%c",gabung[i]);
		}
		printf("\n");
		for(i=x-(x/2);i<x;i++){
			for(j=spasi;j<(x/2)-1;j++){
				printf(" ");
			}
			printf("%c\n",gabung[i]);
			spasi++;
		}
	}else{
		printf("tidak valid\n");
	}
	

return 0;	
}
