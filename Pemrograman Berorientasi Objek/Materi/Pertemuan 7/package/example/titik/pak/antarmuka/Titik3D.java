package example.titik.pak.antarmuka;

class Titik3D implements Titik{
	
	private int x; /*koordinat x*/
	private int y; /*koordinat y*/
	private int z; /*koordinat z*/
	
	Titik3D(){
		/*konstruktor*/
		x = 0;
		y = 0;
		z = 0;
	}
	
	Titik3D(int xp,int yp,int zp){
		/*konstruktor*/
		x = xp;
		y = yp;
		z = zp;
	}
	
	public void setX(int xp){
		/*mengeset nilai koordinat x*/
		x = xp;
	}
	
	public int getX(){
		/*mengeset nilai koordinat x*/
		return x;
	}
	
	public void setY(int yp){
		/*mengeset nilai koordinat x*/
		y = yp;
	}
	
	public int getY(){
		/*mengeset nilai koordinat x*/
		return yp;
	}
	
	public void setZ(int zp){
		/*mengeset nilai koordinat x*/
		z = zp;
	}
	
	public int getZ(){
		/*mengeset nilai koordinat x*/
		return zp;
	}
	
	public void printTitik(){
		/*menampilkan nilai koordinat titik*/
		System.out.println("nilai X : " + getX());
		System.out.println("nilai Y : " + getY());
		System.out.println("nilai Z : " + getZ());
	}
	
}