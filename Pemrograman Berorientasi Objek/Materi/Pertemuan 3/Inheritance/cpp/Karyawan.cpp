class Karyawan : public Manusia{
	
	private:
		string nomor_pegawai;
		string jabatan;
		string departemen;
	
	public:
		Karyawan(){
		}
		
		void setNomorPegawai(string nomor){
			this->nomor_pegawai = nomor;
		}
		
		string getNomorPegawai(){
			return this->nomor_pegawai;
		}
		
		void setJabatan(string jabatan){
			this->jabatan = jabatan;
		}
		
		string getJabatan(){
			return this->jabatan;
		}
		
		void setDepartemen(string departemen){
			this->departemen = departemen;
		}
		
		string getDepartemen(){
			return this->departemen;
		}
		
		~Karyawan(){
		}
		
};