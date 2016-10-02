class Staf{
	
	private String kodeStaf;
	private String namaStaf;
	private String unit;
	
	Staf(){
	}
	
	public void setNomorStaf(String kode){
		this.kodeStaf = kode;
	}
	
	public String getKodeStaf(){
		return this.kodeStaf;
	}
	
	public void setNamaStaf(String nama){
		this.namaStaf = nama;
	}
	
	public String getNamaStaf(){
		return this.namaStaf;
	}
	
	public void setUnit(String unit){
		this.unit = unit;
	}
	
	public String getUnit(){
		return this.unit;
	}
	
}