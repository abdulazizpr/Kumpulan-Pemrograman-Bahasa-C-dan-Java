class Main{
	
	public static void main(String[] args){
		
		Eksepsi eks = new Eksepsi();
		int[] tabInt = new int[10];
		
		System.out.println("eksepsi throw standar");
		/*eksepsi throw standar*/
		
		try{
			eks.eksepsiThrowStandar(-1);
		}catch(Exception e){
			e.printStackTrace();
		}
		
		System.out.println("-------------------------");
		
		System.out.println("eksepsi throw sendiri");
		/*eksepsi throw standar*/
		
		try{
			eks.eksepsiThrowSendiri(-1);
		}catch(Exception e){
			e.printStackTrace();
		}
		
		System.out.println("-------------------------");
		
		System.out.println("eksepsi try catch");
		/*eksepsi try catch karena mengakses indeks array lebih dari jumlah tempat array*/
		
		try{
			tabInt[10] = 10;
		}catch(Exception e){
			e.printStackTrace();
		}
		
		System.out.println("-------------------------");
		
	}
	
}