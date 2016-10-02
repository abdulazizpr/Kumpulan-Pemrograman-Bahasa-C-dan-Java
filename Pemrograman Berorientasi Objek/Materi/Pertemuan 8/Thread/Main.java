class Main{
	
	public static void main(String[] args){
		
		LastThread lt = new LastThread();
		
		lt.start();
		
		NewThread nt = new NewThread();
		
	}
	
}