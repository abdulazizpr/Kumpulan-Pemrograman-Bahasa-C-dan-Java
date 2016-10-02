#include "header.h"

/*
Saya Abdul Aziz Priatna tidak melakukan kecurangan seperti yang telah dispesifikasikan
pada mata kuliah Strurktur Data dalam mengerjakan TP1, jika saya melakukan kecurangan
maka Allah/Tuhan adalah saksi saya, dan saya bersedia menerima hukumanNya. Aamiin.
*/


int main(){
	
	int i;
	scanf("%d",&n);				//banyaknya list
	
	list L;
	createList(&L);
	
	data pegawai[n];			//data pegawain sesuai banyaknya list
	char no_undian[7];
	
	for(i=0;i<n;i++){
		scanf("%s",&pegawai[i].nama);				//input nama
		scanf("%s",&pegawai[i].no_pegawai);			//input no_pegawai
		scanf("%d",&pegawai[i].gaji_pokok);			//input gaji_pokok
		addLast(pegawai[i].nama,pegawai[i].no_pegawai,pegawai[i].gaji_pokok,&L);	
	}
	scanf("%s",&no_undian);							//input no_undian
	
	kumulatif(no_undian,&L);		//akumulasi gajih
	bubble_sort(&L);				//sorting
	
	printElemen(L);		//tampilkan isi elemen
	
	return 0;
}