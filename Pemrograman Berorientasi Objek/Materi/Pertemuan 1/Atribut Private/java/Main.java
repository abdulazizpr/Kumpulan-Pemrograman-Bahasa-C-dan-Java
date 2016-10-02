class Main{
	
	public static void main(String[] args){
		
		Buku b1;
		Buku b2;
		
		b1 = new Buku();
		b1.setJudul("J2ME");
		b1.setPengarang("Orang_1");
		System.out.println(b1.getJudul());
		System.out.println(b1.getPengarang());
		
		b2 = new Buku("J2MEE","Orang_2");
		System.out.println(b2.getJudul());
		System.out.println(b2.getPengarang());
		
	}
	
}