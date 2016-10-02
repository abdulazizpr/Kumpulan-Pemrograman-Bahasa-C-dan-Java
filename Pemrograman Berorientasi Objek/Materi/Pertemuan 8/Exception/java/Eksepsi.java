class Eksepsi{
	
	Eksepsi(){
		/*konstrutor*/
	}
	
	public void eksepsiThrowStandar(int kode) throws Exception{
		if(kode < 1){
			Exception e = new Exception();
			throw e;
		}
	}
	
	public void eksepsiThrowSendiri(int kode) throws Exception{
		if(kode < 1){
			Exception e = new Exception("error");
			throw e;
		}
	}
	
}