#include <iostream>
#include <string>

using namespace std;

class Buku{
	private:
		string judul;
		string pengarang;
	
	public:
		Buku(){
		}
	
	Buku(string j,string p){
		judul = j;
		pengarang = p;
	}
	
	void setJudul(string j){
		judul = j;
	}
	
	void setPengarang(string p){
		pengarang = p;
	}
	
	string getJudul(){
		return judul;
	}
	
	string getPengarang(){
		return pengarang;
	}
	
	~Buku(){
	}
};