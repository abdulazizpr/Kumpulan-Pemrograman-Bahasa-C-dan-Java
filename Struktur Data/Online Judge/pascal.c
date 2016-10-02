#include<stdio.h>
int main(){

	int m;
	int nilai[7][7];
	
	m = 6;
	int a,b;
	for (a=1; a<=m; a++){
		for (b=1; b<=a; b++){
			if (b==1||b==a){
				nilai[a][b]=4;
				printf("%i ", nilai[a][b]);
			}else{
				nilai[a][b]=nilai[a-1][b]+nilai[a-1][b-1];
				printf("%i ", nilai[a][b]);
			}
		}
		printf("\n");
	}
	
}	
	
	