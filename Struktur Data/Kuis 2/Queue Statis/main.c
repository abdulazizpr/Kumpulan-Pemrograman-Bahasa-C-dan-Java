#include "header.h"

int main(){
	
	queue Q;
	createEmpty(&Q);
	
	int n,i;
	scanf("%d",&n);//banyaknya inputan
	
	char nama[100];
	int waktu,prioritas;
	for(i=0;i<n;i++){
		scanf("%s %d %d",&nama,&waktu,&prioritas);//input nama waktu dan prioritas
		if(prioritas==999){//jika prioritasnya 999
			add(nama,waktu,&Q);//maka masukan secara biasa
		}else{//jika tidak
			add_prioritas(nama,waktu,prioritas,&Q);//masukan secara berprioritas
		}
	}
	//lalu print
	printQueue(Q);
	
	return 0;
}