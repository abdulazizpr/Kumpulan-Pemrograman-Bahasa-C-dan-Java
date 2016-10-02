class KerajinanKayu extends HasilKerajinan{
	
	private String fungsi_kerajinan;
	private int harga;
	
	KerajinanKayu(){
	}
	
	public void setFungsiKerajinan(String fungsi_kerajinan){
		this.fungsi_kerajinan = fungsi_kerajinan;
	}
	
	public String getFungsiKerajinan(){
		return this.fungsi_kerajinan;
	}
	
	public void setHarga(int harga){
		this.harga = harga;
	}
	
	public int getHarga(){
		return this.harga;
	}
	
}