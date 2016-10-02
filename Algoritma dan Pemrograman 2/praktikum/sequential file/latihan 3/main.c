#include <stdio.h>
#include <string.h>

typedef struct{
	char nim[10];
	char nama[100];	
	char nilai[2];	
}bungkusan;

void sorting(int n,bungkusan* tabel){
	
	int i,tukar=0;
	bungkusan temp;
	
	do{
		tukar=0;
		for(i=0;i<n-1;i++){
			if(strcmp(tabel[i].nim,tabel[i+1].nim)==1){
				temp=tabel[i];
				tabel[i]=tabel[i+1];
				tabel[i+1]=temp;
				tukar=1;
			}
		}
		
	}while(tukar==1);
	
}

void merge(bungkusan tabel1[],bungkusan tabel2[],bungkusan tabel_urut[],int n,int m){
		
	int index1=0;
	int index2=0;
	int index3=0;
	
	while(index1<n && index2<m){
		if(strcmp(tabel1[index1].nim,tabel2[index2].nim)==-1){
			tabel_urut[index3]=tabel1[index1];
			index1++;
			index3++;
		}else if(strcmp(tabel1[index1].nim,tabel2[index2].nim)==1){
			tabel_urut[index3]=tabel2[index2];
			index2++;
			index3++;
		}else{
			tabel_urut[index3]=tabel1[index1];
			index1++;
			index3++;
			tabel_urut[index3]=tabel2[index2];
			index2++;
			index3++;
		}
	}
	
	int i;
	for(i=index1;i<n;i++){
		tabel_urut[index3]=tabel1[i];
		index3++;
	}
	for(i=index2;i<m;i++){
		tabel_urut[index3]=tabel2[i];
		index3++;
	}
	
}


int main(){
	
	int n=0,i,j;							//variabel buat menghitung banyaknya data
	bungkusan a[100];						//tabel buat menampung data dari file
	FILE *fsumber1;							//deklarasi file
	fsumber1=fopen("tmahasiswa1.txt","r"); 
	
	//proses read file
	fscanf(fsumber1,"%s %s %s\n",&a[n].nim,&a[n].nama,&a[n].nilai);		//cara readnya
	
	//di cek apakah dummy atau tidak
	while(strcmp(a[n].nim,"##")!=0,strcmp(a[n].nama,"##")!=0,strcmp(a[n].nilai,"##")!=0){
		fscanf(fsumber1,"%s %s %s\n",&a[n+1].nim,&a[n+1].nama,&a[n+1].nilai);
		n++;
	}
	
	fclose(fsumber1);					    //cara menutup akses file
	
	int m=0;									//variabel buat menghitung banyaknya data
	bungkusan b[100];						//tabel buat menampung data dari file
	FILE *fsumber2;							//deklarasi file
	fsumber2=fopen("tmahasiswa2.txt","r"); 
	
	//proses read file
	fscanf(fsumber2,"%s %s %s\n",&b[m].nim,&b[m].nama,&b[m].nilai);		//cara readnya
	
	//di cek apakah dummy atau tidak
	while(strcmp(b[m].nim,"##")!=0,strcmp(b[m].nama,"##")!=0,strcmp(b[m].nilai,"##")!=0){
		fscanf(fsumber1,"%s %s %s\n",&b[m+1].nim,&b[m+1].nama,&b[m+1].nilai);
		m++;
	}
	
	fclose(fsumber2);  //cara menutup akses file
	
	sorting(n,a);
	sorting(m,b);
	
	bungkusan gabung[n+m];
	merge(a,b,gabung,n,m);
	
	FILE *fsumber3;
	fsumber3 = fopen("tmahasiswa3.txt", "w");
	for(i=0;i<n+m;i++){
		fprintf(fsumber3,"%s %s %s\n",gabung[i].nim,gabung[i].nama,gabung[i].nilai);
	} 
		fprintf(fsumber3,"## ## ##\n");
	fclose(fsumber3);
	
	return 0;
}