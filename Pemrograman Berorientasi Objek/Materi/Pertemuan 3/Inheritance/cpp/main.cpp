#include <string>
#include <iostream>
using namespace std;
#include "Manusia.cpp"
#include "Karyawan.cpp"

int main(){
	
	Manusia kmanusia;
	Karyawan kkaryawan;
	
	kmanusia.setNama("Gina");
	kmanusia.setAlamat("Bandung");
	kmanusia.setNoKTP("320.120.777");
	kmanusia.setNoTelepon("08188899977");
	
	cout << kmanusia.getNama() << endl;
	cout << kmanusia.getAlamat() << endl;
	cout << kmanusia.getNoKTP() << endl;
	cout << kmanusia.getNoTelepon() << endl;
	
	kkaryawan.setNama("Gina");
	kkaryawan.setAlamat("Bandung");
	kkaryawan.setNoKTP("320.120.777");
	kkaryawan.setNoTelepon("08188899977");
	kkaryawan.setNomorPegawai("13202020");
	kkaryawan.setJabatan("-");
	kkaryawan.setDepartemen("-");
	
	cout << kkaryawan.getNama() << endl;
	cout << kkaryawan.getAlamat() << endl;
	cout << kkaryawan.getNoKTP() << endl;
	cout << kkaryawan.getNoTelepon() << endl;
	cout << kkaryawan.getNomorPegawai() << endl;
	cout << kkaryawan.getJabatan() << endl;
	cout << kkaryawan.getDepartemen() << endl;
	
	return 0;
}