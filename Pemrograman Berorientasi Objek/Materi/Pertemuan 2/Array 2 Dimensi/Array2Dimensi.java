import java.util.Scanner;

public class Array2Dimensi{
	public static void main(String args[]){
		int arr[][] = new int[2][3];
		int i = 0, j = 0;
		
		Scanner scan = new Scanner(System.in);
		
		for(i=0;i<arr.length;i++){
			for(j=0;j<arr[i].length;j++){
				arr[i][j] = scan.nextInt();
				System.out.println(arr[i][j]);
			}
		}
	}
}