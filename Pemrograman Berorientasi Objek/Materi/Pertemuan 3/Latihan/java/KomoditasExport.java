class KomodiExport{
	
	private int kode_komoditas;
	private String negara_tujuan;
	private String jenis_komoditas;
	
	KomodiExport(){
	}
	
	public void setKodeKomoditas(int kode_komoditas){
		this.kode_komoditas = kode_komoditas;
	}
	
	public int getKodeKomoditas(){
		return this.kode_komoditas;
	}
	
	public void setNegaraTujuan(String negara_tujuan){
		this.negara_tujuan = negara_tujuan;
	}
	
	public String getNegaraTujuan(){
		return this.negara_tujuan;
	}
	
	public void setJenisKomoditas(String jenis_komoditas){
		this.jenis_komoditas = jenis_komoditas;
	}
	
	public String getJenisKomoditas(){
		return this.jenis_komoditas;
	}
	
	
}