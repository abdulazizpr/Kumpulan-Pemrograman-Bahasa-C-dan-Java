#include "header.h"

int main(){
	
	int kolom,baris,i,j,status1=0,status2=0;
	
	char k,b;	
	while(status1==0){
		scanf("%c",&k);
		if(k=='K'){
			status1=1;
		}
	}
	
	int hkolom[100];
	int hbaris[100];
	
	if(status1==1){
		scanf("%d",&kolom);
		
		for(i=0;i<kolom;i++){
			scanf("%d",&hkolom[i]);
		}
	}
	
	while(status2==0){
		scanf("%c",&b);
		if(b=='B'){
			status2=1;
		}
	}
	
	if(status2==1){
		scanf("%d",&baris);
		
		for(j=0;j<baris;j++){
			scanf("%d",&hbaris[j]);
		}
	}

	long int hasil[kolom][baris];
	for(i=0;i<baris;i++){
		for(j=0;j<kolom;j++){
			hasil[i][j]=CariFPB(hkolom[j],hbaris[i]);
			printf("%ld\n",hasil[i][j]);		
		}
	}
	
	
	
return 0;	
}