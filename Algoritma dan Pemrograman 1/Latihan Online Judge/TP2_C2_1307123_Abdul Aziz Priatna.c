#include <stdio.h>

/*
Saya Abdul Aziz Priatna(1307123) tidak melakukan kecurangan seperti yang telah dispesifikasikan pada
mata kuliah Algoritma dan Pemrograman I dalam mengerjakan TP2, jika saya melakukan kecurangan 
maka
 Allah/Tuhan adalah saksi saya, dan saya bersedia menerima hukumanNya. Aamiin.
*/

int main(){
	
	//variabel
	int x1,y1,z1;//jam masuk
	int x2,y2,z2;//jam datang
	
	int jumlahjam1, jumlahmenit1, jumlahdetik1, totaldetik1;//konversi detik untuk jam masuk
	int jumlahjam2, jumlahmenit2, jumlahdetik2, totaldetik2;//konversi detik untuk jam datang
	int sisa, sisajam, sisamenit, sisadetik;//untuk mencari sisa jam masuk
	
	//input jam masuk
	scanf("%d %d %d",&x1,&y1,&z1);
	//dikonversi kedalam detik
	jumlahjam1=x1*3600;
	jumlahmenit1=y1*60;
	totaldetik1=jumlahjam1+jumlahmenit1+z1;
	
	//input jam datang
	scanf("%d %d %d",&x2,&y2,&z2);
	//dikonversi kedalam detik
	jumlahjam2=x2*3600;
	jumlahmenit2=y2*60;
	totaldetik2=jumlahjam2+jumlahmenit2+z2;
	
	
	
	if(totaldetik2>totaldetik1){//jika jam datang melebihi jam masuk
		//mencari sisa jam datang-jam masuk
		sisa=totaldetik2-totaldetik1;
		sisajam=sisa/3600;
		sisamenit=(sisa%3600)/60;
		sisadetik=sisa%60;
		printf("terlambat\n");//ouput terlambat
		printf("%.2d %.2d %.2d\n",sisajam,sisamenit,sisadetik);//output sisa waktu yg ada
	}else{
		printf("tidak terlambat\n");//output
	}
	
return 0;
}
