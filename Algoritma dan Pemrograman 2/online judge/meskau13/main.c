#include "header.h"

//menghitung banyak kata dalam pita
int main(){

	char pita[300];
	bungkusan hasil[100];
	int status=0, i,j;
	int lebar;
	int banyakkata[100];
	
	scanf("%299[^\n]s", &pita);
	//scanf("%d",&lebar);
	
	STARTKATA(pita);
	for(i=0;i<GETPANJANGKATA();i++){
		if(ckata[i]=='a')
		{
			strcpy(hasil[status].kata,GETCKATA());
		}
	}
	status++;
	while(EOPKATA(pita) == 0)
	{
		INCKATA(pita);
		for(i=0;i<GETPANJANGKATA();i++){
			hasil[status].jumlah_a=0;
			if(ckata[i]=='a')
			{
				strcpy(hasil[status].kata,GETCKATA());
			}
		}
		status++;
	}
	
	for(i=0;i<status;i++){
		hasil[i].jumlah_a=0;
		for(j=0;j<strlen(hasil[i].kata);j++){
			if(hasil[i].kata[j]=='a'){
				hasil[i].jumlah_a++;
			}
		}
		
	}
	
	insertionsort(status,hasil);
	
	for(i=0;i<status;i++){
		printf("%s",hasil[i].kata);
		if(i<status-1){
			printf(" ");
		}
	}
	printf("\n");
	

return 0;	
}	