#include<stdio.h>

int power(int x,int y){
	int hasil;
	printf("%d indeks %d\n",x,y);
	
	if(y==0){
		return 1;
	}else{
		int hasil=x*power(x,y-1);
	}
}

int main(){
	int hasil=power(2,3);
	printf("hasil pangkat : %d\n",hasil);
	
	return 0;
}