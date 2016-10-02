class Karyawan extends Manusia{
	
	private String nomor_pegawai;
	private String jabatan;
	private String departemen;
	
	Karyawan(){
	}
	
	public void setNomorPegawai(String nomor){
		this.nomor_pegawai = nomor;
	}
	
	public String getNomorPegawai(){
		return this.nomor_pegawai;
	}
	
	public void setJabatan(String jabatan){
		this.jabatan = jabatan;
	}
	
	public String getJabatan(){
		return this.jabatan;
	}
	
	public void setDepartemen(String departemen){
		this.departemen = departemen;
	}
	
	public String getDepartemen(){
		return this.departemen;
	}
	
}