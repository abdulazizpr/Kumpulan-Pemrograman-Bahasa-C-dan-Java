#include <stdio.h>
#include <string.h>
/*
Saya Abdul Aziz Priatna(1307123) tidak melakukan kecurangan seperti yang telah dispesifikasikan pada mata kuliah 
Algoritma dan Pemrograman I dalam mengerjakan Evalusi Praktikum 2 Alpro 1, jika saya melakukan kecurangan maka Allah/Tuhan adalah saksi saya, 
dan saya bersedia menerima hukumanNya. Aamiin.
*/

int main(){
	//variabel
	char kata[50][50],i=0,j,k;
	int jumlahvokal=0;
	
	//perulangan
	do{
		//input kata sebanyak i
		scanf("%s",&kata[i]);
		if(strcmp(kata[i],"dinamik")!=0){//jika bukan kata dinamik
			for(j=0;j<strlen(kata[i]);j++){//maka akan di cek kata yang lainnya
				if(kata[i][j]=='a'||kata[i][j]=='i'||kata[i][j]=='u'||kata[i][j]=='e'||kata[i][j]=='o'){//jika ada huruf vokal
					jumlahvokal++;//maka jumlahvokal terus bertamabah
				}
			}
		}
	}while((strcmp(kata[i],"dinamik")!=0));//perulangan akan berhenti bila ada kata dinamik
	
	printf("%d\n",jumlahvokal);//output jumlahvokal
	while(strcmp(kata[i],"dinamik")!=0){
		for(j=0;j<strlen(kata[i]);j++){
			if(kata[i][j]=='a'||kata[i][j]=='i'||kata[i][j]=='u'||kata[i][j]=='e'||kata[i][j]=='o'){
				for(k=(j+1);k<=strlen(kata[i]);k++){
					kata[i][k-1]=kata[i][k];
				}
			}	
		}
		for(j=0;j<strlen(kata[i]);j++){
			printf("%c",kata[i][j]);
		}
		printf("\n");
	}
	
	

return 0;
}
