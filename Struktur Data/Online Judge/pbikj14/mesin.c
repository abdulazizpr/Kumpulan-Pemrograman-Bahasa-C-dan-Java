#include "header.h"

void makeTree(int c,tree *T){
	
	simpul *node = (simpul *) malloc (sizeof (simpul));
	node->nilai = c;
	node->right = NULL;
	node->left = NULL;
	(*T).root = node;
}

void addRight(int c,simpul **root){
	
	if((*root)->right == NULL){
		/*jika sub pohon kanan kosong*/
		simpul *node = (simpul *) malloc (sizeof (simpul));
		node->nilai = c;
		node->right = NULL;
		node->left = NULL;
		(*root)->right = node;
	}
	else printf("sub pohon kanan telah terisi");
	
}

void addLeft(int c,simpul **root){
	
	if((*root)->left == NULL){
		/*jika sub pohon kanan kosong*/
		simpul *node = (simpul *) malloc (sizeof (simpul));
		node->nilai = c;
		node->right = NULL;
		node->left = NULL;
		(*root)->left = node;
	}
	else printf("sub pohon kanan telah terisi");
	
}

void delRight(simpul **root){
	
	simpul *node = (*root)->right;
	(*root)->right = NULL;
	free(node);
	
}

void delLeft(simpul **root){
	
	simpul *node = (*root)->left;
	(*root)->left = NULL;
	free(node);

}

void printTreePreOrder(simpul *root){
	
	if(root != NULL){
		printf(" %d",root->nilai);
		printTreePreOrder(root->left);
		printTreePreOrder(root->right);
	}
	
}

void printTreeInOrder(simpul *root){
	
	if(root != NULL){
		
		printTreeInOrder(root->left);
		printf(" %d",root->nilai);
		printTreeInOrder(root->right);
		
	}
	
}

void printTreePostOrder(simpul *root){
	
	if(root != NULL){
		
		printTreePostOrder(root->left);
		printTreePostOrder(root->right);
		printf(" %d",root->nilai);
		
	}
	
}

void printTreeLevelOrderNext(simpul *root){
	
	if(root != NULL){
		
		if(root->left != NULL) printf(" %d",root->left->nilai);
		if(root->right != NULL) printf(" %d",root->right->nilai);
		if(root->left != NULL) printTreeLevelOrderNext(root->left);
		if(root->right != NULL) printTreeLevelOrderNext(root->right);
	
	}
	
}

void printTreeLevelOrder(simpul *root){
	
	if(root != NULL){
		
		printf(" %d",root->nilai);
		printTreeLevelOrderNext(root);
		
	}
	
}


void copyTree(simpul *root1,simpul **root2){
	
	if(root1 != NULL){
		
		(*root2) = (simpul *) malloc (sizeof (simpul));
		(*root2)->nilai = root1->nilai;
		if(root1->left != NULL) copyTree(root1->left,&(*root2)->left);
		if(root1->right != NULL) copyTree(root1->right,&(*root2)->right);
		
	}
	
}

int isEqual(simpul *root1,simpul *root2){
	
	int hasil = 1;
	if(root1 != NULL && root2 != NULL){
		if(root1->nilai != root2->nilai) hasil = 0;
		else{
			isEqual(root1->left,root2->left);
			isEqual(root1->right,root2->right);
		}
	}else{
		if(root1 != NULL || root2 != NULL) hasil = 0;
	}	
	
	return hasil;
	
}

simpul* cariSimpul(int nilai,simpul* root){
	simpul* cari = NULL;
	if(root->nilai== nilai){
		cari = root;
	}else{
		if(root->left != NULL && cari == NULL){
			cari = cariSimpul(nilai,root->left);//cari ke anak cabang kiri
		}
		if(root->right != NULL && cari == NULL){
			cari = cariSimpul(nilai,root->right);//cari ke anak cabang kanan
		}
	}
	return cari;
}

int jumlahsimpulkiri(int hasil,simpul *root){
	
	if(root != NULL){
		//printf("Akar : %d\n",root->nilai);
		if(root->left != NULL){
			//printf("kiri : %d\n",root->left->nilai);
			hasil =  jumlahsimpulkiri(hasil,root->left); //hitung ke anak cabang kiri
		}
		if(root->right != NULL){
			//printf("kanan : %d\n",root->right->nilai);
			hasil =  jumlahsimpulkiri(hasil,root->right);//hitung ke anak cabang kanan
		}
		
		return hasil+root->nilai;
	}else{
		return 0;
	}
	
}	
	