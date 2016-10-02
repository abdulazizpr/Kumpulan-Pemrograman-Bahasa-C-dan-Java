#include "header.h"

/*
Saya Abdul Aziz Priatna(1307123) tidak melakukan kecurangan seperti yang telah dispesifikasikan pada 
mata kuliah Algoritma dan Pemograman 2 dalam mengerjakan UAS, jika saya melakukan kecurangan
maka Allah/Tuhan adalah saksi saya, dan saya bersedia menerima hukumanNya. Aamiin.
*/

int main(){
	
	
	underscore = 0;				//inisialisasi underscore
	
	//masukan pita
	char pita[666];	
	scanf("%299[^\n]s",&pita);
	
	start(pita);				//memulai masukan kata
	cekunderscore(pita);		//lalu pengecekan underscore di awal
	
	while(eop(pita)==0){		//lalu proses akan berhenti jika ada eop
		inc(pita);				//maju satu kata
		cekunderscore(pita);	//lalu pengecekan underscore selama tida eop
	}
	
	printf("%d\n",underscore);	//lalu tampilkan hasil underscore nya
	
	
	return 0;
}