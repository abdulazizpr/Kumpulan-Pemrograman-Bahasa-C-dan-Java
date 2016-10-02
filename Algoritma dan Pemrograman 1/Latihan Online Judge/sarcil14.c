#include <stdio.h>

int main(){
	
	
	int a,b,c,d,e,f;
	int jumlahkelipatand=0,jumlahkelipatane=0,jumlahkelipatanf=0;
	
	scanf("%d",&a);
	scanf("%d",&b);
	scanf("%d",&c);
	
	scanf("%d",&d);
	if(a%d==0){
		jumlahkelipatand++;
	}if(b%d==0){
		jumlahkelipatand++;
	}if(c%d==0){
		jumlahkelipatand++;
	}
		
	scanf("%d",&e);
	if(a%e==0){
		jumlahkelipatane++;
	}if(b%e==0){
		jumlahkelipatane++;
	}if(c%e==0){
		jumlahkelipatane++;
	}
	
	scanf("%d",&f);
	if(a%d==0){
		jumlahkelipatanf++;
	}if(b%d==0){
		jumlahkelipatanf++;
	}if(c%d==0){
		jumlahkelipatanf++;
	}
	
	
	if(jumlahkelipatand>=2 && jumlahkelipatane>=2 && jumlahkelipatanf>=2){
		printf("valid\n");
	}else{
		printf("tidak valid\n");
	}
		
return 0;	
}