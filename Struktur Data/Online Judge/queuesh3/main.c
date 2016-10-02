#include "header.h"

int main(){
	
	
	queue Q1,Q2,Q3;
	createEmpty(&Q1);
	createEmpty(&Q2);
	createEmpty(&Q3);
	
	int waktu1,waktu;
	char nama[100],q1[3],q2[3],q3[3];
	int n,m,o,i;
	
	//scanf("%d",&waktu1);
	scanf("%s",&q1);
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d %s",&waktu,&nama);
		add(waktu,nama,&Q1);
	}
	
	scanf("%s",&q2);
	scanf("%d",&m);
	for(i=0;i<m;i++){
		scanf("%d %s",&waktu,&nama);
		add(waktu,nama,&Q2);
	}
	
	scanf("%s",&q3);
	scanf("%d",&o);
	for(i=0;i<o;i++){
		scanf("%d %s",&waktu,&nama);
		add(waktu,nama,&Q3);
	}
	
	if(hitungwaktu(Q1) > hitungwaktu(Q2) && hitungwaktu(Q1) > hitungwaktu(Q3)) printf("%d\n",hitungwaktu(Q1));
	else if(hitungwaktu(Q1) < hitungwaktu(Q2) && hitungwaktu(Q2) > hitungwaktu(Q3)) printf("%d\n",hitungwaktu(Q2));
	else printf("%d\n",hitungwaktu(Q3));
	
	
	
	return 0;
}