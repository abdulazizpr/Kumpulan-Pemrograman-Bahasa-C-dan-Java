class Kayu{
	
	private int kodekayu;
	private String jenis_pohon;
	private int berat;
	private int volume;
	
	Kayu(){
	}
	
	Kayu(int kodekayu,String jenis_pohon,int berat,int volume){
		this.kodekayu = kodekayu;
		this.jenis_pohon = jenis_pohon;
		
	}
	
	public void setKodeKayu(int kodekayu){
		this.kodekayu = kodekayu;
	}
	
	public int getKodeKayu(){
		return this.kodekayu;
	}
	
	public void setJenisPohon(String jenis_pohon){
		this.jenis_pohon = jenis_pohon;
	}
	
	public String getJenisPohon(){
		return this.jenis_pohon;
	}
	
	public void setBerat(int berat){
		this.berat = berat;
	}
	
	public int getBerat(){
		return this.berat;
	}
	
	public void setVolume(int volume){
		this.volume = volume;
	}
	
	public int getVolume(){
		return this.volume;
	}
	
}