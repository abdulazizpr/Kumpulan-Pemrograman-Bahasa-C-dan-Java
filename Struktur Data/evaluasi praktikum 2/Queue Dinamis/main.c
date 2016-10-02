#include "header.h"

int main(){
	
	
	queue Q;
	createEmpty(&Q);
	
	char nama[100];
	int waktu,i,ongkos,n,total_waktu;
	
	scanf("%d",&total_waktu);//masukan waktu
	scanf("%d",&n);//masukan banyaknya input
	
	for(i=0;i<n;i++){
		scanf("%s %d %d",&nama,&waktu,&ongkos);//masukan nama waktu ongkos
		add(nama,waktu,ongkos,&Q);//lalu masukan ke dalam Queue
	}
	
	//lalu print
	printQueue(total_waktu,Q);
	
	
	return 0;
}