class Main{
	public static void main(String[] args){
		
		Pabrik opabrik = new Pabrik();
		Gudang ogudang = new Gudang();
	
		opabrik.setKodePabrik(1);
		opabrik.setNamaPabrik("Gangsir");
		opabrik.setAlamatPabrik("Bandung");
		opabrik.setTeleponPabrik("08188899977");
	
		System.out.println(opabrik.getKodePabrik());
		System.out.println(opabrik.getNamaPabrik());
		System.out.println(opabrik.getAlamatPabrik());
		System.out.println(opabrik.getTeleponPabrik());
		
	}
}