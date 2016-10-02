#include "header.h"

int main(){
	
	
	stack S1,S2;
	createEmpty(&S1);
	createEmpty(&S2);
	
	char stack1[3],stack2[3];
	int n,m,i;
	int angka1,angka2;
	
	scanf("%s",&stack1);
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&angka1);
		push(angka1,&S1);
	}
	
	scanf("%s",&stack2);
	scanf("%d",&m);
	for(i=0;i<m;i++){
		scanf("%d",&angka2);
		push(angka2,&S2);
	}
	
	int jumlah1 = jumlahangka(S1);
	int jumlah2 = jumlahangka(S2);

	printf("%s\n",stack1);
	if(jumlah1%2==0){
		printStack(S1);
	}else{
		pindahinstack(S1);
	}
	
	printf("%s\n",stack2);
	if(jumlah2%2==0){
		printStack(S2);
	}else{
		pindahinstack(S2);
	}
	
	return 0;
}