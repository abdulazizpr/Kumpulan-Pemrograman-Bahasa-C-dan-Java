#include "header.h"

void makeTree(char nama[],tree *T){
	
	simpul *node;
	node = (simpul *) malloc (sizeof (simpul));
	strcpy(node->nama,nama);
	node->sibling = NULL;
	node->child = NULL;
	(*T).root = node;
}

void addChild(char nama[], simpul **root){
	
	if((*root) != NULL){
		/*jika root tidak kosong*/
		simpul *node;
		node = (simpul *) malloc (sizeof (simpul));
		strcpy(node->nama,nama);
		node->child = NULL;
		
		if((*root)->child == NULL){
			/*simpul baru menjadi anak pertama*/
			node->sibling = NULL;
			(*root)->child = node;
		}else{
			if((*root)->child->sibling==NULL){
				/*jika simpul baru menjadi anak kedua*/
				node->sibling = (*root)->child;
				(*root)->child->sibling = node;
			}else{
				
				simpul *last = (*root)->child;
				/*mencari simpul anak terakhir*/
				while(last->sibling != (*root)->child){
					last = last->sibling;
				}
				
				node->sibling = (*root)->child;
				last->sibling = node;
			}
		}
		node = NULL;
		
	}
	
}

void delChild(char nama[],simpul **root){
	
	simpul *node = (*root)->child;
	
	if(node != NULL){
		if(node->sibling == NULL){
			/*jika hanya mempunyai satu anak*/
			if(strcmp(node->nama , nama)==0){
				(*root)->child = NULL;
				free(node);
			}else{
				printf("tidak ada simpul anak dengan info karakter masukan\n");
			}
		}else{
			/*jika memiliki banyak anak*/
			simpul *prev = NULL;
			
			/*mencari simpul yang akan dihapus*/
			int ketemu = 0;
			while((node->sibling != (*root)->child)&&(ketemu == 0)){
				if(strcmp(node->nama , nama)==0){
					ketemu = 1;
				}else{
					prev = node;
					node = node->sibling;
				}
			}
			
			/*memproses simpul anak terakhir karena belum terproses dalam pengulangan*/
			if((ketemu == 0)&&(strcmp(node->nama , nama)==0)){
				ketemu = 1;
			}
			
			if(ketemu == 1){
				simpul *last = (*root)->child;
				
				/*mencari simpul anak terakhir*/
				while(last->sibling != (*root)->child){
					last = last->sibling;
				}
				
				if(prev == NULL){
					/*jika simpul yang dihapus anak pertama*/
					if((node->sibling == last)&&(last->sibling == (*root)->child)){
						/*jika hanya ada 2 anak*/
						(*root)->child = last;
						last->sibling = NULL;
					}else{
						(*root)->child = node->sibling;
						last->sibling = (*root)->child;
					}
				}else{
					if((prev == node) &&(last->sibling == node)){
						/*jika hanya ada 2 simpul anak, yang dihapus anak kedua*/
						node->sibling = NULL;
						(*root)->child->sibling = NULL;
					}else if((prev != node) &&(last->sibling == node)){
						/*jika lebih dari 2 simpul anak*/
						node->sibling = NULL;
						prev->sibling = (*root)->child;
					}else{
						prev->sibling = node->sibling;
						node->sibling = NULL;
					}
				}
				
				free(node);
			}else{
				printf("tidak ada simpul anak dengan info karakter masukan\n");
			}
		}
	}

}

simpul* findSimpul(char nama[], simpul *root){
	simpul *hasil = NULL;
	if(root != NULL){
		if(strcmp(root->nama,nama)==0){
			hasil = root;
		}else{
			simpul *node = root->child;
			if(node != NULL){
				if(node->sibling == NULL){
					/*jika memiliki satu anak*/
					if(strcmp(node->nama , nama)==0){
						hasil = node;
					}else{
						hasil = findSimpul(nama, node);
					}
				}else{
					/*jika memiliki banyak anak*/
					int ketemu = 0;
					while((node->sibling != root->child)&&(ketemu == 0)){
						if(strcmp(node->nama , nama)==0){
							hasil = node;
							ketemu = 1;
						}else{
							hasil = findSimpul(nama, node);
							node = node->sibling;
						}
					}
					
					if(ketemu == 0){
						if(strcmp(node->nama , nama)==0){
							hasil = node;
						}
					}
				}
			}
		}
	}
	
	return hasil;
}


