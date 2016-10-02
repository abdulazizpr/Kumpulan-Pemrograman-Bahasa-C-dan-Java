#include "header.h"

int main(){
	int i;
	tiktak prog[100];
	for(i=0;i<6;i++){
		scanf("%s",&prog[i].nama);
		scanf(" %c",&prog[i].bentuk);
		scanf("%d",&prog[i].x);
		scanf("%d",&prog[i].y);
	}
	status(prog);
	return 0;
}