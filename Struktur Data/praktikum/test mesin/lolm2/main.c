#include "header.h"

int main(){
	
	list L;
	createList(&L);
	
	int n,i,j;
	scanf("%d",&n);
	
	pertama kali[n];
	kedua pisan[n][4];//ieu jang inputan kolom
	
	for(i=0;i<n;i++){
		scanf(" %c",&kali[i].huruf);
		addLastB(kali[i].huruf,&L);
		for(j=0;j<4;j++){
			scanf("%s",&pisan[i][j].kata);
		}
	}
	
	i = 0;
	eBaris *now = L.first;
	while(now != NULL && i<n){		
		addLastK(pisan[i][0].kata,now);
		addAfterK(now->col,pisan[i][1].kata);
		addLastK(pisan[i][2].kata,now);
		addFirstK(pisan[i][3].kata,now);
		
		now = now->next;//iterasi ka baris berikutna
		i++;
	}
	
	printElement(L);
	
	return 0;
}