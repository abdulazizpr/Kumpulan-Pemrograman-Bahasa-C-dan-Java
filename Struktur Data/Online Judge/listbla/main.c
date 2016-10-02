#include "header.h"

int main(){
	
	scanf("%d",&n);
	
	list L;
	
	createList(&L);
	
	int i;
	data baru[n];
	for(i=0;i<n;i++){
		scanf("%s",&baru[i].kata);
		int tengah = cari_tengah(L);
		
		if(strcmp(baru[i].kata,"dawala")==0){
			addAfter(tengah,baru[i].kata,&L);
		}else{
			addLast(baru[i].kata,&L);
		}	
	}
	
	printElemen(L);
	
	
	return 0;
}