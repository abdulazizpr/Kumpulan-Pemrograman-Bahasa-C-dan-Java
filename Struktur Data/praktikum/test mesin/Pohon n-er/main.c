#include "header.h"

int main(){
	
	char masukan[100];
	scanf("%s",&masukan);

	tree T;
	makeTree('A',&T);
	addChild('B',T.root);
	delChild('B',T.root);
	addChild('C',T.root);
	addChild('D',T.root);
	addChild('E',T.root->child);
	addChild('F',T.root->child->child);
	addChild('G',T.root->child);
	addChild('H',T.root);

	printTreePreOrder(T.root);
	printf(" ");
	printf("\n");
	delChild('H',T.root);

	printTreePreOrder(T.root);
	printf(" ");
	printf("\n");
	addChild('I',T.root->child);
	addChild('J',T.root->child->child);

	printTreePreOrder(T.root);
	printf(" ");
	printf("\n");
	
	simpul *node = findSimpul('C',T.root);
	if(node!=NULL){
		printf("ditemukan C\n");
	}else{
		printf("tidak ditemukan\n");
	}
	node = findSimpul('C',T.root->child->child);
	if(node!=NULL){
		printf("ditemukan C\n");
	}else{
		printf("tidak ditemukan\n");
	}
	
	
	return 0;
}