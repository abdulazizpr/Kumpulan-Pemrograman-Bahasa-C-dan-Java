class Gudang extends Pabrik implements Aset{
	
	private int kodeAset;
	private int jenisAset;
	private double nilaiAset;
	private int kodeGudang;
	private String namaGudang;
	private String alamatGudang;
	
	Gudang(){
	}
	
	public void setKodeAset(int kodeAset){
		this.kodeAset = kodeAset;
	}
	
	public int getKodeAset(){
		return this.kodeAset;
	}
	
	public void setJenisAset(int jenisAset){
		this.jenisAset = jenisAset;
	}
	
	public int getJenisAset(){
		return this.jenisAset;
	}
	
	public void setNilaiAset(double nilaiGudang){
		this.nilaiAset = nilaiAset;
	}
	
	public double getNilaiAset(){
		return this.nilaiAset;
	}
	
	public void setKodeGudang(int kodeGudang){
		this.kodeGudang = kodeGudang;
	}
	
	public int getKodeGudang(){
		return this.kodeGudang;
	}
	
	public void setNamaGudang(String namaGudang){
		this.namaGudang = namaGudang;
	}
	
	public String getNamaGudang(){
		return this.namaGudang;
	}
	
	public void setAlamatGudang(String alamatGudang){
		this.alamatGudang = alamatGudang;
	}
	
	public String getAlamatGudang(){
		return this.alamatGudang;
	}
	
}