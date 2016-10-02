#include "header.h"

int main(){
	
	char pita[300];
	int j;
	int a=0,i=0,u=0,e=0,o=0;
	printf("Masukan pada kalimat pita\n");
	scanf("%299[^\n]s",&pita);
	
	start(pita);
	for(j=0;j<panjangkata;j++){
		if(ckata[j] == 'a'){
			a++;
		}else if(ckata[j] == 'i'){
			i++;
		}else if(ckata[j] == 'u'){
			u++;
		}else if(ckata[j] == 'e'){
			e++;
		}else if(ckata[j] == 'o'){
			o++;
		}
	}
	printf("\n\nberikut kata yang telah dipecah dari pita\n");
	printf("%s\n",getkata());
	while(eop(pita)==0){
		inc(pita);
		for(j=0;j<panjangkata;j++){
			if(ckata[j] == 'a'){
				a++;
			}else if(ckata[j] == 'i'){
				i++;
			}else if(ckata[j] == 'u'){
				u++;
			}else if(ckata[j] == 'e'){
				e++;
			}else if(ckata[j] == 'o'){
				o++;
			}
		}
		printf("%s\n",getkata());
	}
	printf("panjang pita : %d\n",indeks);
	printf("banyak huruf vokal\n");
	printf("a = %d\n",a);
	printf("i = %d\n",i);
	printf("u = %d\n",u);
	printf("e = %d\n",e);
	printf("o = %d\n",o);
	
	
	return 0;
}