class Titik;
class SahabatTitik{
	
	private:
		int atributSahabatTitik;
		
	public:
		SahabatTitik();
		
		void printTitik(const Titik &t);
};

SahabatTitik::SahabatTitik(){
	/*konstruktor*/
	atributSahabatTitik = 89;
}