class Kamar extends Gedung implements Ruangan {
	
	private String nomorKamar;
	private String namaKamar;
	private String kegunaan;
	private String kelas;
	private String nomorRuangan;
	private int panjangRuangan;
	private int lebarRuangan;
	private String fungsiRuangan;
	
	Kamar(){
	}
	
	public void setNomorKamar(String nomor){
		this.nomorKamar = nomor;
	}
	
	public String getNomorKamar(){
		return this.nomorKamar;
	}
	
	public void setNamaKamar(String nama){
		this.namaKamar = nama;
	}
	
	public String getNamaKamar(){
		return this.namaKamar;
	}
	
	public void setKegunaan(String kegunaan){
		this.kegunaan = kegunaan;
	}
	
	public String getKegunaan(){
		return this.kegunaan;
	}
	
	public void setKelas(String kelas){
		this.kelas = kelas;
	}
	
	public String getKelas(){
		return this.kelas;
	}
	
	public void setNomorRuangan(String nomor){
		this.nomorRuangan = nomor;
	}
	
	public String getNomorRuangan(){
		return this.nomorRuangan;
	}
	
	public void setPanjangRuangan(int panjang){
		this.panjangRuangan = panjang;
	}
	
	public int getPanjangRuangan(){
		return this.panjangRuangan;
	}
	
	public void setLebarRuangan(int lebar){
		this.lebarRuangan = lebar;
	}
	
	public int getLebarRuangan(){
		return this.lebarRuangan;
	}
	
	public void setFungsiRuangan(String fungsi){
		this.fungsiRuangan = fungsi;
	}
	
	public String getFungsiRuangan(){
		return this.fungsiRuangan;
	}
}