#include "header.h"

int main(){
	
	
	tree T;
	
	int n,m,i,j;
	scanf("%d",&n);
	
	char input[100];
	simpul *node;
	
	for(i=0;i<n;i++){
		scanf("%s",&input);
		pemisah(input);
		if(strcmp(ortu,"null")==0){
			makeTree(anak,&T);
		}else{
			simpul *node = findSimpul(ortu,T.root);
			addChild(anak,&node);
		}
	}
	
	scanf("%d",&m);
	
	char cari[m][100];
	for(i=0;i<m;i++){
		scanf("%s",&cari[i]);
	}
	
	caripanjangkata(T.root,0);
	printTreePreOrder(T.root,0,0);
	printf("\n");
	
	char orang_tua[100][100];
	jumlah_hapus = 0;
	for(i=0;i<m;i++){
		cari_ortu(cari[i],orang_tua,T.root,0);
	}
	
	for(i=0;i<jumlah_hapus;i++){
		simpul *find = findSimpul(temp[i],T.root);
		delete_anak(&find);
		delChild(temp[i],&T.root);		
	}
	
	printf("\n");
	caripanjangkata(T.root,0);
	printTreePreOrder(T.root,0,0);
	
	return 0;
}