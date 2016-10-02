#include <stdio.h>
#include <string.h>

//bungkusan
typedef struct{
	char binner[8];
	int desimal;
	int bilanganbiner[8];
}bungkusan;

//prosedur dan fungsi
int konversibiner(int ,bungkusan* );
char* penjumlahanbiner(int ,bungkusan* ,bungkusan* );
void sorting(bungkusan* ,int );
void merge(bungkusan [],bungkusan [],bungkusan [],int ,int );
void binary_search(bungkusan* ,int ,int );