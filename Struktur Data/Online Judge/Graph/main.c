#include "header.h"

void jarak(char kota_tujuan[],int jumlah,simpul *awal){
	
	if(awal != NULL){
		//while(awal != NULL){
			
			jalur *arc = awal->arc;
			int status = 0;
			while(arc != NULL && status==0){
				if(strcmp(arc->node->info,kota_tujuan)==0){
					jumlah += arc->info;
					status = 1;
				}else{
					jarak(kota_tujuan,jumlah+arc->info,arc->node);
				}
				
				arc = arc->next;
			}
		//}
	}
	
	printf("%d\n",jumlah);
}

int main(){
	
	int n,m[100],o[100],i,j,k;
	
	scanf("%d",&n);
	char kota[100];
	char jalur[100];
	int beban;
	
	char kota_awal[n][100];
	char kota_tujuan[n][100];
	
	graph G[n];
	for(i=0;i<n;i++){
		createEmpty(&G[i]);
	}
	
	for(i=0;i<n;i++){
		scanf("%d",&m[i]);
		for(j=0;j<m[i];j++){
			scanf("%s",&kota);
			simpul *cari = findSimpul(kota,G[i]);
			if(cari==NULL){
				addSimpul(kota,&G[i]);
			}
			
			scanf("%d",&o[j]);
			
			for(k=0;k<o[j];k++){
				scanf("%s",&jalur);
				scanf("%d",&beban);
				
				simpul *begin = findSimpul(kota,G[i]);
				simpul *end = findSimpul(jalur,G[i]);
				
				if(begin != NULL && end == NULL){
					addSimpul(jalur,&G[i]);
					end = findSimpul(jalur,G[i]);
					addJalur(end,beban,&begin);
				}else if(begin != NULL && end != NULL){
					addJalur(end,beban,&begin);
				}
			}
			
		}
		
		scanf("%s",&kota_awal[i]);
		scanf("%s",&kota_tujuan[i]);
	}
	
	for(i=0;i<n;i++){
		simpul *awal = findSimpul(kota_awal[i],G[i]);
		jarak(kota_tujuan[i],0,awal);
	}
	
	return 0;
}