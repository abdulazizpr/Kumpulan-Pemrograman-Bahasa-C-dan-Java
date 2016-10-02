/* Saya Muhammad Sabilil Aslam (1305778) tidak melakukan kecurangan seperti yang telah dispesifikasikan pada mata kuliah Algoritma dan Pemrograman I dalam mengerjakan TP6 , 
jika saya melakukan kecurangan maka Allah adalah saksi saya, dan saya bersedia menerima hukumanNya. Aamiin. */

#include <stdio.h>
#include <string.h>

typedef struct{
	int level;
	int harga;
}nasigoreng;

int main(){
	nasigoreng a[50];
	char input;
	int i=0;
	
	scanf("%d", &a[i].level);
	scanf("%d", &a[i].harga);
	
	while(a[i].level != 0){
		scanf("%d", &a[i+1].level);
		scanf("%d", &a[i+1].harga);
		i++;
	}
	
	scanf("%c", &input);
	int level1 = a[0].level;
	int harga1 = a[0].harga;
	
	i=0;
	if(input == 'A'){
		while(a[i].level != 0){
			if(level1 < a[i].level){
				level1=a[i].level;
				harga1=a[i].harga;
			}i++;
		}
		printf("%d\n%d\n", level1,harga1);
	}
	else if(input == 'B'){
		while(a[i].level != 0){
			if(harga1 < a[i].harga){
				harga1=a[i].harga;
				level1=a[i].level;
			}i++;
		}
		printf("%d\n%d\n", level1,harga1);
	}
	else{
		printf("tidak ada yang dicari\n");
	}
		
		
return 0;
}
