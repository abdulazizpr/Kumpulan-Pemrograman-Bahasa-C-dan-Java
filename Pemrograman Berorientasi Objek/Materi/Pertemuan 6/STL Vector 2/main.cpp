#include <vector>
#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;
int main(){
	
	vector<int> vc;
	
	vc.push_back(6);
	vc.push_back(2);
	vc.push_back(7);
	vc.push_back(4);
	vc.push_back(9);

	sort(vc.begin(), vc.end());

	int i;
	do{
		for(i=0;i<vc.size();i++){
			printf("%d ",vc[i]);
		}
		printf("\n");
	}while(next_permutation(vc.begin(), vc.end()));
	
	return 0;
}