class Pasien extends Kamar implements Penyakit{
	
	private String kodePasien;
	private String namaPasien;
	private String kodePenyakit;
	private String namaPenyakit;
	private String deskripsiPenyakit;
	
	Pasien(){
	}
	
	public void setKodePasien(String kode){
		this.kodePasien = kode;
	}
	
	public String getKodePasien(){
		return this.kodePasien;
	}
	
	public void setNamaPasien(String nama){
		this.namaPasien = nama;
	}
	
	public String getNamaPasien(){
		return this.namaPasien;
	}
	
	public void setNomorPenyakit(String kode){
		this.kodePenyakit = kode;
	}
	
	public String getNomorPenyakit(){
		return this.kodePenyakit;
	}
	
	public void setNamaPenyakit(String nama){
		this.namaPenyakit = nama;
	}
	
	public String getNamaPenyakit(){
		return this.namaPenyakit;
	}
	
	public void setDeskripsiPenyakit(String deskripsiPenyakit){
		this.deskripsiPenyakit = deskripsiPenyakit;
	}
	
	public String getDeskripsiPenyakit(){
		return this.deskripsiPenyakit;
	}
	
}