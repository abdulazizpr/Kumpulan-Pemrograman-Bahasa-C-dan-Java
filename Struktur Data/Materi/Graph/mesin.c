#include "header.h"

void createEmpty(graph *G){
	(*G).first = NULL;
}

void addSimpul(char c,graph *G){
	simpul *node = (simpul *) malloc (sizeof (simpul));
	node->info = c;
	node->next = NULL;
	node->arc = NULL;
	
	if((*G).first == NULL){
		/*jika graf kosong*/
		(*G).first = node;
	}else{
		/*menambahkan simpul baru pada akhir graf*/
		simpul *last = (*G).first;
		while(last->next != NULL){
			last = last->next;
		}
		
		last->next = node;
	}
}

void addJalur(simpul *tujuan,int beban, simpul **awal){
	
	jalur *arc = (jalur *) malloc (sizeof (jalur));
	arc->info = beban;
	arc->next = NULL;
	arc->node = tujuan;
	
	if((*awal)->arc == NULL){
		/*jika list jalur list kosong*/
		(*awal)->arc = arc;
	}else{
		/*menambahkan jalur baru pada akhir list jalur*/
		jalur *last = (*awal)->arc;
		
		while(last->next != NULL){
			last = last->next;
		}
		
		last->next = arc;
	}
	
}

void delSimpul(char c,graph *G){
	
	simpul *elmt = (*G).first;
	if(elmt != NULL){
		
		simpul *prev = NULL;
		/*mencari simpul yang akan dihapus*/
		
		int ketemu = 0;
		while(elmt != NULL && ketemu == 0){
			if(elmt->info == c){
				ketemu = 1;
			}else{
				prev = elmt;
				elmt = elmt->next;
			}
		}
		
		if(ketemu == 1){
			if(elmt->arc == NULL){
				if(prev==NULL){
					/*hapus simpul pertama*/
					(*G).first = elmt->next;
				}else{
					if(elmt->next == NULL){
						/*hapus simpul terakhir*/
						prev->next = NULL;
					}else{
						/*hapus simpul di tengah*/
						prev->next = elmt->next;
						elmt->next = NULL;
					}
				}
				free(elmt);
			}
		}else{
			printf("tidak ada simpul dengan info karakter masukan\n");
		}
	}else{
		printf("tidak ada simpul dengan info karakter masukan\n");
	}
	
}

simpul *findSimpul(char c,graph G){
	
	simpul *hasil = NULL;
	simpul *node = G.first;
	
	int ketemu = 0;
	while(node != NULL && ketemu == 0){
		if(node->info == c){
			hasil = node;
			ketemu = 1;
		}else{
			node = node->next;
		}
	}
	
	return hasil;
}

void delJalur(char ctujuan,simpul **awal){
	
	jalur *arc = (*awal)->arc;
	
	if(arc != NULL){
		
		jalur *prev = NULL;
		
		/*mencari jalur yang akan di hapus*/
		
		int ketemu = 0;
		while(arc != NULL && ketemu == 0){
			if(arc->node->info == ctujuan){
				ketemu = 1;
			}else{
				prev = arc;
				arc = arc->next;
			}
		}
		
		if(ketemu == 1){
			if(prev == NULL){
				/*hapus jalur pertama*/
				(*awal)->arc = arc->next;
			}else{
				if(arc->next == NULL){
					/*hapus jalur pertama*/
					prev->next = NULL;
				}else{
					/*hapus jalur di tengah*/
					prev->next = arc->next;
					arc->next = NULL;
				}
			}
			free(arc);
		}else{
			printf("tidak ada jalur dengan simpul tujuan\n");
		}
	}else{
		printf("tidak ada jalur dengan simpul tujuan\n");
	}
}

void printGraph(graph G){
	
	simpul *node = G.first;
	
	if(node != NULL){
		
		while(node != NULL){
			
			printf("simpul : %c\n",node->info);
			
			jalur *arc = node->arc;
			
			while(arc != NULL){
				printf(" - ada jalur ke simpul : %c dengan beban : %d\n",arc->node->info,arc->info);
				
				arc = arc->next;
			}
			
			node = node->next;
		
		}
	}else{
		printf("graf kosong");
	}
	
}

void hapussimpuljalur(char c,graph *G){
	
	simpul *begin = findSimpul(c,(*G));
	
	if(begin != NULL){
		jalur *arc = begin->arc;
		//selama jalur tidak kosong
		while(arc != NULL){
			delJalur(arc->node->info,&begin);//hapus jalur satu2
			//arc = arc->next;
		}
		
		//lalu hapus simpulnya
		delSimpul(c,G);
	}
	
}