class Atribut;

class AlatTulis{
	
	private:
		string kode_alat_tulis;
		string nama_alat_tulis;
		string harga;
	
	public:
		/*konstruktor*/
		AlatTulis(){
		}
		
		AlatTulis(string a,string b,int c){
			this->kode_alat_tulis = a;
			this->nama_alat_tulis = b;
			this->harga = c;
		}
		
		/*method get set*/
		void setKodeAlatTulis(string a){
			this->kode_alat_tulis = a;
		}
		
		string getKodeAlatTulis(){
			return this->kode_alat_tulis;
		}
		
		void setNamaAlatTulis(string a){
			this->nama_alat_tulis = a;
		}
		
		string getNamaAlatTulis(){
			return this->nama_alat_tulis;
		}
		
		
		void setHarga(string c){
			this->harga = c;
		}
		
		string getHarga(){
			return this->harga;
		}
		
		/*uuntuk mengakses di kelas Atribut*/
		friend class Atribut;
};