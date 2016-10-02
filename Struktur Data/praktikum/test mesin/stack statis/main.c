#include "header.h"

int main(){
	
	
	stack S;
	createEmpty(&S);
	
	int i;
	char huruf[5];
	for(i=0;i<5;i++){
		scanf(" %c",&huruf[i]);
	}
	
	push(huruf[0],&S);
	push(huruf[1],&S);
	printStack(S);
	push(huruf[2],&S);
	push(huruf[3],&S);
	printStack(S);
	pop(&S);
	pop(&S);
	push(huruf[4],&S);
	printStack(S);
	
	return 0;
}