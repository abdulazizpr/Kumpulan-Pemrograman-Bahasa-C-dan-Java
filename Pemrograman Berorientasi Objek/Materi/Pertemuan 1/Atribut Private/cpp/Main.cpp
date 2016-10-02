#include "Buku.cpp"

int main(){
	
	Buku b1;
	b1.setJudul("J2ME");
	b1.setPengarang("Orang_1");
	
	cout << b1.getJudul() << endl;
	cout << b1.getPengarang() << endl;
	
	Buku b2("J2ME","Orang_2");
	cout << b2.getJudul() << endl;
	cout << b2.getPengarang() << endl;
	
	return 0;
}