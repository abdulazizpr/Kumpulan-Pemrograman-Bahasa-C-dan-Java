#include "header.h"

int cari_jalan(simpul *awal,simpul *tujuan,int jumlah_jalan){
	
	
	int status = 0;
	if(awal != NULL){
		jalur *arc = awal->arc;
		
		while(arc != NULL && status==0){
			jumlah_jalan++;
			if(arc->node->info==tujuan->info){
				status = 1;
			}else{
				cari_jalan(arc->node,tujuan,jumlah_jalan);
				arc = arc->next;
			}
		}
		
		//if(status==1){
			return jumlah_jalan;
		//}
	}
	
	
}

int main(){
	
	graph G;
	createEmpty(&G);
	
	int n,i,j;
	scanf("%d",&n);
	
	int m[100];
	char kota[100];
	char jalur[100][100];
	char kota_awal;
	char kota_tujuan;
	
	for(i=0;i<n;i++){
		scanf(" %c",&kota[i]);
		scanf(" %d",&m[i]);
		for(j=0;j<m[i];j++){
			scanf(" %c",&jalur[i][j]);
		}
	}
	
	scanf(" %c %c",&kota_awal,&kota_tujuan);
	
	for(i=0;i<n;i++){
		addSimpul(kota[i],&G);
	}
	
	simpul *begin;
	simpul *end;
	for(i=0;i<n;i++){
		begin = findSimpul(kota[i],G);
		for(j=0;j<m[i];j++){
			end = findSimpul(jalur[i][j],G);
			if(begin != NULL && end != NULL) addJalur(end,&begin);
		}
	}
	
	begin = findSimpul(kota_awal,G);
	end = findSimpul(kota_tujuan,G);
	
	printf("%d\n",cari_jalan(begin,end,0));
	//printGraph(G);
	/* addSimpul('A',&G);
	addSimpul('B',&G);
	addSimpul('C',&G);
	addSimpul('D',&G);
	addSimpul('E',&G);
	
	simpul *begin = findSimpul('A',G);
	simpul *end = findSimpul('C',G);
	if(begin != NULL && end != NULL){
		addJalur(end,&begin);
	}
	
	begin = findSimpul('A',G);
	end = findSimpul('D',G);
	if(begin != NULL && end != NULL){
		addJalur(end,&begin);
	}
	
	begin = findSimpul('B',G);
	end = findSimpul('A',G);
	if(begin != NULL && end != NULL){
		addJalur(end,&begin);
	}
	
	begin = findSimpul('B',G);
	end = findSimpul('E',G);
	if(begin != NULL && end != NULL){
		addJalur(end,&begin);
	}
	
	begin = findSimpul('D',G);
	end = findSimpul('B',G);
	if(begin != NULL && end != NULL){
		addJalur(end,&begin);
	}
	
	printGraph(G);	
	delSimpul('B',&G);
	printGraph(G); */

	
	return 0;
}