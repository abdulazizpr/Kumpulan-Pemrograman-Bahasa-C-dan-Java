#include <stdio.h>

void tulis(int n){
	int counter;
	counter=n;
	
	if(counter>0){
		printf("proses rekrusif dengan nilai counter: %d\n", counter);
		counter=counter-1;
		tulis(counter);
	}
	
}

int main(){
	
	tulis(10);
	
	return 0;
}