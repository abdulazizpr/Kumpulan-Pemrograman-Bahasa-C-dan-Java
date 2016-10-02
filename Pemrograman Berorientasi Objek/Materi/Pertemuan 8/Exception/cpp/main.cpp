#include <iostream>
using namespace std;
#include "Eksepsi.cpp"

int main(){
	
	Eksepsi eks;
	int tabInt[10];
	
	cout << "eksepsi throw standar" << endl;
	
	/*eksepsi throw standar*/
	
	try{
		eks.eksepsiThrowStandar(-1);
	}catch(exception::error e){
		cout << e.p << endl;
	}
	
	cout << "------------------" <<endl;
	cout << "eksepsi throw sendiri" << endl;
	
	/*eksepsi throw dengan kalimat sendiri*/
	
	try{
		eks.eksepsiThrowSendiri(-1);
	}catch(exception::error e){
		cout << e.p << endl;
	}
	
	cout << "------------------" <<endl;
	cout << "eksepsi try catch" << endl;
	
	/*eksepsi try catch karena mengakses indeks array lebih dari jumlah tempat array*/
	
	try{
		eks.eksepsiThrowIndexOutBounds(10,10,10,&tabInt[10]);
	}catch(exception::error e){
		cout << e.p << endl;
	}
	
	cout << "------------------" <<endl;
	
	return 0;
}