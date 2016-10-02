#include <stdio.h>

int carifpb(int a, int b) {
	if(b==0){
		return a;
	}else{
		int temp = a % b;
		return carifpb(b, temp);
	}
}

int perkalian(int a,int b){
	int x=a*b;
	return x;
}
int kuadrat(int a){
	
}