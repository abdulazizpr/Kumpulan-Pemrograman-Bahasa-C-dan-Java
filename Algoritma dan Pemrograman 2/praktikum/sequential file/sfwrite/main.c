#include <stdio.h>
#include <string.h>

typedef struct{
	char nim[10];
	char nama[100];	
	char nilai[2];	
}bungkusan;

int main(){
	
	int n=0;								//variabel buat menghitung banyaknya data
	int i,j;								//variabel buat perulangan
	bungkusan a[100];						//tabel buat menampung data dari file
	FILE *fsumber;							//deklarasi file
	fsumber=fopen("tmahasiswa.txt","r");	//cara akses membuka file nya
	
	//proses read file
	fscanf(fsumber,"%s %s %s\n",&a[n].nim,&a[n].nama,&a[n].nilai);		//cara readnya
	
	//di cek apakah dummy atau tidak
	while(strcmp(a[n].nim,"##")!=0,strcmp(a[n].nama,"##")!=0,strcmp(a[n].nilai,"##")!=0){
		fscanf(fsumber,"%s %s %s\n",&a[n+1].nim,&a[n+1].nama,&a[n+1].nilai);
		n++;
	}
	fclose(fsumber);  //cara menutup akses file
	
	//proses inputan data
	scanf("%s %s %s",&a[n].nim,&a[n].nama,&a[n].nilai);
	
	//proses penulisan file kembali
	//nama file harus beda
	FILE *fsumber1;
	fsumber1=fopen("tmahasiswa.txt","w");		//ini buat di write
	for(i=0;i<n+1;i++){
		fprintf(fsumber1,"%s %s %s\n",a[i].nim,a[i].nama,a[i].nilai);
	}
	
		//jangan lupa tambahkan record dummy 
		fprintf(fsumber1,"## ## ##\n");
	
	fclose(fsumber);
	
	
	return 0;
}