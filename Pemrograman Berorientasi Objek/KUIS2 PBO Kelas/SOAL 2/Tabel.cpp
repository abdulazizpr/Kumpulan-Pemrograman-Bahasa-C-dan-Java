class Atrribut;

class Tabel{
	
	private:
		int baris;
		int kolom;
	
	public:
		/*konstruktor*/
		Tabel(){
		}
		
		Tabel(int b,int k){
			this->baris = b;
			this->kolom = k;
		}
		
		/*method get dan set*/
		void setBaris(int b){
			this->baris = b;
		}
		
		int getBaris(){
			return this->baris;
		}
		
		void setKolom(int k){
			this->kolom = k;
		}
		
		int getKolom(){
			return this->kolom;
		}
		
		/*untuk membuat tabel*/
		void buatBaris(string isi[],int add,int n){
			
			for(int i=0;i<n;i++){
				for(int j=0;j<isi[i].length();j++){
					cout << "-" << ends;
				}
			}
			cout << endl;
			
			for(int i=0;i<n;i++){
				cout << "| " << ends;
				cout << isi[i] << ends;
				for(int j=0;j<(add-3);j++){
					cout << " " << ends;
				}
				cout << "|" << ends;
			}
			cout << endl;
		}
		
		/*mengakses di kelas atribut*/
		friend class Atrribut;
	
};