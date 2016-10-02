#include <vector>
#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

int main(){
	
	vector<string> vc;
	
	vc.push_back("merah");
	vc.push_back("kuning");
	vc.push_back("hijau");
	vc.push_back("biru");
	vc.push_back("jingga");
	
	sort(vc.begin(), vc.end());
	
	int i;
	do{
		for(i=0;i<vc.size();i++){
			printf("%s ",vc[i].c_str());
		}
		printf("\n");
	}while(next_permutation(vc.begin(), vc.end()));
	
	
	return 0;
}