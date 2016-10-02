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

//fungsi untuk mencari simpul 
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
					if(strcmp(node->nama,nama)==0){
						hasil = node;
					}else{
						hasil = findSimpul(nama, node);
					}						
				}else{					
					/*jika memiliki banyak anak*/
					int ketemu = 0;
					while((node->sibling != root->child)&&(ketemu == 0)){
						if(strcmp(node->nama,nama)==0){
							hasil = node;
							ketemu = 1;
						}else{
							if(hasil==NULL){								
								hasil = findSimpul(nama, node);								
								node = node->sibling;
							}else{
								ketemu = 1;
							}
						}
					}
					
					/*memproses simpul anak terakhir karena belum terproses dalam pengulangan*/
					if(ketemu == 0){
						if(strcmp(node->nama,nama)==0){
							hasil = node;
						}else{
							if(hasil==NULL){
								hasil = findSimpul(nama,node);
								node = node->sibling;
							}else{
								ketemu = 1;
							}
						}
					}
				}
			}
		}
	}
	return hasil;
}

void inisialisasi(int n){
	int i;
	for(i=0;i<n;i++){
		panjang[i] = 0;//di set 0 semua sebanyak masukan
	}
}

//fungsi mencari kata terpanjang
void caripanjangkata(simpul* root,int level){
	
	if(root != NULL){
		
		//cek apakah akar tersebut memiliki kata terpanjang
		if(strlen(root->nama)>=panjang[level]){
			panjang[level] = strlen(root->nama);//masukan kedalam array panjang
		}
		
		level++;//level bertambah
		simpul *node = root->child;
		if(node != NULL){
			if(node->sibling == NULL){
				/*jika tidak punya sodara*/
				caripanjangkata(node,level);//rekursif ke anak
			}
			else{
				/*jika memiliki banyak anak*/
				
				/*cari di setiap anak*/
				while(node->sibling != root->child){
					caripanjangkata(node,level);//rekursif ke anak
					node = node->sibling;
				}
				
				//cek akhir anak
				caripanjangkata(node,level);
				
			}
			
		}
	}
}

void printTreePreOrder(simpul *root,int spasi,int level){
	
	
	if(root != NULL){				
		
		int i;
		if(spasi==0){//jika spasinya 0
			printf("|%s\n",root->nama);//maka print akar tanpa spasi
		}else{
			for(i=0;i<spasi;i++){
				printf(" ");//print spasi
			}
			
			printf("|%s\n",root->nama);//print akar dengan spasi
		}
		
		simpul *node = root->child;
		spasi += panjang[level] + 2;//jumlahkan spasi di tiap level
		level++;//level bertambah
		
		if(node != NULL){
			if(node->sibling == NULL){
				/*jika tidak punya sodara*/
				printTreePreOrder(node,spasi,level);//rekursif ke anak
			}
			else{
				/*jika memiliki banyak anak*/
				
				/*mencetak simpul anak*/
				while(node->sibling != root->child){
					printTreePreOrder(node,spasi,level);//rekursif ke anak
					node = node->sibling;
				}
				
				//cetak akhir anak
				printTreePreOrder(node,spasi,level);
				
			}
			
		}
		
	}
	
}

//fungsi untuk mencari tanda #
int cari_hastag(char input[]){
	
	int i = 0;
	int status = 0;
	int index = -1;
	while(i<strlen(input) && status==0){
		if(input[i]=='#'){//jika bertemu #
			status = 1;//maka status 1 (berhenti)
			index = i;//ambil index
		}else{
			i++;
		}
	}
	
	//lempar index;
	return index;
	
}

void pemisah(char input[]){
	
	int i,j=0,k=0;
	for(i=0;i<cari_hastag(input);i++){//berulang jika bertemu #
		anak[j] = input[i];//masukan semua input ke dalam anak
		j++;//pertambahan string
	}
	anak[j] = '\0';//akhir penambahan
	
	for(i=cari_hastag(input)+1;i<strlen(input)+1;i++){//berulang mulai dari # sampai akhir panjang kata
		ortu[k] = input[i];//masukan semua input ke dalam orty
		k++;//pertambahan string
	}
	ortu[k] = '\0';//akhir penambahan
}

