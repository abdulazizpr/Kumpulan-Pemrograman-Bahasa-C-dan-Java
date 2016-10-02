public class Tabel{
	
	private int baris;
	//banyaknya baris
	
	private int kolom;
	//banyaknya kolom
	
	Tabel(){
	}
	
	Tabel(int baris, int kolom){
		//konstruktor langsung mengisi atribut
		this.baris = baris;
		this.kolom = kolom;
	}
	
	public void setBaris(int baris){
		//mengeset
		this.baris = baris;
	}
	
	public void buatHeader(String[] isi,int add){
		int i = 0, j = 0;//inisialisasi variabel di java
		
		//buat tabel bagian atas
		for(i=0;i<isi.length;i++){
			for(j=0;j<(isi[i].length()+add);j++){
				System.out.print("-");
			}
		}
		System.out.println("");
		
		//buat baris isi
		for(i=0;i<isi.length;i++){
			System.out.print("| ");
			System.out.print(isi[i]);
			for(j=0;j<(add-3);j++){
				System.out.print(" ");
			}
			System.out.print("|");
		}
		System.out.println("");		
	}
	
	public void buatBaris(String[] isi,int add){
		int i = 0, j = 0;//inisialisasi variabel di java
		
		//buat tabel bagian atas
		for(i=0;i<isi.length;i++){
			for(j=0;j<(isi[i].length()+add);j++){
				System.out.print("-");
			}
		}
		System.out.println("");
		
		//buat baris isi
		for(i=0;i<isi.length;i++){
			System.out.print("| ");
			System.out.print(isi[i]);
			for(j=0;j<(add-3);j++){
				System.out.print(" ");
			}
			System.out.print("|");
		}
		System.out.println("");
		
	}
}