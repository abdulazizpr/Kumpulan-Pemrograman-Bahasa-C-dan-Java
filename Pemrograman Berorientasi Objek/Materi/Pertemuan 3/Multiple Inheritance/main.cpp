#include <string>
#include <iostream>
using namespace std;
#include "Asset.cpp"
#include "Pabrik.cpp"
#include "Gudang.cpp"

int main(){
	
	Aset oaset;
	Pabrik opabrik;
	Gudang ogudang;
	
	oaset.setKodeAset(1);
	oaset.setJenisAset(1);
	oaset.setNilaiAset(300000000);
	
	cout << oaset.getKodeAset() << endl;
	cout << oaset.getJenisAset() << endl;
	cout << oaset.getNilaiAset() << endl;
	
	opabrik.setKodePabrik(1);
	opabrik.setNamaPabrik("BDG Aaamiin");
	opabrik.setAlamatPabrik("Bandung");
	opabrik.setTeleponPabrik("08188899977");
	
	cout << opabrik.getKodePabrik() << endl;
	cout << opabrik.getNamaPabrik() << endl;
	cout << opabrik.getAlamatPabrik() << endl;
	cout << opabrik.getTeleponPabrik() << endl;
	
	ogudang.setKodeAset(3);
	ogudang.setJenisAset(3);
	ogudang.setNilaiAset(300000000);
	ogudang.setKodePabrik(3);
	ogudang.setNamaPabrik("BDG Aamiin");
	ogudang.setAlamatPabrik("Bandung");
	ogudang.setTeleponPabrik("08188899977");
	ogudang.setKodeGudang(1);
	ogudang.setNamaGudang("BDG Aaamiin I");
	ogudang.setAlamatGudang("Bandung");
	
	cout << ogudang.getKodeAset() << endl;
	cout << ogudang.getJenisAset() << endl;
	cout << ogudang.getNilaiAset() << endl;
	cout << ogudang.getKodePabrik() << endl;
	cout << ogudang.getNamaPabrik() << endl;
	cout << ogudang.getAlamatPabrik() << endl;
	cout << ogudang.getTeleponPabrik() << endl;
	cout << ogudang.getKodeGudang() << endl;
	cout << ogudang.getNamaGudang() << endl;
	cout << ogudang.getAlamatGudang() << endl;
	
	return 0;
}