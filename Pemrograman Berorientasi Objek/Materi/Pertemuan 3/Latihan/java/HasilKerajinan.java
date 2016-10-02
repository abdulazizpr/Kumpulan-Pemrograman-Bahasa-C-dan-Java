class HasilKerajinan{
	
	private int kode_kerajinan;
	private String bahan;
	private String nama_kerajinan;
	
	HasilKerajinan(){
	}
	
	public void setKodeKerajinan(int kode_kerajinan){
		this.kode_kerajinan = kode_kerajinan;
	}
	
	public int getKodeKerajinan(){
		return this.kode_kerajinan;
	}
	
	public void setBahan(String bahan){
		this.bahan = bahan;
	}
	
	public String getBahan(){
		return this.bahan;
	}
	
	public void setNamaKerajinan(String nama_kerajinan){
		this.nama_kerajinan = nama_kerajinan;
	}
	
	public String getNamaKerajinan(){
		return this.nama_kerajinan;
	}
	
}