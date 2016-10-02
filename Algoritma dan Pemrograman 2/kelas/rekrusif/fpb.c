#include <stdio.h>

int CariFPB(int a,int b){
	printf("%d habis dibagi %d\n",a,b);
	
	if(b==0){
		return a;
	}else{
		int temp=a%b;
		return CariFPB(b,temp);
	}
	
}

int main(){
	int hasil=CariFPB(100,20);
	printf("hasil fpb: %d\n",hasil);
	return 0;
}