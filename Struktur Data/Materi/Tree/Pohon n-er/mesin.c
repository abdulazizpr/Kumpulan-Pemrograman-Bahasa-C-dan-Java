#include "header.h"

void makeTree(char c,tree *T){
	
	simpul *node = (simpul *) malloc(sizeof (simpul));
	node->info = c;
	node->sibling = NULL;
	node->child = NULL;
	(*T).root = node;
	
}

void addChild(char c,simpul *root){
	
	if(root != NULL){
		/*jika root tidak kosong*/
		simpul *node = (simpul *) malloc(sizeof (simpul));
		node->info = c;
		node->child = NULL;
		if(root->child == NULL){
			/*simpul baru menjadi anak pertama*/
			node->sibling = NULL;
			root->child = node;
		}else{
			if(root->child->sibling == NULL){
				/*jika simpul baru menjadi anak kedua*/
				node->sibling = root->child;
				root->child->sibling = node;
			}else{
				simpul *last = root->child;
				
				/*mencari simpul anak terakhir*/
				while(last->sibling != root->child){
					last = last->sibling;
				}
				
				node->sibling = root->child;
				last->sibling = node;
			}
		}
		node = NULL;
	}
}

void delChild(char c,simpul *root){
	
	simpul *node = root->child;
	
	if(node != NULL){
		if(node->child == NULL){//jika tida mempunyai anak
			if(node->sibling == NULL){
				if(root->child->info == c){
					/*jika mempunyai satu anak*/
					if(root->child->child == NULL){
						/*jika yang akan dihapus tidak punya anak*/
						root->child = NULL;
						free(node);
					}else{
						printf("tidak ada simpul anak dengan info karakter masukan");
					}
				}
			}else{
				/*jika memiliki banyak anak*/
				
				simpul *prev = NULL;
				
				/*mencari simpul yang akan dihapus*/
				
				int ketemu = 0;
				while(node->sibling != root->child && ketemu==0){
					if(node->info == c){
						ketemu = 1;
					}else{
						prev = node;
						node = node->sibling;
					}
				}
				
				/*memproses simpul anak terakhir karena belum terproses dalam perulangan*/
				if(ketemu==0 && node->info == c){
					ketemu = 1;
				}
				
				if(ketemu==1){
					
					simpul *last = root->child;
					
					/*mencari simpul anak terakhir*/
					while(last->sibling != root->child){
						last = last->sibling;
					}
					
					if(prev == NULL){
						/*jika simpul yang dihapus anak pertama*/
						if(node->sibling == last && last->sibling == root->child){
							/*jika hanya ada 2 anak*/
							root->child = last;
							last->sibling = NULL;
						}else{
							root->child = node->sibling;
							last->sibling = root->child;
						}
					}else{
						if(prev == root->child && last->sibling==root->child){
							/*jika hanya 2 simpul anak, yang dihapus anak kedua*/
							root->child->sibling = NULL;
						}else{
							prev->sibling = node->sibling;
							node->sibling = NULL;
						}
					}
					
					free(node);
				}else{
					printf("tidak ada simpul anak dengan info karakter masukan");
				}	
			}
		}	
	}
}

simpul *findSimpul(char c,simpul *root){
	
	simpul *hasil = NULL;
	if(root != NULL){
		if(root->info == c){
			hasil = root;
		}else{
			simpul *node = root->child;
			if(node != NULL){
				if(node->sibling == NULL){
					/*jika memiliki satu anak*/
					if(node->info == c){
						hasil = node;
					}else{
						hasil = findSimpul(c,node);
					}
				}
			}else{
				/*jika memiliki banyak anak*/
				int ketemu = 0;
				while(node->sibling != root->child && ketemu==0){
					if(node->info == c){
						ketemu = 1;
					}else{
						findSimpul(c,node);
						node = node->sibling;
					}
				}
			}
		}
		
		
	}
	
}