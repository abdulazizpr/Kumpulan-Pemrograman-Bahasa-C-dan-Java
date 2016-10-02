class Aset{
	
	private:
		int kodeAset;
		int jenisAset;
		double nilaiAset;
	
	public:
		Aset(){
		}
		
		void setKodeAset(int kodeAset){
			this->kodeAset = kodeAset;
		}
		
		int getKodeAset(){
			return this->kodeAset;
		}
		
		void setJenisAset(int jenis){
			this->jenisAset = jenis;
		}
		
		int getJenisAset(){
			return this->jenisAset;
		}
		
		void setNilaiAset(double nilai){
			this->nilaiAset = nilai;
		}
		
		int getNilaiAset(){
			return this->nilaiAset;
		}
		
		~Aset(){
		}
};