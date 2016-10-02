import java.util.Scanner;

public class Main{
	
	public static void main(String[] args){
		
		int n = 0; //banyaknya balok
		
		System.out.println("Masukan banyak balok:");
		
		Scanner sc = new Scanner(System.in);
		
		try{
			n = sc.nextInt();
		}catch(Exception e){
		}
		
		//array balok
		Balok[] arrbalok = new Balok[n];
		
		//mengisi array balok
		int i = 0, p = 0, l = 0, t = 0;
		
		for(i=0;i<n;i++){
			System.out.println("Masukan panjang, lebar ting balok ke "+ (i+1) + " : ");
			try{
				p = sc.nextInt();
			}catch(Exception e){
			}
			
			try{
				l = sc.nextInt();
			}catch(Exception e){
			}
			
			try{
				t = sc.nextInt();
			}catch(Exception e){
			}
			
			arrbalok[i] = new Balok(p,l,t);
		}
		
		//menampilkan array balok
		Tabel tab = new Tabel(n,5);
		
		for(i=0;i<n;i++){
			String[] arrstr = new String[5];
			arrstr[0] = "" + arrbalok[i].getPanjang();
			arrstr[1] = "" + arrbalok[i].getLebar();
			arrstr[2] = "" + arrbalok[i].getTinggi();
			arrstr[3] = "" + arrbalok[i].volume();
			arrstr[4] = "" + arrbalok[i].luas();
			tab.buatBaris(arrstr,5);
		}

	}
	
}