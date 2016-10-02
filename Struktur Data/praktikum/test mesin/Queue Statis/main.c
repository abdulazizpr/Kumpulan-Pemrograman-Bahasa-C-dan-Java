#include "header.h"

int main(){
	
	queue Q;
	createEmpty(&Q);
	
	char huruf[8];
	int i;
	for(i=0;i<8;i++){
		scanf(" %c",&huruf[i]);
	}
	
	printQueue(Q);
	add(huruf[0],&Q);
	add(huruf[1],&Q);
	add_prioritas(huruf[2],3,&Q);
	printQueue(Q);
	add(huruf[3],&Q);
	printQueue(Q);
	del(&Q);
	del(&Q);
	del(&Q);
	add(huruf[4],&Q);
	add(huruf[5],&Q);
	add_prioritas(huruf[6],2,&Q);
	printQueue(Q);
	del(&Q);
	add(huruf[7],&Q);
	printQueue(Q);
	
	return 0;
}