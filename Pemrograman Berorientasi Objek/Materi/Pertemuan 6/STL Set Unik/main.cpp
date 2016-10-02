#include <cstdio>
#include <vector>
#include <set>
#include <string>
using namespace std;
int main (){

	//string
	set<string> s;
	s.insert("Hello");
	s.insert("World");
	s.insert("Hello");
	s.insert("World");
	set<string>::const_iterator it;

	vector<string> str;
	//mending dipindah ke vector kalau memang sudah unik di set
	
	int i = 0;
	for (it =s.begin();it!=s.end();it++) {
		str.push_back("" + *it);
		printf("%s\n", str[i].c_str());
		i++;
	}

	return 0;
}	