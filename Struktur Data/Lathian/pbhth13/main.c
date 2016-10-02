#include "header.h"

int main(){
	
	tree T;
	
	int n,i;
	scanf("%d",&n);
	char ortu,anak;
	int nilai;
	char find;
	
	for(i=0;i<n;i++){
		scanf(" %c %c %d",&ortu,&anak,&nilai);
		if(ortu=='-'){
			makeTree(anak,nilai,&T);
		}else{
			simpul *cari = cariSimpul(ortu,T.root);
			if(cari->left==NULL){
				addLeft(anak,nilai,&cari);
			}else if(cari->right==NULL){
				addRight(anak,nilai,&cari);
			}
		}
	}
	scanf(" %c",&find);
	simpul *cariS = cariSimpul(find,T.root);
	printf("%d\n",jumlahsimpul(0,cariS));
	
	return 0;
}