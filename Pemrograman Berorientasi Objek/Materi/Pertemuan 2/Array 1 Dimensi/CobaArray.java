import java.util.Scanner;

public class CobaArray{
	
	public static void main(String args[]){
		int arr[] = new int[5];
		arr[0] = 9;
		
		System.out.println("isi array ke-0 " + arr[0]);
		
		/*
			Kalo bikin string
			String a = "apa ya"
			int b = 9;
		*/
		
		int i = 0; //di java versi baru harus ada inisialisasi
		int e = 0;
		
		Scanner scan = new Scanner(System.in);
		
		for(i=0;i<5;i++){
			arr[i] = scan.nextInt();
			System.out.println("Isis array ke:" + i + "adalah" + arr[i]);
		}
		
	}
	
}