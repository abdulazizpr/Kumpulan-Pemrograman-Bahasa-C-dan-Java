#include "header.h"

int main(){
	
	
	stack S,S1,S2;
	createEmpty(&S);
	createEmpty(&S1);
	createEmpty(&S2);
	
	int n,i,j;
	scanf("%d",&n);
	
	char perintah[n][100];
	int angka;
	
	for(i=0;i<n;i++){
		scanf("%s",&perintah[i]);
		if(strcmp(perintah[i],"push")==0){
			scanf("%d",&angka);
			push(angka,&S);
		}else if(strcmp(perintah[i],"pop_cari")==0){
			scanf("%d",&angka);
			pop_cari(angka,&S);
		}else if(strcmp(perintah[i],"pop_banyak")==0){
			scanf("%d",&angka);
			pop_banyak(angka,&S);
		}else if(strcmp(perintah[i],"print_stack")==0){
			isi_stack(S,&S1);
		}
	}
	
	copy_stack(S1,&S2);
	printStack(S2);

	
	return 0;
}