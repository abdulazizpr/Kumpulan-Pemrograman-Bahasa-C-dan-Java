#include "header.h"

int main(){
	
	char pita[500];
	
	
	scanf("%499[^\n]s",&pita);
	start(pita);
	
	
	//mencetak kata pertama
	printf("%s\n",getkata());
	
	while(eop(pita)==0){
		inc(pita);
		printf("%s\n",getkata());
	}
	
	return 0;
}