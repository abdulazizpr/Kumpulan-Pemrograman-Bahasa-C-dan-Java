#include <stdio.h>
#include <string.h>

int main(){
	
	int i,j,k;
	char kata[100][100];
	
	i=0;
	do{
		i++;
		scanf("%s",&kata[i]);
		
	}while(strcmp(kata[i],"selesai")!=0);
	
	
	
return 0;
}
