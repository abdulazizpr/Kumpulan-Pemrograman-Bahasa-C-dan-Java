class KelasSahabat{
	
	public:
		KelasSahabat(){
			/*Konstruktor*/
		}
		
		void aksesSahabat(Sahabat tm){
			//mengakses atribut private
			cout << "Kelas Friend" << endl;
			cout << "Nilai teman : " << tm.atributSahabat << endl;
			cout << "----------------------------------" << endl;
		}
	
};