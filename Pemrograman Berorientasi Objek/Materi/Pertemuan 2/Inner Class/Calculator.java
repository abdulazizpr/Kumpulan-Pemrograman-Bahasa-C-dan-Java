class Calculator{
	
	private Operasi opr;
	
	Calculator(){
		opr = new Operasi();
	}
	
	Operasi getOpr(){
		return opr;
	}
	
	class Operasi{
		Operasi(){
		}
		
		int tambah(int x,int y){
			return (x+y);
		}
		
		int kurang(int x,int y){
			return (x-y);
		}
		
		int kali(int x,int y){
			return (x*y);
		}
		
		int bagi(int x,int y){
			if(y > 0){ 
				return (x/y);
			}else{
				return -999999;
			}
		}
		
	}
}