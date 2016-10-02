#include "header.h"

void makeTree(char nama[],int angka,tree *T){
	
	simpul *node = (simpul *) malloc (sizeof (simpul));
	strcpy(node->data.nama, nama);
	node->data.angka = angka;
	node->right = NULL;
	node->left = NULL;
	(*T).root = node;
}

void addRight(char nama[],int angka,simpul **root){
	
	if((*root)->right == NULL){
		/*jika sub pohon kanan kosong*/
		simpul *node = (simpul *) malloc (sizeof (simpul));
		strcpy(node->data.nama, nama);
		node->data.angka = angka;
		
		node->right = NULL;
		node->left = NULL;
		(*root)->right = node;
	}
	else printf("sub pohon kanan telah terisi");
	
}

void addLeft(char nama[],int angka,simpul **root){
	
	if((*root)->left == NULL){
		/*jika sub pohon kanan kosong*/
		simpul *node = (simpul *) malloc (sizeof (simpul));
		strcpy(node->data.nama, nama);
		node->data.angka = angka;
		
		node->right = NULL;
		node->left = NULL;
		(*root)->left = node;
	}
	else printf("sub pohon kanan telah terisi");
	
}

void add(char ortu[],char anak[],int nilai,simpul **root){
	
	if((*root) != NULL){
		
		if(strcmp((*root)->data.nama,ortu)==0){//jika ortunya sama
			if((*root)->left==NULL){//jika kiri kosong
				addLeft(anak,nilai,&(*root));//maka tambahkan dari kiri
			}else if((*root)->right==NULL){//jika kanan kosong
				addRight(anak,nilai,&(*root));//maka tambahkan dari kanan
			}
		}else{
			if((*root)->left!=NULL){//jika kiri tidak kosong
				add(ortu,anak,nilai,&(*root)->left);//maka rekursif dari kiri
			}
			if((*root)->right!=NULL){//jika kanan tidak kosong
				add(ortu,anak,nilai,&(*root)->right);//maka rekursif dari kanan
			}
		}
		
	}
	
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
		printf("%s %d\n",root->data.nama,root->data.angka);
		/* if(jumlahsimpul != 1){
			printf(" - ");
		}else{
			printf("\n");
		} */
		jumlahsimpul--;
		
		printTreePreOrder(root->left);
		printTreePreOrder(root->right);
	}
	
}

void printTreeInOrder(simpul *root){
	
	if(root != NULL){
		printTreeInOrder(root->left);
		printf("%s %d\n",root->data.nama,root->data.angka);
		printTreeInOrder(root->right);
		
	}
	
}

void printTreePostOrder(simpul *root){
	
	if(root != NULL){
		printTreePostOrder(root->left);
		printTreePostOrder(root->right);
		printf("%s %d\n",root->data.nama,root->data.angka);
	}
	
}

void printTreegenerasiOrderNext(simpul *root){
	
	if(root != NULL){
		
		if(root->left != NULL) printf("%s %d\n",root->left->data.nama,root->left->data.angka);
		if(root->right != NULL) printf("%s %d\n",root->right->data.nama,root->right->data.angka);
		if(root->left != NULL) printTreegenerasiOrderNext(root->left);
		if(root->right != NULL) printTreegenerasiOrderNext(root->right);
	
	}
	
}

void printTreegenerasiOrder(simpul *root){
	
	if(root != NULL){
		
		printf("%s %d\n",root->data.nama,root->data.angka);
		printTreegenerasiOrderNext(root);
		
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
		if(strcmp(root1->data.nama,root2->data.nama)!=0 && root1->data.angka != root2->data.angka) hasil = 0;
		else{
			isEqual(root1->left,root2->left);
			isEqual(root1->right,root2->right);
		}
	}else{
		if(root1 != NULL || root2 != NULL) hasil = 0;
	}	
	
	return hasil;
	
}

int carinamasimpulortu(char nama[],simpul *root){//fungis cari namasimpul ortu
	
	int hasil=0;//default jika ada anak yang tidak ditemukan
	if(root != NULL){
		if(root->left != NULL){//jika kiri tidak kosong
			if(strcmp(root->left->data.nama , nama)==0){//jika anak dikiri sama dengan yang dicari
				printf("%s ", root->data.nama);//tampilkan ortunya
				hasil=1;//tandanya ada
			}else{
				//rekursif
				hasil=carinamasimpulortu(nama,root->left);
			}
		}
		if(root->right != NULL&&hasil!=1){//jika di kiri tidak ada maka cari di kanan
			if(strcmp(root->right->data.nama , nama)==0){//jika anak di kanan sama dengan yang dicari
				printf("%s ", root->data.nama);//tampilkan ortunya
				hasil=1;//tandanya ada
			}else{
				//rekursif
				hasil=carinamasimpulortu(nama,root->right);
			}
		}
	}
	
	//lempar ada/tidaknya ortu
	return hasil;

}

//prosedur menampilkan ortu
void tampilortu(char nama[],simpul* root){
	
	int hasil;
	if(root != NULL){//jika root tidak kosong
		hasil=carinamasimpulortu(nama,root);//maka ambil ada/tidaknya ortu sekaligus menampilkan ortunya
	}
	
	//printf("%s\n",hasil);
 	
	if(hasil==0){//jika tidak ada
		printf("Null ");//maka tampilkan null
	} 
}

//prosedur mencari di generasi ke berapakah simpul tersebut
void carigenerasi(int generasi,simpul* cari,simpul *root){

  if(root != NULL){//jika tidak kosong
    if(root == cari){//jika akar sama dengan yang dicari
		printf("%d ", generasi);//maka tampilkan generasi ke berapanya
	}
    if(root->left != NULL){//jika kiri tidak kosong
      carigenerasi(generasi+1,cari,root->left);//maka rekursif dengan menambahkan generasinya ke kiri
    }
    if(root->right != NULL){//jika kana tidak kosong
      carigenerasi(generasi+1,cari,root->right);//maka rekursif dengan menambahkan generasinya ke kanan
    }
  }

}

void jumlahsimpulcari(int hasil,simpul* cari,simpul *root){

  if(root != NULL){//jika root tidak kosong
    if(root == cari){//jika rootnya sama dengan yang dicari
		printf("%d\n", hasil);//maka tampilkan hasil rekursifnya
	}
    if(root->left != NULL){//jika kiri tidak kosong
      jumlahsimpulcari(hasil+root->left->data.angka,cari,root->left);//maka rekursif dengan menambahkan jumlahsimpul ke kiri
    }
    if(root->right != NULL){
      jumlahsimpulcari(hasil+root->right->data.angka,cari,root->right);//maka rekursif dengan menambahkan jumlahsimpul ke kanan
    }
  }

}

simpul* findSimpul(char nama[],simpul* root){
	simpul* hasil = NULL;
	if(strcmp(root->data.nama , nama)==0){//jika namanya sama dengan di root
		hasil = root;//maka masukan root ke hasil
	}else{
		if(root->left != NULL && hasil == NULL){//jika tidak ditemukan maka rekursif ke kiri
			hasil = findSimpul(nama,root->left);
		}
		if(root->right != NULL && hasil == NULL){//jika tidak ditemukan maka rekursif ke kanan
			hasil = findSimpul(nama,root->right);
		}
	}
	
	//lempar simpul
	return hasil;
}