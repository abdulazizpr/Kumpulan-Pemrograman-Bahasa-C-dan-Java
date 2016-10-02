#include "header.h"


void prima(int n){
	
	int i,angka,hitungbagi,j,hasil;
	
	i = 0;

	angka = 1;

     while(i<n){
		/*angka 2 termasuk bilangan prima */

         if(angka==2){
              i ++;
			  hasil=i*angka;
              printf("%d %d\n",i,hasil);
         }

		/*bilangan ganjil dan bukan angka 1*/
		else  if(angka%2==1 && angka!=1){
            hitungbagi=0;
            for(j=1;j<=angka;j++){
                if(angka%j==0){
                    hitungbagi++;
                }
            }
            if(hitungbagi==2){
                i++;
				hasil=i*angka;
				printf("%d %d\n",i,hasil);
            }
		}

        angka ++;
		//printf("%d\n",angka);
      }
}