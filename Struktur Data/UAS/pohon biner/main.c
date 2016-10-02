#include "header.h"

int main(){
	
	tree T;
	
	int n,i;
	scanf("%d",&n);//banyaknya input
	char anak;
	char ortu[100];
	char pilihan[100];
	
	for(i=0;i<n;i++){
		scanf(" %c %s %s",&anak,&ortu,&pilihan);
		
		if(strcmp(ortu,"null")==0 || strcmp(pilihan,"null")==0){//jika ortu atau pilihan null
			makeTree(anak,&T);//maka buatlah pohon
		}else{
			simpul *cari = cariSimpul(ortu[0],T.root);//cari simpul ortu
			if(strcmp(pilihan,"kiri")==0){//jika di kiri
				if(cari->left==NULL){//jika kosong
					addLeft(anak,&cari);//maka masukan di kiri
				}
			}else if(strcmp(pilihan,"kanan")==0){//jika dikanan
				if(cari->right==NULL){//jika kosong
					addRight(anak,&cari);//maka masukan di kanan
				}
			}
			
		}
		
	}
	
	int lengkap = caripohonlengkap(T.root);
	int sama = carisimpulsama(' ',T.root);
	
	if(lengkap==1 && sama==1){//jika lengkap dan sama 1
		printf("lengkap dan ada yang sama\n");
	}else if(lengkap==1 && sama==0){//jika lengkap 1 sama 0
		printf("lengkap dan tidak ada yang sama\n");
	}else if(lengkap==0 && sama==1){//jika lengkap 0 sama 1
		printf("tidak lengkap dan ada yang sama\n");
	}else if(lengkap==0 && sama==0){//jika lengkap 0 sama 0
		printf("tidak lengkap dan tidak ada yang sama\n");
	}
	
	return 0;
}