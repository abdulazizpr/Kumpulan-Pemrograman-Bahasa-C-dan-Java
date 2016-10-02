class Gedung{
	
	private String kodeGedung;
	private String namaGedung;
	private String fungsiGedung;
	
	Gedung(){
	}
	
	public void setKodeGedung(String kode){
		this.kodeGedung = kode;
	}
	
	public String getKodeGedung(){
		return this.kodeGedung;
	}
	
	public void setNamaGedung(String nama){
		this.namaGedung = nama;
	}
	
	public String getNamaGedung(){
		return this.namaGedung;
	}
	
	public void setFungsiGedung(String fungsi){
		this.fungsiGedung = fungsi;
	}
	
	public String getFungsiGedung(){
		return this.fungsiGedung;
	}
	
}