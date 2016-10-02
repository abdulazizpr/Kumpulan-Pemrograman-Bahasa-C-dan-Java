class Titik3D : public Titik{
	
	private:
		int z;	//koordinat z
	
	public:
		Titik3D(){
			/*konstruktor*/
			z = 0;
		}
	
		Titik3D(int xp,int yp,int zp){
			/*konstruktor*/
			setX(xp);
			setY(yp);
			z = zp;
		}
		
		/*fungsi friend*/
		friend void tampilkanTitik(Titik t1,Titik3D t2);
		
	protected:
		int getZ(){
			/*mengembalikan nilzi z*/
			return z;
		}
	
};