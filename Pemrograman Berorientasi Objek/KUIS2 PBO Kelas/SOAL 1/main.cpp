#include <cstdio>
#include <iostream>
using namespace std;
#include "Mesin.cpp"

/*
Sumpah :
Saya Abdul Aziz Priatna tidak melakukan kecurangan seperti yang telah dispesifikasikan 
pada mata kuliah Pemrograman Berorientasi Objek dalam mengerjakan Kuis 2, jika saya melakukan kecurangan 
maka Allah/Tuhan adalah saksi saya, dan saya bersedia menerima hukumanNya. Aamiin.
*/

int main(){
	
	int n,m;
	
	/*masukan banyaknya\ array*/
	cout << "Masukan banyaknya array : ";
	cin >> n;
	
	/*masukan isi array yang ditampilkan ke samping*/
	cout << "Masukan banyaknya isi array yg ditampilkan ke samping : ";
	cin >> m;
	
	/*masukan array*/
	string arr[n];
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	
	/*masukan ke dalam template*/
	tulis(arr,n,m);
	
	return 0;
}