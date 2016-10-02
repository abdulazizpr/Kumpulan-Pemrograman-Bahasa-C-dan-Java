#include "header.h"

long long int faktor(int n){
	if((n==0) || (n==1)){
		return 1;
	}else{
		return(n*faktor(n-1));
	}
}