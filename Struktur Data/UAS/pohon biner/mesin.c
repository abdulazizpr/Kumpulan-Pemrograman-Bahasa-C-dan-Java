#include "header.h"

void makeTree(char info,tree *T){
	
	simpul *node = (simpul *) malloc (sizeof (simpul));
	node->data.info = info;

	node->right = NULL;
	node->left = NULL;
	(*T).root = node;
}

void addRight(char info,simpul **root){
	
	if((*root)->right == NULL){
		/*jika sub pohon kanan kosong*/
		simpul *node = (simpul *) malloc (sizeof (simpul));
		node->data.info = info;
		
		node->right = NULL;
		node->left = NULL;
		(*root)->right = node;
	}
	else printf("sub pohon kanan telah terisi");
	
}

void addLeft(char info,simpul **root){
	
	if((*root)->left == NULL){
		/*jika sub pohon kanan kosong*/
		simpul *node = (simpul *) malloc (sizeof (simpul));
		node->data.info = info;
	
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
		printf("%c ",root->data.info);
		printTreePreOrder(root->left);
		printTreePreOrder(root->right);
	}
	
}

void printTreeInOrder(simpul *root){
	
	if(root != NULL){
		
		printTreeInOrder(root->left);
		printf("%c ",root->data.info);
		printTreeInOrder(root->right);
		
	}
	
}

void printTreePostOrder(simpul *root){
	
	if(root != NULL){
		
		printTreePostOrder(root->left);
		printTreePostOrder(root->right);
		printf("%c ",root->data.info);
		
	}
	
}

void printTreeLevelOrderNext(simpul *root){
	
	if(root != NULL){
		
		if(root->left != NULL) printf("%c ",root->left->data.info);
		if(root->right != NULL) printf("%c ",root->right->data.info);
		if(root->left != NULL) printTreeLevelOrderNext(root->left);
		if(root->right != NULL) printTreeLevelOrderNext(root->right);
	
	}
	
}

void printTreeLevelOrder(simpul *root){
	
	if(root != NULL){
		
		printf("%c ",root->data.info);
		printTreeLevelOrderNext(root);
		
	}
	
}


void copyTree(simpul *root1,simpul **root2){
	
	if(root1 != NULL){
		
		(*root2) = (simpul *) malloc (sizeof (simpul));
		(*root2)->data = root1->data;
		if(root1->left != NULL) copyTree(root1->left,&(*root2)->left);
		if(root1->right != NULL) copyTree(root1->right,&(*root2)->right);
		
	}
	
}

int isEqual(simpul *root1,simpul *root2){
	
	int hasil = 1;
	if(root1 != NULL && root2 != NULL){
		if(root1->data.info != root2->data.info) hasil = 0;
		else{
			isEqual(root1->left,root2->left);
			isEqual(root1->right,root2->right);
		}
	}else{
		if(root1 != NULL || root2 != NULL) hasil = 0;
	}	
	
	return hasil;
	
}

simpul* cariSimpul(char info,simpul* root){
	simpul* cari = NULL;
	if(root->data.info == info){
		cari = root;
	}else{
		if(root->left != NULL && cari == NULL){
			cari = cariSimpul(info,root->left);//cari ke anak cabang kiri
		}
		if(root->right != NULL && cari == NULL){
			cari = cariSimpul(info,root->right);//cari ke anak cabang kanan
		}
	}
	return cari;
}

int jumlahsimpul(int hasil,simpul *root){
	
	if(root != NULL){
		//printf("Akar : %d\n",root->nilai);
		if(root->left != NULL){
			//printf("kiri : %d\n",root->left->nilai);
			hasil =  jumlahsimpul(hasil,root->left); //hitung ke anak cabang kiri
		}
		if(root->right != NULL){
			//printf("kanan : %d\n",root->right->nilai);
			hasil =  jumlahsimpul(hasil,root->right);//hitung ke anak cabang kanan
		}
		
		return hasil;//+root->data.nilai;
	}else{
		return 0;
	}
	
}

int simpulgenap(int hasil,simpul *root){
	
	if(root != NULL){
		//printf("Akar : %d\n",root->nilai);
		if(root->left != NULL){
			//printf("kiri : %d\n",root->left->nilai);
			hasil =  jumlahsimpul(hasil,root->left); //hitung ke anak cabang kiri
		}
		if(root->right != NULL){
			//printf("kanan : %d\n",root->right->nilai);
			hasil =  jumlahsimpul(hasil,root->right);//hitung ke anak cabang kanan
		}
		
		return hasil;//+root->data.nilai;
	}else{
		return 0;
	}
	
}

int caripohonlengkap(simpul *root){
	
	int hasil = 1;
	if(root->left != NULL){
		if(root->right != NULL) hasil = 0;//jika kiri kanan tidak kosong maka hasil 0	
	}
	
	if(root->left != NULL){
		hasil = caripohonlengkap(root->left);//rekursif ke kiri
	}
	
	if(root->right != NULL){
		hasil = caripohonlengkap(root->right);//rekursif ke kanan
	}
	
	
	return hasil;
	
}

int carisimpulsama(char info,simpul *root){
	
	int status = 0;
	if(root->data.info==info){//jika sama
		status = 1;//maka status 1
	}else{
		if(root->left != NULL){
			status = carisimpulsama(root->data.info,root->left);//rekursif ke kiri
		}
		
		if(root->right != NULL){
			status = carisimpulsama(root->data.info,root->right);//rekursif ke kanan
		}
	}
	
	return status;
}


	