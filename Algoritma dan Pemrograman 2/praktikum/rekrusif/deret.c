#include <stdio.h>

int cek(int i,int a,int b,int c,int d){
	
	int temp;
	if(i==0){
		temp=a;
	}else if(i==1){
		temp=b;
	}else if(i==2){
		temp=c;
	}else if(i==3){
		temp=d;
	}else{
		temp=cek(i-2,a,b,c,d)+cek(i-4,a,b,c,d);
	}
	
	return temp;
	
}

int main(){
	
	int n;
	int i;
	int a,b,c,d;
	
	scanf("%d %d %d %d",&a,&b,&c,&d);
	scanf("%d",&n);
	
	int m1[n+1];
	
	for(i=0;i<n;i++){
		m1[i]=cek(i,a,b,c,d);
		printf("%d ",m1[i]);
	}
	printf("\n");
	
}