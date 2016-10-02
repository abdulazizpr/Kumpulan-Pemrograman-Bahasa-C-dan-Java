public class Balok{
	
	private int panjang;
	//panjang balok
	
	private int lebar;
	//lebar balok
	
	private int tinggi;
	//tinggi balok
	
	Balok(){
	//konstruktor kosong
	}
	
	Balok(int panjang,int lebar,int tinggi){
		//konstruktor langsung isi atribut
		this.panjang = panjang;
		this.lebar = lebar;
		this.tinggi = tinggi;
	}
	
	//get set
	public int getPanjang(){
		return this.panjang;
	}
	
	public int getLebar(){
		return this.lebar;
	}
	
	public int getTinggi(){
		return this.tinggi;
	}
	
	public int volume(){
		//menghitung volume balok
		return (panjang * lebar * tinggi);
	}
	
	public int luas(){
		//menghitung luas balok
		return ((2*panjang*lebar) + (2*panjang*tinggi) + (2*lebar*tinggi));
	}
	
	
}