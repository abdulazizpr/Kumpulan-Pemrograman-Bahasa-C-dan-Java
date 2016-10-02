import java.util.Scanner;
import java.util.*;

class Main{
	
	public static void main(String[] args){
		
		Scanner sc = new Scanner(System.in);
		System.out.print("cls");
		System.out.print("Masukan banyaknya data pengrajin kayu : ");
		
		int nomor=0,n=0,i=0,indeks=0;;
		String nama="",alamat="",namaUsaha="",noKTP="",deskripsi="";
		double omset=0;
		
		n = sc.nextInt();
		
		PengerajinKayu[] PK = new PengerajinKayu[n];
		
		
		for(i=0;i<n;i++){
			indeks = i+1;
			System.out.println("=====================Nomor Usaha : "+ indeks +"===================");
			System.out.print("Nama : ");
			try{
				nama = sc.next();
			}catch(Exception e){
			}
			
			System.out.print("Alamat : ");
			try{
				alamat = sc.next();
			}catch(Exception e){
			}
			
			System.out.print("Nama Usaha : ");
			try{
				namaUsaha = sc.next();
			}catch(Exception e){
			}
			
			System.out.print("Nomor KTP : ");
			try{
				noKTP = sc.next();
			}catch(Exception e){
			}
			
			System.out.print("Omset Per Bulan : ");
			try{
				omset = sc.nextDouble();
			}catch(Exception e){
			}
			
			System.out.print("Deskripsi : ");
			try{
				deskripsi = sc.next();
			}catch(Exception e){
			}
			
			/*instansiasi*/
			PK[i] = new PengerajinKayu();
			
			PK[i].setNoUsaha(indeks);
			PK[i].setNama(nama);
			PK[i].setAlamat(alamat);
			PK[i].setNamaUsaha(namaUsaha);
			PK[i].setNoKTP(noKTP);
			PK[i].setOmsetPerBulan(omset);
			PK[i].setDeskripsi(deskripsi);
			
		}
		
		//menampilkan array balok
		Tabel tab = new Tabel(n,7);
		
		String head[] = new String[7];
		
		
		for(i=0;i<n;i++){
			String[] arrstr = new String[7];
			arrstr[0] = "" + PK[i].getNoUsaha();
			arrstr[1] = "" + PK[i].getNama();
			arrstr[2] = "" + PK[i].getAlamat();
			arrstr[3] = "" + PK[i].getNamaUsaha();
			arrstr[4] = "" + PK[i].getNoKTP();
			arrstr[5] = "" + PK[i].getOmsetPerBulan();
			arrstr[6] = "" + PK[i].getDeskripsi();
			
			tab.buatBaris(arrstr,7);
		}
		
		
	}
	
}