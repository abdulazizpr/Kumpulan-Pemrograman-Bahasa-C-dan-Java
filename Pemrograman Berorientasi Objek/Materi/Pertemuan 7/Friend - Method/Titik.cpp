class Titik{
	
	private:
		int x;	/*koordinat x*/
		int y; 	/*koordinat y*/
	
	public:
		Titik(){
			/*konstruktor*/
			x = 0;
			y = 0;
		}
		
		Titik(int xp,int yp){
			/*konstruktor*/
			x = xp;
			y = xp;
		}
		
		void setX(int xp){
			/*mengembalikan nilai x*/
			x = xp;
		}
		
		void setY(int yp){
			/*mengembalikan nilai y*/
			y = yp;
		}
		
		/*funsgi friend*/
		friend void SahabatTitik::printTitik(const Titik &t);
	
};

/*method friend*/
void SahabatTitik::printTitik(const Titik &t){
	/*bisa mengakses atribut private*/
	cout << "Metode Friend" << endl;
	cout << "Titik : x : " << t.x << " y : " << t.y << endl;
	cout << "----------------------------------" << endl;
}