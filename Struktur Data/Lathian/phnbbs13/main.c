#include "header.h"

int main(){
	
	tree T;
	
	int n,i;
	scanf("%d",&n);
	char ortu[100],anak[100];
	char info;
	char find;
	
	for(i=0;i<n;i++){
		scanf("%s %s %c",&ortu,&anak,&info);
		if(strcmp(ortu,"null")==0){
			makeTree(anak,info,&T);
		}else{
			simpul *cari = cariSimpul(ortu,T.root);
			if(cari->left==NULL){
				addLeft(anak,info,&cari);
			}else if(cari->right==NULL){
				addRight(anak,info,&cari);
			}
		}
	}
	scanf(" %c",&find);
	tampil_cari(find,T.root);
	
	return 0;
}