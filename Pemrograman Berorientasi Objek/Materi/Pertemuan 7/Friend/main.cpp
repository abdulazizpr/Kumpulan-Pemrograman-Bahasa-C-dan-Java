#include <iostream>
using namespace std;
#include "Titik.cpp"
#include "Titik3D.cpp"

/*fungsi friend*/
//bisa hanya satu masukan
void tampilkanTitik(Titik t1,Titik3D t2){
	//bisa mengakses atribut private
	cout << "Fungsi Friend" << endl;
	cout << "Titik : x : " << t1.x << " y : " << t1.y << endl;
	cout << "Titik3D : x : " << t2.x << " y : " << t2.y << " z : " << t2.getZ() << endl;
	cout << "----------------------------------" << endl;
	
}

int main(){
	
	Titik t1(28,1);
	Titik3D t2(28,1,7);
	
	tampilkanTitik(t1,t2);
	
	return 0;
}