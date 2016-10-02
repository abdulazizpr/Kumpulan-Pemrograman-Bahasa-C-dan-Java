#include "header.h"

int main(){
	
	
	stack S1,S2;
	createEmpty(&S1);
	createEmpty(&S2);
	
	char stack1[3],stack2[3];
	int n,m,i;
	float angka1,angka2;
	
	scanf("%s",&stack1);
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%f",&angka1);
		push(angka1,&S1);
	}
	
	scanf("%s",&stack2);
	scanf("%d",&m);
	for(i=0;i<m;i++){
		scanf("%f",&angka2);
		push(angka2,&S2);
	}
	
	int sama = cek_sama(S1,S2);
	if(sama==0){
		pindahinstack(S1);
	}else{
		pindahinstack(S1);
		pindahinstack(S2);
	}
	

	return 0;
}