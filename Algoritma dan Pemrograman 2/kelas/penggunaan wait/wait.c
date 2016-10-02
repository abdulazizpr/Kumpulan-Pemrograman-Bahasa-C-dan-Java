#include <time.h>
#include <stdio.h>

void wait(float x) {
    time_t start;
    time_t current;
    time(&start);
    do
        time(&current);
    while (difftime(current,start) < x);
}

int main(){
	int i;
	for(i=0;i<10;i++){
		//system("cls");
		if(i%2 == 0){
			printf("lalala\n");
		}else{
			printf("yeyeye\n");
		}
		wait((float)2);
	}
	return 0;
}
