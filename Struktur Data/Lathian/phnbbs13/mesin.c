#include "header.h"

void makeTree(char nama[],char info,tree *T){
	
	simpul *node = (simpul *) malloc (sizeof (simpul));
	strcpy(node->data.nama , nama);
	node->data.info = info;
	node->right = NULL;
	node->left = NULL;
	(*T).root = node;
}

void addRight(char nama[],char info,simpul **root){
	
	if((*root)->right == NULL){
		/*jika sub pohon kanan kosong*/
		simpul *node = (simpul *) malloc (sizeof (simpul));
		strcpy(node->data.nama , nama);
		node->data.info = info;
		node->right = NULL;
		node->left = NULL;
		(*root)->right = node;
	}
	else printf("sub pohon kanan telah terisi");
	
}

void addLeft(char nama[],char info,simpul **root){
	
	if((*root)->left == NULL){
		/*jika sub pohon kanan kosong*/
		simpul *node = (simpul *) malloc (sizeof (simpul));
		strcpy(node->data.nama , nama);
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
		printf("%s %c\n",root->data.nama,root->data.info);
		printTreePreOrder(root->left);
		printTreePreOrder(root->right);
	}
	
}

void printTreeInOrder(simpul *root){
	
	if(root != NULL){
		
		printTreeInOrder(root->left);
		printf("%s %c\n",root->data.nama,root->data.info);
		printTreeInOrder(root->right);
		
	}
	
}

void printTreePostOrder(simpul *root){
	
	if(root != NULL){
		
		printTreePostOrder(root->left);
		printTreePostOrder(root->right);
		printf("%s %c\n",root->data.nama,root->data.info);
		
	}
	
}

void printTreeLevelOrderNext(simpul *root){
	
	if(root != NULL){
		
		if(root->left != NULL) printf("%s %c\n",root->left->data.nama,root->left->data.info);
		if(root->right != NULL) printf("%s %c\n",root->right->data.nama,root->right->data.info);
		if(root->left != NULL) printTreeLevelOrderNext(root->left);
		if(root->right != NULL) printTreeLevelOrderNext(root->right);
	
	}
	
}

void printTreeLevelOrder(simpul *root){
	
	if(root != NULL){
		
		printf("%s %c\n",root->data.nama,root->data.info);
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

simpul* cariSimpul(char nama[],simpul* root){
	simpul* cari = NULL;
	if(strcmp(root->data.nama,nama)==0){
		cari = root;
	}else{
		if(root->left != NULL && cari == NULL){
			cari = cariSimpul(nama,root->left);//cari ke anak cabang kiri
		}
		if(root->right != NULL && cari == NULL){
			cari = cariSimpul(nama,root->right);//cari ke anak cabang kanan
		}
	}
	return cari;
}

void tampil_cari(char cari,simpul* root){
	
	if(root != NULL){
		
		if(root->data.info==cari)printf("%s\n",root->data.nama);
		
		if(root->left != NULL && root->left->data.info == cari){
			tampil_cari(cari,root->left);//cari ke anak cabang kiri
		}
		if(root->right != NULL && root->right->data.info == cari){
			tampil_cari(cari,root->right);//cari ke anak cabang kanan
		}
		
		
	}
	
}

/* int jumlahsimpul(int hasil,simpul *root){
	
	if(root != NULL){
		//printf("Akar : %d\n",root->info);
		if(root->left != NULL){
			//printf("kiri : %d\n",root->left->info);
			hasil =  jumlahsimpul(hasil,root->left); //hitung ke anak cabang kiri
		}
		if(root->right != NULL){
			//printf("kanan : %d\n",root->right->info);
			hasil =  jumlahsimpul(hasil,root->right);//hitung ke anak cabang kanan
		}
		
		return hasil+root->data.info;
	}else{
		return 0;
	}
	
} */

	