void delete_anak(simpul **root){
	
	if(root != NULL){//jika tidak punya sodara
		simpul *node = (*root)->child;
		if(node->sibling==NULL){
			//jika tidak punya anak
			if(node->child==NULL){
				delChild(node->nama,root);//langsung delete
			}else{
				delete_anak(&node);//telusuri anak2nya
			}
		}else{
			while(node->sibling != (*root)->child){
				if(node->child != NULL){
					delete_anak(&node);//telusuri anak2nya
				}
				node = node->sibling;
				
			}
			
			//cek akhirnya
			if(node->child != NULL){
				delete_anak(&node);//telusuri anak2nya
			}
			
			//deklarasi variabel
			char temp[100][100];
			int i,index = 0;
			
			//untuk penghapusan semua anak2nya
			simpul *hapus = (*root)->child;
			while(hapus->sibling != (*root)->child){
				strcpy(temp[index],hapus->nama);//tampung semua kedalam temp
				index++;//penambahan di setiap tampungan
				hapus = hapus->sibling;
			}
			
			//tampung sisanya
			strcpy(temp[index],hapus->nama);
			index++;
			
			//proses penghapusan semua anak
			for(i=0;i<index;i++){
				delChild(temp[i],root);
			}
		}
	}
	
}


void cari_ortu(char nama[],char ortu[][100],simpul *root,int index){
	
	int ketemu = 0;
	simpul *hasil = NULL;
	if(root != NULL && ketemu==0){  //jika root tidak kosong
		strcpy(ortu[index],root->nama);//tampung setiap kunjungan
		if(strcmp(root->nama , nama)==0){ //jika yang dicari merupakan root
			hasil = root;
			ketemu = 1;
		}
		else{
			simpul *node = root->child;
			if(node != NULL && ketemu==0){
				if(node->sibling == NULL){
					index++;
					strcpy(ortu[index],node->nama);//tampung setiap kunjungan					
					/*jika memiliki satu anak*/
					if(strcmp(node->nama , nama)==0){
						hasil = node;
						ketemu = 1;
					}
					else{
						cari_ortu(nama,ortu,node,index); //rekursif (lanjut mencari simpul di dalam anak node)
					}
				}
				else{
					/*jika memiliki banyak anak*/    
					//cari simpul
					index++;
					node = root->child;
					while((node->sibling != root->child)&&(ketemu == 0)){		 		    
						//jika merupakan yang dicari status ketemu diubah menjadi 1
						strcpy(ortu[index] , node->nama);//tampung setiap kunjungan	
						if(strcmp(node->nama , nama)==0){
							hasil = node;
							ketemu = 1;
						}
						else{ //jika bukan, rekursif (cari ke anak node)
							cari_ortu(nama,ortu,node,index);
							node = node->sibling;
						}
					}
					/*memproses simpul anak terakhir karena belum terproses dalam pengulangan while di atas*/
					if(ketemu == 0){
						strcpy(ortu[index] , node->nama);//tampung setiap kunjungan	
						if(strcmp(node->nama,nama)==0){ //jika node merupakan yang dicari 
							hasil = node;
							ketemu = 1;
						}else{
							cari_ortu(nama,ortu,node,index);
						}
					}
				}
			}
			
		}
	}
	
	if(ketemu==1 && hasil!=NULL){
		index++;
		strcpy(ortu[index], hasil->nama);//tampung hasil kunjungan akhir
		int i,x=0;
	
		for(i=0;i<index;i++){
			printf("%s",ortu[i]);//print yang telah dikunjungi
			if(i<index-1){
				printf(" - ");
			}
			
			if(i==1){//jika indeks pertama(untuk mengambil ortu level pertama)
				strcpy(temp[jumlah_hapus],ortu[i]);//masukan ke temp
				jumlah_hapus++;//jumlahkan indeks
			}
		}
		printf("\n");
		
	}
	
}