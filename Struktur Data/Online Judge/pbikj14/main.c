#include "header.h"

int main(){
	
	tree T;
	
	int n,i;
	scanf("%d",&n);
	int ortu,anak;
	char pilihan[20];
	
	for(i=0;i<n;i++){
		scanf("%d %d %s",&anak,&ortu,pilihan);
		if(strcmp(pilihan,"akar")==0 && ortu==0){
			makeTree(anak,&T);
		}else{
			simpul *cari = cariSimpul(ortu,T.root);
			if(strcmp(pilihan,"kiri")==0){
				addLeft(anak,&cari);
			}else if(strcmp(pilihan,"kanan")==0){
				addRight(anak,&cari);
			}
		}
	}
	
	printf("%d\n",jumlahsimpulkiri(0,T.root->left)+T.root->nilai);
	
	
	return 0;
}