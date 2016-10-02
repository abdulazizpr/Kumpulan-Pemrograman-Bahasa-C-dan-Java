#include <stdio.h>

int fib2(int* arr,int n){
	if(n<2){
		arr[n]=n;
		return n;
	}else{
		arr[n]=fib2(arr,n-1)+fib2(arr,n-2);
		return arr[n];
	}
}

int main(){
	int n;
	printf("masukan bilangan fibbonaci ");
	scanf("%d",&n);
	int arr[n];
	
	fib2(arr,n);
	int i=0;
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	
	return 0;
}