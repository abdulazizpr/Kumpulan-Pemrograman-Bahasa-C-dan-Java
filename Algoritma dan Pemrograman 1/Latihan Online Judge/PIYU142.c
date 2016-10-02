#include <stdio.h>

/*
Saya Abdul Aziz Priatna tidak melakukan kecurangan seperti yang telah dispesifikasikan pada mata kuliah Algoritma dan Pemrograman I 
dalam mengerjakan TP5, jika saya melakukan kecurangan maka Allah/Tuhan adalah saksi saya, dan saya bersedia 
menerima hukumanNya. Aamiin.
*/

int main(){
	
	//variabel
	int x,y,x2[10],y2[10];
	int n,q,m,i,j;
	int total[10];
	int total1=0;
	int x3,y3;
	
	//awal langkah
	scanf("%d %d",&x,&y);
	
	//banyaknya teman menelpon
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		//banyaknya langkah 
		scanf("%d",&m);
		
		char k[m];
		int l[m];
		total[i]=0;
		x2[i]=x;
		y2[i]=y;
		for(j=0;j<m;j++){
			scanf(" %c",&k[j]);//arah
			scanf("%d",&l[j]);//langkah
			
			//proses
			switch(k[j]){
				case 'H':{//pilih H untuk arah horizontal
					x2[i]=x2[i]+l[j];//jumlah langkah horizontal
					//jika jumlah langkahnya negatif
					if(l[j]<0){
						//maka langkah dikalikan -1
						total[i]=total[i]+(l[j]*-1);
					}else{//jika tidak
						//jumlah langkah
						total[i]=total[i]+l[j];
					}					
				}break;
				case 'V':{//pilih V jika arahnya vertikal
					y2[i]=y2[i]+l[j];//jumlah langkah vertikal
					//jika jumlah langkahnya negatif
					if(l[j]<0){
						//maka langkah dikalikan -1
						total[i]=total[i]+(l[j]*-1);
					}else{//jika tidak
						//jumlah langkah
						total[i]=total[i]+l[j];
					}
				}break;
			}
		}
		//mencari nilai terbesar dari setiap langkah
		if(total[i]>total1){//jika jumlah langkah lebih besar dari jumlah langkah sebenarnya
			//maka jumlah langkah sama dengan jumlah langka sebanyak i
			total1=total[i];
			x3=x2[i];
			y3=y2[i];
		}
	}
	
	//output
	int penelpon=0;
	for(i=n-1;i>=0;i--){
		//jumlah banyaknya penelpon
		penelpon=i+1;
		printf("%d\n",penelpon);
		
		//koordinat lapangan yang diberi tahu
		printf("%d %d\n",x2[i],y2[i]);
		
		//jarak lapangan
		printf("%d\n",total[i]);
		
	}
	printf("koordinat lapangan\n");
	//koordinat lapangan yang sebenarnya
	printf("%d %d\n",x3,y3);
	
	//jarak dari tempat awal ke lapang tobi
	printf("%d\n",total1);
	
	
	
	
	
	
return 0;
}
