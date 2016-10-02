#include <stdio.h>
#include <string.h>

int main(){
	
	char input[100][100];
	char temp[100];
	int i, tukar, n;
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		scanf("%s",&input[i]);
	}
	
	do{
		tukar=0;
		
		for(i=0;i<n-1;i++){
			if(strcmp(input[i],input[i+1])==1){
				strcpy(temp,input[i]);
				strcpy(input[i],input[i+1]);
				strcpy(input[i+1],temp);
				tukar=1;
			}
		}
		
	}while(tukar==1);
	
	printf("\n");
	for(i=0;i<n;i++){
		printf("%s\n",input[i]);
	}
	
	return 0;
}