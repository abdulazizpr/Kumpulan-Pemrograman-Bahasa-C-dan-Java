#include "header.h"

int main(){
	
	
	queue Q;
	createEmpty(&Q);
	
	char raptor[100];
	int waktu_mulai;
	int lama_waktu;
	
	int i;
	for(i=0;i<4;i++){
		scanf("%s %d %d",&raptor,&waktu_mulai,&lama_waktu);
		add(raptor,waktu_mulai,lama_waktu,&Q);
	}
	
	
	printQueue(Q);
	
	return 0;
}