class LastThread extends Thread{
	
	LastThread(){
		/*konstruktor*/
	}
	
	public void run(){
		int i;
		for(i=0;i<10;i++){
			System.out.println("proses LastThread");
			try{
				sleep(1000);
			}catch(Exception e){
				e.printStackTrace();
			}
		}
	}
	
}