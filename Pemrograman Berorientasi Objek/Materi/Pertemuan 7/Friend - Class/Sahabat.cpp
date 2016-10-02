class KelasSahabat;

class Sahabat{
	
	private:
		int atributSahabat;
		
	public:
		Sahabat(){
			/*konstruktor*/
			atributSahabat = 89;
		}
		
		/*kelas teman*/
		friend class KelasSahabat;
};