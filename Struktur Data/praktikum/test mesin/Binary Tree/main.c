#include "header.h"

int main(){
	
	tree T;
	
	char huruf[14];
	
	int i;
	for(i=0;i<14;i++){
		scanf(" %c",&huruf[i]);
	}
	
	makeTree(huruf[0], &T);
	addLeft(huruf[1],&T.root);
	addRight(huruf[2],&T.root);
	addLeft(huruf[3],&T.root->left);
	addRight(huruf[4],&T.root->left);
	addRight(huruf[5],&T.root->right);
	addLeft(huruf[6],&T.root->left->left);
	addRight(huruf[7],&T.root->left->left);
	addRight(huruf[8],&T.root->left->right);
	addLeft(huruf[9],&T.root->right->right);
	addRight(huruf[10],&T.root->right->right);
	addLeft(huruf[11],&T.root->left->left->right);
	addRight(huruf[12],&T.root->left->left->right);
	addLeft(huruf[13],&T.root->right->right->left);
	
	printf("Pre\n");
	jumlahsimpul = hitungsimpul(0,T.root);
	printTreePreOrder(T.root);
	delLeft(&T.root->left->left->right);//L Hilang
	
	printf("In\n");
	jumlahsimpul = hitungsimpul(0,T.root);
	printTreeInOrder(T.root);
	delRight(&T.root->left->right);//I Terhapus
	
	printf("Post\n");
	jumlahsimpul = hitungsimpul(0,T.root);
	printTreePostOrder(T.root);
	
	return 0;
}