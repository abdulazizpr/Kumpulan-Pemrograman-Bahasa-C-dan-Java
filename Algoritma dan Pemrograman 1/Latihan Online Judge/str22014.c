#include <stdio.h>
#include <string.h>

/*
Saya Abdul Aziz Priatna(1307123) tidak melakukan kecurangan seperti yang telah dispesifikasikan pada mata kuliah 
Algoritma dan Pemrograman I dalam mengerjakan Kuis 2, jika saya melakukan kecurangan maka Allah/Tuhan adalah saksi saya, 
dan saya bersedia menerima 
hukumanNya. Aamiin.
*/

int main(){
		
		//variabel
		int i,j,k,indeks,panjang;
		
		//variabel string
		char kalimat[100];
		scanf("%s",&kalimat);//inputan string
		
		//panjang untuk banyaknya string kalimat
		panjang=strlen(kalimat);
		indeks=0;
		for(i=0;i<panjang;i++){
			if(kalimat[i]=='a'|| kalimat[i]=='i'||kalimat[i]=='u'||kalimat[i]=='e'||kalimat[i]=='o'){
				if(indeks==0) kalimat[i]='0';
				else if(indeks==1) kalimat[i]='1';
				else if(indeks==2) kalimat[i]='2';
				else if(indeks==3) kalimat[i]='3';
				else if(indeks==4) kalimat[i]='4';
				else if(indeks==5) kalimat[i]='5';
				else if(indeks==6) kalimat[i]='6';
				else if(indeks==7) kalimat[i]='7';
				else if(indeks==8) kalimat[i]='8';
				else if(indeks==9) kalimat[i]='9';
			}
			if(indeks>9){
				indeks=0;
			}else{
				indeks++;
			}
							
		}
		
		printf("%s\n",kalimat);
	
return 0;
}
