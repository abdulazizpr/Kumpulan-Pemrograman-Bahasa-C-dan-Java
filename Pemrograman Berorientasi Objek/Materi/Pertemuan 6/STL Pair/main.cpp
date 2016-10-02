#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int main (){
	int n;
	scanf("%d", &n);
	pair<int, int> data[n];

	int i;
	for(i=0;i<n;i++){
		scanf("%d %d", &data[i].first,&data[i].second);
	}
	
	printf("isi dari pair\n");
	for(i=0;i<n;i++){
		printf("%d %d\n",data[i].first, data[i].second);
	}
	
	return 0;
}