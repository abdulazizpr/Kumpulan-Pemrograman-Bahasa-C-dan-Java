#include <stdio.h>

int main(){
	
	//membersihkan layar
	system("cls");
	int papan[3][3];
	//angka 1 untuk pemain pertama berupa huruf X
	//angka 2 untuk pemain pertama berupa huruf O
	int i,j,k;
	
	//inisialisasi papan diisi
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			papan[i][j] = 0;
		}
	}
	
	//awalnya pemain di set -1 sebagai penanda permainan belum dimulai
	int pemain = -1;
	
	//x dan y juga di set -1 sebagai penanda permainan belum dimulai
	int x=-1, y=-1;
	for(i=0;i<9;i++){
		//mengisi papan jika ada masukan dari pemain
		if(x!=-1 && y!=-1){
			papan[x][y]=pemain;
		}
		
		//menggambar papan
		printf("Kondisi Papan:\n");
		printf("----------------\n");
		for(j=0;j<3;j++){
			printf("|  ");
			for(k=0;k<3;k++){
				if(papan[k][j]==0){
				//jika papan kosong
					printf("  |  ");
				}else if(papan[k][j]==1){
				//jika papan diisi pemain pertama	
					printf("O |  ");
				}else if(papan[k][k]==2){
				//jika papan diisi pemain kedua	
					printf("X |  ");
				}
			}
			printf("\n----------------\n");
		}
		printf("\n");
		
		//pergantian pemain yang akan mengisi pemain
		if(pemain==1){
			pemain=2;
		}else{
			pemain=1;
		}
		
		//meminta masukan pemain
		printf("Masukan X,Y (Pemain %d) : ",pemain);
		scanf("%d %d",&x,&y);
		//membersihkan layar
		system("cls");
	}
	
	
	
	
	
	return 0;
}