void caripanjangkata(simpul* root,int indeks){
	
	if(root != NULL){
		
	
		if(strlen(root->nama)>=panjang[indeks]){
			panjang[indeks] = strlen(root->nama);
		}
		
		indeks++;
		simpul *node = root->child;
		if(node != NULL){
			if(node->sibling == NULL){
				/*jika tidak punya sodara*/
				caripanjangkata(node,indeks);
			}
			else{
				/*jika memiliki banyak anak*/
				
				while(node->sibling != root->child){
					caripanjangkata(node,indeks);//rekursif ke anak
					node = node->sibling;
				}
				
				
			}
			
		}
	}
}

void printTreePreOrder(simpul *root,int spasi,int indeks){
	
	
	if(root != NULL){				
		
		int i;
		for(i=0;i<spasi;i++){
			printf("-");
		}
		
		printf("|%s\n",root->nama);

		simpul *node = root->child;
		spasi += panjang[indeks] + 2;
		indeks++;
		if(node != NULL){
			if(node->sibling == NULL){
				printTreePreOrder(node,spasi,indeks);
			}
			else{
				/*jika memiliki banyak anak*/
				
				while(node->sibling != root->child){
					printTreePreOrder(node,spasi,indeks);
					node = node->sibling;
				}
				
				printTreePreOrder(node,spasi,indeks);
				
			}
			
		}
		
	}
	
}

int cari_hastag(char input[]){
	
	int i = 0;
	int status = 0;
	int index = -1;
	while(i<strlen(input) && status==0){
		if(input[i]=='#'){
			status = 1;
			index = i;
		}else{
			i++;
		}
	}
	
	return index;
	
}

void pemisah(char input[]){
	
	int i,j=0,k=0;
	for(i=0;i<cari_hastag(input);i++){
		anak[j] = input[i];
		j++;
	}
	anak[j] = '\0';
	
	for(i=cari_hastag(input)+1;i<strlen(input)+1;i++){
		ortu[k] = input[i];
		k++;
	}
	ortu[k] = '\0';
}

void delete_anak(simpul **root){
	char temp[100][100];
	int index = 0;
	int i;
	
	if(root != NULL){
		simpul *node = (*root)->child;
		if(node->sibling==NULL){
			if(node->child==NULL){
				delChild(node->nama,root);
			}else{
				delete_anak(&node);
			}
		}else{
			while(node->sibling != (*root)->child){
				if(node->child != NULL){
					delete_anak(&node);
				}
				node = node->sibling;
				
			}
			
			
			simpul *hapus = (*root)->child;
			while(hapus->sibling != (*root)->child){
				strcpy(temp[index],hapus->nama);
				index++;
				hapus = hapus->sibling;
			}
			
			strcpy(temp[index],hapus->nama);
			index++;
			
			for(i=0;i<index;i++){
				delChild(temp[i],root);
			}
		}
	}
	
}


void cari_ortu(char nama[],char ortu[][100],simpul *root,int index){
	
	int ketemu = 0;
	simpul *hasil = NULL;
	if(root != NULL && ketemu==0){  
		strcpy(ortu[index],root->nama);
		if(strcmp(root->nama , nama)==0){ 
			hasil = root;
			ketemu = 1;
		}
		else{
			simpul *node = root->child;
			if(node != NULL && ketemu==0){
				if(node->sibling == NULL){
					index++;
					strcpy(ortu[index],node->nama);					
					
					if(strcmp(node->nama , nama)==0){
						hasil = node;
						ketemu = 1;
					}
					else{
						cari_ortu(nama,ortu,node,index); 
					}
				}
				else{
					index++;
					node = root->child;
					while((node->sibling != root->child)&&(ketemu == 0)){		 		    
						strcpy(ortu[index] , node->nama);	
						if(strcmp(node->nama , nama)==0){
							hasil = node;
							ketemu = 1;
						}
						else{
							cari_ortu(nama,ortu,node,index);
							node = node->sibling;
						}
					}
					
					if(ketemu == 0){
						strcpy(ortu[index] , node->nama);	
						if(strcmp(node->nama,nama)==0){  
							hasil = node;
							ketemu = 1;
						}
					}
				}
			}
			
		}
	}
	
	if(ketemu==1 && hasil!=NULL){
		index++;
		strcpy(ortu[index], hasil->nama);
		int i,x=0;
	
		for(i=0;i<index;i++){
			printf("%s",ortu[i]);
			if(i<index-1){
				printf(" - ");
			}
			
			if(i==1){
				strcpy(temp[jumlah_hapus],ortu[i]);
				jumlah_hapus++;
			}
		}
		printf("\n");
		
	}
	
}