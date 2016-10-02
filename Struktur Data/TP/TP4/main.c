#include "header.h"

/*
Saya Abdul Aziz Priatna tidak melakukan kecurangan seperti yang telah dispesifikasikan
pada mata kuliah Strurktur Data dalam mengerjakan TP4, jika saya melakukan kecurangan
maka Allah/Tuhan adalah saksi saya, dan saya bersedia menerima hukumanNya. Aamiin.
*/

int main(){
	
	list L;
	createList(&L);
	
	int n,m,i;
	scanf("%d",&n);										//jumlah masukan ke dalam list
	data terminal;										//deklarasi terminal
	
	for(i=0;i<n;i++){					
		scanf("%s",&terminal.kota);						//input terminal tiap kota
		scanf("%d",&terminal.jarak);					//input jarak tiap kota
		addLast(terminal.kota,terminal.jarak,&L);		//masukan ke dalam list secara addLast
	}
	
	scanf("%d",&m);										//jumlah masukan perintah
	
	char perintah[100];
	char terminal_baru[100];
	char terminal_lama[100];
	int jarak;
	int total_jarak = 0;
	
	for(i=0;i<m;i++){
		scanf("%s",&perintah);											//inputan perintah
		if(strcmp(perintah,"ADD")==0){									//jika perintanya ADD
			scanf("%s",&terminal_baru);										//masukan terminal_baru
			scanf("%s",&terminal_lama);										//masukan terminal_lama
			scanf("%d",&jarak);												//masukan jarak yang ditempuh dari kota lama ke kota baru
			operasi_add(terminal_baru,terminal_lama,jarak,&L);				//di operasikan di prosedur operasi_add
		}else if(strcmp(perintah,"DEL")==0){							//jika perintanya DEL
			scanf("%s",&terminal_lama);										//masukan terminal yang akan di delete
			operasi_del(terminal_lama,&L);									//di operasikan di prosedur operasi_del
		}else if(strcmp(perintah,"COUNT")==0){							//jika perintanya COUNT
			scanf("%s",&terminal_baru);										//masukan kota awal
			scanf("%s",&terminal_lama);										//masukan kota akhir
			total_jarak+=operasi_count(terminal_baru,terminal_lama,&L);		//di operasikan di fungsi operasi_count untuk mendapat jarak dari awal sampe akhir
		}
	}
	
	printElement(L);					//tampilkan
	printf("%d\n",total_jarak);			//output total_jarak
	
	return 0;
}	