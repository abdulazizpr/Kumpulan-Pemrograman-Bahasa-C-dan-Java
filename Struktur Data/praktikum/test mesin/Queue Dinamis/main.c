#include "header.h"

int main(){
	
	
	queue Q;
	createEmpty(&Q);
	
	
	char huruf[7];
	int i;
	for(i=0;i<7;i++){
		scanf(" %c",&huruf[i]);
	}
	
	printQueue(Q);
	add(huruf[0],&Q);
	add(huruf[1],&Q);
	add(huruf[2],&Q);
	add_prioritas(huruf[3],3,&Q);
	add(huruf[4],&Q);
	printQueue(Q);
	
	del(&Q);
	del(&Q);
	del(&Q);
	printQueue(Q);
	add_prioritas(huruf[5],2,&Q);
	add(huruf[6],&Q);
	printQueue(Q);
	
	return 0;
}