/*Nama Pembuat: Husni Arsyad
  Nama Program: Kuis 1 Alpro 1
  NIM		  : 1307731
  Kelas		  : C2
  
  Saya Husni Arsyad 1307731 Kelas C2 mengerjakan tugas ini dengan jujur
*/
#include<stdio.h>
int main(){

	int a,b,c,d,e,f,g=0,h;
	
	scanf("%d",&a);
	scanf("%d",&b);
	scanf("%d",&c);
	scanf("%d",&d);
	scanf("%d",&e);
	scanf("%d",&f);
	
//penandaan bilangan genap
	if(a%2 == 0){
		g += 1;
	}
	if(b%2 == 0){
		g += 1;
	}
	if(c%2 == 0){
		g += 1;
	}
	if(d%2 == 0){
		g += 1;
	}
	if(e%2 == 0){
		g += 1;
	}
	if(f%2 == 0){
		g += 1;
	}

//jika bilangan bulat ada tepat 3
	if(g == 3){
	//pertukaran nilai a
		if(a%2 != 0){
			h = a;
			a = b;
			b = h;
		}
		if(a%2 != 0){
			h = a;
			a = c;
			c = h;
		}
		if(a%2 != 0){
			h = a;
			a = d;
			d = h;
		}
		if(a%2 != 0){
			h = a;
			a = e;
			e = h;
		}
		if(a%2 != 0){
			h = a;
			a = f;
			f = h;
		}
	//pertukaran nilai b
		if(b%2 == 0){
			h = b;
			b = c;
			c = h;
		}
		if(b%2 == 0){
			h = b;
			b = d;
			d = h;
		}if(b%2 == 0){
			h = b;
			b = e;
			e = h;
		}if(b%2 == 0){
			h = b;
			b = f;
			f = h;
		}
	//pertukaran nilai c
		if(c%2 != 0){
			h = c;
			c = d;
			d = h;
		}
		if(c%2 != 0){
			h = c;
			c = e;
			e = h;
		}
		if(c%2 != 0){
			h = c;
			c = f;
			f = h;
		}
	//pertukaran nilai d
		if(d%2 == 0){
			h = d;
			d = e;
			e = h;
		}
		if(d%2 == 0){
			h = d;
			d = f;
			f = h;
		}
	//pertukaran nilai e
		if(e%2 != 0){
			h = e;
			e = f;
			f = h;
		}
	//pertukaran nilai f tidak perlu karena nilainya pasti sudah ditukar
	
		printf("%d\n%d\n%d\n%d\n%d\n%d\n",a,b,c,d,e,f);
	}else{
		printf("tidak valid\n");
	}
return 0;
}
