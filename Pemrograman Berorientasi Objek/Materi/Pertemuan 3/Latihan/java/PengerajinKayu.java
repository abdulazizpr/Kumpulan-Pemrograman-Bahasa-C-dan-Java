class PengerajinKayu extends Pengusaha{
	
	private String noKTP;
	private double omsetPerBulan;
	private String deskripsi;
	
	PengerajinKayu(){
	}
	
	public void setNoKTP(String noKTP){
		this.noKTP = noKTP;
	}
	
	public String getNoKTP(){
		return this.noKTP;
	}
	
	public void setOmsetPerBulan(double omsetPerBulan){
		this.omsetPerBulan = omsetPerBulan;
	}
	
	public double getOmsetPerBulan(){
		return this.omsetPerBulan;
	}
	
	public void setDeskripsi(String deskripsi){
		this.deskripsi = deskripsi;
	}
	
	public String getDeskripsi(){
		return this.deskripsi;
	}
}