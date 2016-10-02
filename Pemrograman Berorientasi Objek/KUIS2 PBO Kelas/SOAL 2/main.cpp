#include <cstdio>
#include <iostream>
using namespace std;
#include "Tabel.cpp"
#include "AlatTulis.cpp"
#include "Atribut.cpp"

/*
Sumpah :
Saya Abdul Aziz Priatna tidak melakukan kecurangan seperti yang telah dispesifikasikan 
pada mata kuliah Pemrograman Berorientasi Objek dalam mengerjakan Kuis 2, jika saya melakukan kecurangan 
maka Allah/Tuhan adalah saksi saya, dan saya bersedia menerima hukumanNya. Aamiin.
*/

int main(){
	
	//instansisai
	AlatTulis at[3];
	Atribut ab;
	
	//masukan hardcode
	at[0].setKodeAlatTulis("K001");
	at[0].setNamaAlatTulis("Pensil");
	at[0].setHarga("12000");
	
	at[1].setKodeAlatTulis("K002");
	at[1].setNamaAlatTulis("Pulpen");
	at[1].setHarga("13000");
	
	at[2].setKodeAlatTulis("K003");
	at[2].setNamaAlatTulis("Buku");
	at[2].setHarga("14000");
	
	//instansiasi tabel
	Tabel tab(3,3);
	
	//mengakses alat tulis dan tabel di kelas Atribut
	ab.AksesAtribut(tab,at,3);
	
	return 0;
}