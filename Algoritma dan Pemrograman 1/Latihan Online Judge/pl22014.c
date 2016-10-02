#include <stdio.h>
#include <string.h>

/*
Saya Abdul Aziz Priatna(1307123) tidak melakukan kecurangan seperti yang telah dispesifikasikan pada mata kuliah 
Algoritma dan Pemrograman I dalam mengerjakan UTS, jika saya melakukan kecurangan maka Allah/Tuhan adalah saksi saya, 
dan saya bersedia menerima 
hukumanNya. Aamiin.
*/

int main(){
	//variabel
	int n,i,j,k,l,spasi=0;
	scanf("%d",&n);//inputan
	
	//variabel kata sebanyak n
	char kata[n][50];
	for(i=0;i<n;i++){
		//inputan kata sebanyak i
		scanf("%s", &kata[i]);
	}
	
	//variabel untuk menampung panjang string kata
	int panjang;
	for(i=0;i<n;i++){
		
		//isi variabel panjang sama dengan panjang string kata
		panjang=strlen(kata[i]);
		//jika indeksnya ganjil
		if(i%2==1){
			//maka di print kebawah
			for(j=0;j<panjang;j++){
				k=1;
				while(k<spasi){
					printf(" ");
					k++;
				}
				printf("%c\n",kata[i][panjang-1-j]);//output
			}	
		}else{//jika tidak
			//maka di print ke samping
			j=0;
			while(j<spasi){
				printf(" ");
				j++;
			}
			//di print dari 0 ke tengah
			for(j=0;j<panjang/2;j++){
				printf("%c",kata[i][j]);//output
			}
			//denagn ditandai spasi di tengah
			for(j=0;j<1;j++){
					printf(" ");//output
			}
			//di print dari tengah ke akhir
			for(j=panjang-(panjang/2);j<panjang;j++){
				printf("%c",kata[i][j]);//output
			}
			printf("\n");
			//jumlah spasi sama dengan jumlah panjang/2
			spasi=spasi+(panjang/2)+1;	
		}
	}

return 0;
}
