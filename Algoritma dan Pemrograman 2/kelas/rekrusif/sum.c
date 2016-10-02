#include <stdio.h>

int sum(int n){
	
	printf("n = %d\n",n);
	
	if(n==1){
		return 1;
	}else{
		return n=n+sum(n-1);
	}
	
}

int main(){
	int hasil=sum(4);
	printf("hasilnya adalah %d",hasil);
	
	return 0;
}