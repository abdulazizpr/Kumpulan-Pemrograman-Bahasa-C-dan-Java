#include <stdio.h>

int faktorial(int n){
	printf("n = %d\n",n);
	if(n==0 || n==1){
		return 1;
	}else{
		return (n*faktorial(n-1));
	}
}

int main(){
	long long int hasil=faktorial(11);
	printf("hasil faktorial: %lld\n",hasil);
	
	return 0;
}