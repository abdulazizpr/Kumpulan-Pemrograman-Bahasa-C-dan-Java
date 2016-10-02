#include "header.h"

int main(){
	
	char pita[500];
	scanf("%499[^\n]s", &pita);
	char prev, now, next;
	int jumlah_angka=0;
	
	START(pita);
	prev = ' ';
	now = GETCC();
	INC(pita);
	next = GETCC();
	while(EOP() == 0){
		
		if(now>='0' && now<='9'){
			if(prev != ' ' && next != ' ' && next != '.'){
				jumlah_angka++;
			}
		}
		
		prev = now;
		
		now = next;
		
		INC(pita);
		
		next = GETCC();
	}
	
	printf("%d\n",jumlah_angka);
	
	return 0;
}