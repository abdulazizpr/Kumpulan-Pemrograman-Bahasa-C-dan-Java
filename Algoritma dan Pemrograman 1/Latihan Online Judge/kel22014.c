#include <stdio.h>

/*
Saya Abdul Aziz Priatna(1307123) tidak melakukan kecurangan seperti yang telah dispesifikasikan pada 
mata kuliah Algoritma dan Pemrograman I dalam mengerjakan Kuis 1, jika saya melakukan kecurangan 
maka Allah/Tuhan adalah saksi saya, dan saya bersedia menerima hukumanNya. Aamiin.
*/

int main(){
	
	//variabel
	int a,b,c;//inputan
	int jumlahkelipatan=0;//penampungan untuk jumlahkelipatan setiap inputan
	
	//input
	scanf("%d %d %d",&a,&b,&c);
	
	//proses penampungan setiap inputan
	if(a%b==0){
		jumlahkelipatan++;
	}
	if(c%b==0){
		jumlahkelipatan++;
	}
	if(b%a==0){
		jumlahkelipatan++;
	}
	if(c%a==0){
		jumlahkelipatan++;
	}
	if(a%c==0){
		jumlahkelipatan++;
	}
	if(b%c==0){
		jumlahkelipatan++;
	}
	
	//proses output
	if(jumlahkelipatan>=2){
		if((a%b==0)&&(c%b==0)){
			//output
			printf("%d %d\n",a,b);
			printf("%d %d\n",c,b);
		}
		if((b%a==0)&&(c%a==0)){
			//output
			printf("%d %d\n",b,a);
			printf("%d %d\n",c,a);
		}
		if((a%c==0)&&(b%c==0)){
			//output
			printf("%d %d\n",a,c);
			printf("%d %d\n",b,c);
		}	
	}else{
		if(a%b==0){
			//output
			printf("%d %d\n",a,b);
		}
		if(c%b==0){
			//output
			printf("%d %d\n",c,b);
		}
		if(b%a==0){
			//output
			printf("%d %d\n",b,a);
		}
		if(c%a==0){
			//output
			printf("%d %d\n",c,a);
		}
		if(a%c==0){
			//output
			printf("%d %d\n",a,c);
		}
		if(b%c==0){
			//output
			printf("%d %d\n",b,c);
		}
	}

return 0;
}
