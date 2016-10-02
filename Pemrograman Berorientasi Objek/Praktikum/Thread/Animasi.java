public class Animasi extends Thread{
	
	private int panjang;
	private int tinggi;
	private int x;
	private int y;
	private String atas;
	private String samping;
	
	public Animasi(int a,int b){
		panjang = a;
		tinggi = b;
		x = 1;
		y = 0;
		atas = "atas";
		samping = "kanan";
	}
	
	public void run(){
		while(true){
			for(int i = 0;i<panjang+2;i++){
				System.out.print("=");
			}
			System.out.println();
			for(int i=0;i<tinggi;i++){
				for(int j=0;j<panjang+2;j++){
					if(j==0 || j==panjang+1){
						System.out.print("|");
					}else if(i==y && j==x){
						System.out.print("0");
					}else{
						System.out.print(" ");
					}
				}System.out.println();
			}
			for(int i=0;i<panjang+2;i++){
				System.out.print("=");
			}
			System.out.println();
			System.out.println();
			try{
				this.sleep(1000);
			}catch(Exception e){
				e.printStackTrace();
			}
			gerak(atas,samping);
		}
	}
	
	public void gerak(String vertikal,String horizontal){
		if(vertikal.equals("bawah")){
			y++;
			if(y==tinggi){
				atas = "atas";
				y--;
				y--;
			}
		}else{
			y--;
			if(y==-1){
				atas = "bawah";
				y++;
				y++;
			}
		}
		
		if(horizontal.equals("kanan")){
			x++;
			if(x==panjang){
				samping="kiri";
				x--;
				x--;
			}
		}else{
			x--;
			if(x==-1){
				samping = " kanan";
				x++;
				x++;
			}
		}
	}
	
}