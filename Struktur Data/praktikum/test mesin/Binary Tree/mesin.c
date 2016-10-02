#include "header.h"

void makeTree(char c,tree *T){
	
	simpul *node = (simpul *) malloc (sizeof (simpul));
	node->info = c;
	node->right = NULL;
	node->left = NULL;
	(*T).root = node;
}

void addRight(char c,simpul **root){
	
	if((*root)->right == NULL){
		/*jika sub pohon kanan kosong*/
		simpul *node = (simpul *) malloc (sizeof (simpul));
		node->info = c;
		node->right = NULL;
		node->left = NULL;
		(*root)->right = node;
	}
	else printf("sub pohon kanan telah terisi");
	
}

void addLeft(char c,simpul **root){
	
	if((*root)->left == NULL){
		/*jika sub pohon kanan kosong*/
		simpul *node = (simpul *) malloc (sizeof (simpul));
		node->info = c;
		node->right = NULL;
		node->left = NULL;
		(*root)->left = node;
	}
	else printf("sub pohon kanan telah terisi");
	
}

void delRight(simpul **root){
	if((*root)->right != NULL){
		if((*root)->right->left ==NULL || (*root)->right->right==NULL){
			simpul *node = (*root)->right;
			(*root)->right = NULL;
			free(node);
		}
	}
	
}

void delLeft(simpul **root){
	if((*root)->left != NULL){
		if((*root)->left->left==NULL || (*root)->left->right==NULL){
			simpul *node = (*root)->left;
			(*root)->left = NULL;
			free(node);
		}
	}
}

int hitungsimpul(int hasil,simpul *root){
	
	if(root != NULL){
		hasil++;
		hasil=hitungsimpul(hasil,root->left);
		hasil=hitungsimpul(hasil,root->right);
	
	}
	
	return hasil;
}

void printTreePreOrder(simpul *root){
	
	if(root != NULL){
		printf("%c",root->info);
		if(jumlahsimpul != 1){
			printf(" - ");
		}else{
			printf("\n");
		}
		jumlahsimpul--;
		
		printTreePreOrder(root->left);
		printTreePreOrder(root->right);
	}
	
}

void printTreeInOrder(simpul *root){
	
	if(root != NULL){
		printTreeInOrder(root->left);
		printf("%c",root->info);
		if(jumlahsimpul != 1){
			printf(" - ");
		}else{
			printf("\n");
		}
		jumlahsimpul--;
		printTreeInOrder(root->right);
		
	}
	
}

void printTreePostOrder(simpul *root){
	
	if(root != NULL){
		printTreePostOrder(root->left);
		printTreePostOrder(root->right);
		printf("%c",root->info);
		if(jumlahsimpul != 1){
			printf(" - ");
		}else{
			printf("\n");
		}
		jumlahsimpul--;
	}
	
}

void printTreeLevelOrderNext(simpul *root){
	
	if(root != NULL){
		
		if(root->left != NULL) printf(" %c",root->left->info);
		if(root->right != NULL) printf(" %c",root->right->info);
		if(root->left != NULL) printTreeLevelOrderNext(root->left);
		if(root->right != NULL) printTreeLevelOrderNext(root->right);
	
	}
	
}

void printTreeLevelOrder(simpul *root){
	
	if(root != NULL){
		
		printf(" %c",root->info);
		printTreeLevelOrderNext(root);
		
	}
	
}


void copyTree(simpul *root1,simpul **root2){
	
	if(root1 != NULL){
		
		(*root2) = (simpul *) malloc (sizeof (simpul));
		(*root2)->info = root1->info;
		if(root1->left != NULL) copyTree(root1->left,&(*root2)->left);
		if(root1->right != NULL) copyTree(root1->right,&(*root2)->right);
		
	}
	
}

int isEqual(simpul *root1,simpul *root2){
	
	int hasil = 1;
	if(root1 != NULL && root2 != NULL){
		if(root1->info != root2->info) hasil = 0;
		else{
			isEqual(root1->left,root2->left);
			isEqual(root1->right,root2->right);
		}
	}else{
		if(root1 != NULL || root2 != NULL) hasil = 0;
	}	
	
	return hasil;
	
}