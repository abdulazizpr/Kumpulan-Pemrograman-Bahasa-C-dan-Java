#include <stdio.h>

int main(){
	
	int n,m,k,h,r;
	scanf("%d",&n);
	scanf("%d",&m);
	scanf("%d",&k);
	scanf("%d",&h);
	scanf("%d",&r);
	
	int gehu,bala2,pisgor,cireng,total;
	gehu=n*(500-400);
	bala2=m*(500-350);
	pisgor=k*(500-425);
	cireng=h*(500-325);
	
	total=(gehu+bala2+cireng+pisgor)*r;
	
	printf("%d\n",total);
	
return 0;	
}