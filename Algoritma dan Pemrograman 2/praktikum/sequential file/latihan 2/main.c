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
	FILE *fsumber1;							//deklarasi file
	fsumber1=fopen("tmahasiswa1.txt","r");	//cara akses membuka file nya
	
	//proses read file
	fscanf(fsumber1,"%s %s %s\n",&a[n].nim,&a[n].nama,&a[n].nilai);		//cara readnya
	
	//di cek apakah dummy atau tidak
	while(strcmp(a[n].nim,"##")!=0,strcmp(a[n].nama,"##")!=0,strcmp(a[n].nilai,"##")!=0){
		fscanf(fsumber1,"%s %s %s\n",&a[n+1].nim,&a[n+1].nama,&a[n+1].nilai);
		n++;
	}
	fclose(fsumber1);  //cara menutup akses file
	
	int m=0;								//variabel buat menghitung banyaknya data
	bungkusan b[100];						//tabel buat menampung data dari file
	FILE *fsumber2;							//deklarasi file
	fsumber2=fopen("tmahasiswa2.txt","r");	//cara akses membuka file nya
	
	//proses read file
	fscanf(fsumber2,"%s %s %s\n",&b[m].nim,&b[m].nama,&b[m].nilai);		//cara readnya
	
	//di cek apakah dummy atau tidak
	while(strcmp(b[m].nim,"##")!=0,strcmp(b[m].nama,"##")!=0,strcmp(b[m].nilai,"##")!=0){
		fscanf(fsumber2,"%s %s %s\n",&b[m+1].nim,&b[m+1].nama,&b[m+1].nilai);
		m++;
	}
	fclose(fsumber2);  //cara menutup akses file
	
	printf("\n");
	printf("Isi text mahasiswa 1 : \n");
	for(i=0;i<n;i++){
		printf("%s %s %s\n",a[i].nim,a[i].nama,a[i].nilai);
	}
	printf("\n");
	printf("Isi text mahasiswa 2 : \n");
	for(i=0;i<m;i++){
		printf("%s %s %s\n",b[i].nim,b[i].nama,b[i].nilai);
	}
	
	return 0;
}