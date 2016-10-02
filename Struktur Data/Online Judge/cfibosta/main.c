#include "header.h"

int main(){
	
	int a,b;
	scanf("%d",&n);
	scanf("%d",&a);
	scanf("%d",&b);
	
	stack S;
	createEmpty(&S);
	
	int arr[n+1];
	
	fib(arr, n, a, b,0);
	int i=0;
	for(i=0;i<n;i++){
		push(arr[i],&S);
	}
	
	printStack(S);
	
	return 0;
}