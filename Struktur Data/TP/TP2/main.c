#include "header.h"

/*
Saya Abdul Aziz Priatna tidak melakukan kecurangan seperti yang telah dispesifikasikan
pada mata kuliah Strurktur Data dalam mengerjakan TP2, jika saya melakukan kecurangan
maka Allah/Tuhan adalah saksi saya, dan saya bersedia menerima hukumanNya. Aamiin.
*/

int main(){
	
	list L;
	createList(&L);		//membuat list baru	
	
	int n,m,p,i;
	scanf("%d\n",&n);	//masukan banyaknya data
	
	data senior[n];
	for(i=0;i<n;i++){
		scanf("%s %d",&senior[i].nama_sales,&senior[i].hasil_penjualan);	//masukan data senior ke list
		addLast(senior[i].nama_sales,senior[i].hasil_penjualan,&L);		//dimasukan secara addlast
	}
	
	kumulatif_senior(&L);		//dikumulatifkan
	sort(&L);					//lalu sorting
	
	scanf("%d",&m);
	data junior[m];
	for(i=0;i<m;i++){
		scanf("%s %d",&junior[i].nama_sales,&junior[i].hasil_penjualan);	//masukan data junior ke list
		add_sort_junior(junior[i].nama_sales,junior[i].hasil_penjualan,&L);		//dimasukan dengan tidak mengubah data yang telah diurutkan
	}
	
	scanf("%d",&p);			//masukan banyaknya data yang akan dihapus
	char hapus[p][100];
	for(i=0;i<p;i++){
		scanf("%s",&hapus[i]);	//masukan nama yang akan dihapus
		hapus_sales(hapus[i],&L);	//lalu dihapus sesuai dengan nama yang akan dihapus
	}
	
	printElement(L);	//lalu print semua yang ada di list
	
	return 0;
}