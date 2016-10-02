#include"header.h"

int main(){

	char pita[300];
	scanf("%299[^\n]s", &pita);
	
	START(pita);
	int status=0;
	
	while(EOP() == 0)
	{
		/* printf("%d ",indeks);printf("%c\n", GETCC()); */
		INC(pita);
		char  a = GETCC();
		
		if(a == 'n' || a=='a')
		{
			if( (pita[indeks-1]!=' ') && ( (pita[indeks+1]!=' ') && (pita[indeks+1]!='.') ) ) 
			{
				status++;
				/* printf("		here\n"); */
			}
		}
	}
	
	printf("%d\n",status);

return 0;
}
