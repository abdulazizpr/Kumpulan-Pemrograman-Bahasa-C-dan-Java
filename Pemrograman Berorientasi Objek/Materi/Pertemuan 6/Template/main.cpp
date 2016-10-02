#include <cstdio>
#include <iostream>
using namespace std;
#include "Mesin.cpp"
#include "Titik.cpp"
#include "Tulis.cpp"

int main(){
	
	Titik<int> t1(28, 1);
	string kata = "membahasa template";
	
	tulisMasukan(18);
	tulisMasukan(28.11);
	tulisMasukan("prosedur tulisMasukan dengan masukan string");
	
	keluaran(11, 11.82);
	keluaran(9, 11.82);
	keluaran(9.81, 11.82);
	keluaranO('A');
	keluaranO(81);
	keluaranO(82.81);
	keluaranO(3 , 5);
	keluaranO(18.9 , 28.11);
	
	cout << "t1 : x :" << t1.getX() << "y : " << t1.getY() << endl;
	
	Tulis<string> t(kata);
	
	return 0;
}