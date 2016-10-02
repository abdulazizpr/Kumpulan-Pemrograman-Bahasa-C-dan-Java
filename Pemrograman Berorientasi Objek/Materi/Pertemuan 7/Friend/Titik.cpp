class Titik3D;
class Titik{
	
	private:
		int x; //koordinat x
		int y; //koordinat y
		
	public:
		Titik(){
			/*konstruktor*/
			x = 0;
			y = 0;
		}
		
		Titik(int xp,int yp){
			/*konstruktor*/
			x = xp;
			y = yp;
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
		friend void tampilkanTitik(Titik t1,Titik3D t2);
	
};