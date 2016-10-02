#include "header.h"

void jumlah_beban(char tujuan,graph G){
	
	simpul *node = G.first;
	
	int jumlah = 0;
	int status = 0;
	
	if(node != NULL){
		
		while(node != NULL && status==0){
			
			jalur *arc = node->arc;
			
			while(arc != NULL){
				if(arc->node->info==tujuan){
					jumlah += arc->info;
				}else{
					if(node->info==tujuan){
						jumlah += arc->info;
					}
				}
				arc = arc->next;	
			}
			
			if(node->info==tujuan){
				status = 1;
			}
			node = node->next;
		
		}
	}
	
	printf("%d\n",jumlah);
}

int main(){
	
	graph G;
	createEmpty(&G);
	
	int n,m,i;
	scanf("%d",&n);
	
	char kota;
	char tujuan;
	int beban;
	for(i=0;i<n;i++){
		scanf(" %c",&kota);
		addSimpul(kota,&G);
	}
	
	scanf("%d",&m);
	for(i=0;i<m;i++){
		scanf(" %c",&kota);
		scanf(" %c",&tujuan);
		scanf("%d",&beban);
		simpul *begin = findSimpul(kota,G);
		simpul *end = findSimpul(tujuan,G);
		
		if(begin != NULL && end != NULL){
			addJalur(end,beban,&begin);
		}
	}
	
	scanf(" %c",&tujuan);
	jumlah_beban(tujuan,G);
	//printGraph(G);
	/* addSimpul('A',&G);
	addSimpul('B',&G);
	addSimpul('C',&G);
	addSimpul('D',&G);
	addSimpul('E',&G);
	addSimpul('F',&G);
	
	simpul *begin = findSimpul('A',G);
	simpul *end = findSimpul('B',G);
	if(begin != NULL && end != NULL){
		addJalur(end,3,&begin);
	}
	
	begin = findSimpul('B',G);
	end = findSimpul('D',G);
	if(begin != NULL && end != NULL){
		addJalur(end,3,&begin);
	}
	
	end = findSimpul('E',G);
	if(begin != NULL && end != NULL){
		addJalur(end,7,&begin);
	}
	
	begin = findSimpul('C',G);
	end = findSimpul('A',G);
	if(begin != NULL && end != NULL){
		addJalur(end,3,&begin);
	}
	
	begin = findSimpul('D',G);
	if(begin != NULL && end != NULL){
		addJalur(end,8,&begin);
	}
	
	end = findSimpul('C',G);
	if(begin != NULL && end != NULL){
		addJalur(end,3,&begin);
	}
	
	begin = findSimpul('E',G);
	end = findSimpul('D',G);
	if(begin != NULL && end != NULL){
		addJalur(end,4,&begin);
	}
	
	end = findSimpul('F',G);
	if(begin != NULL && end != NULL){
		addJalur(end,4,&begin);
	}
	
	begin = findSimpul('F',G);
	end = findSimpul('D',G);
	if(begin != NULL && end != NULL){
		addJalur(end,2,&begin);
	}
	
	printf("================\n");
	printGraph(G);
	printf("\n================\n");
	
	/*begin = findSimpul('A',G);
	if(begin != NULL){
		delJalur('B',&begin);
	}
	
	hapussimpuljalur('A',&G);
	
	printf("================\n");
	printf("setelah dihapus\n");
	printGraph(G);
	printf("\n================\n"); */
	
	return 0;
}