#include "header.h"

int cek_a(char kata[]){
	
	int hasil=0, i;
	for(i=0;i<strlen(kata);i++) if(kata[i]=='a') hasil++;
	
	return hasil;
}

int main(){
	
	list L;
	createList(&L);
	
	int n,i;
	scanf("%d",&n);
	
	data kalimat[n];
	for(i=0;i<n;i++){
		scanf("%s",&kalimat[i].kata);
		kalimat[i].jumlah_a=cek_a(kalimat[i].kata);

		if(countElement(L)<3){
			addFirst(kalimat[i].kata,&L);
		}else{
			if(kalimat[i].jumlah_a%2==0) addAfter(L.tail->prev->prev,kalimat[i].kata,&L);
			else addFirst(kalimat[i].kata,&L);
		}
	}
	
	printElement(L);
	
	return 0;
}