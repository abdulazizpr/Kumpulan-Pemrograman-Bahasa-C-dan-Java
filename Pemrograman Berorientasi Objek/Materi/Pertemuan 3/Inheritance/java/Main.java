class Main{
	
	public static void main(String[] args){
		
		Manusia kmanusia = new Manusia();
		Karyawan kkaryawan = new Karyawan();
		
		kmanusia.setNama("Gina");
		kmanusia.setAlamat("Bandung");
		kmanusia.setNoKTP("320.120.777");
		kmanusia.setNoTelepon("08188899977");
		
		System.out.println(kmanusia.getNama());
		System.out.println(kmanusia.getAlamat());
		System.out.println(kmanusia.getNoKTP());
		System.out.println(kmanusia.getNoTelepon());
	
		kkaryawan.setNama("Gina");
		kkaryawan.setAlamat("Bandung");
		kkaryawan.setNoKTP("320.120.777");
		kkaryawan.setNoTelepon("08188899977");
		kkaryawan.setNomorPegawai("13202020");
		kkaryawan.setJabatan("-");
		kkaryawan.setDepartemen("-");
		
		System.out.println(kkaryawan.getNama());
		System.out.println(kkaryawan.getAlamat());
		System.out.println(kkaryawan.getNoKTP());
		System.out.println(kkaryawan.getNoTelepon());
		System.out.println(kkaryawan.getNomorPegawai());
		System.out.println(kkaryawan.getJabatan());
		System.out.println(kkaryawan.getDepartemen());
		
	}
	
}