package controller;

import java.io.*;
import model.DB;
import model.Barang;

public class ProsesBarang{
	
	private int jml;
	private String kode;
	private String qty;
	private String harga;
	private String[][] daftar = new String[25][5];
	
	private String error;
	
	public ProsesBarang(){
		//konstruktor
		this.jml = 0;
	}
	
	public void prosesBrg(){
		jml = 0;
		try{
			Barang brg = new Barang();
			brg.getDaftarBarang();
			
			while(brg.getResult().next()){
				
				String kode = brg.getResult().getString(1);
				String qty = brg.getResult().getString(2);
				String harga = brg.getResult().getString(3);
				
				daftar[jml][0] = kode;
				daftar[jml][1] = qty;
				daftar[jml][2] = harga;
				
				jml++;
			}
			brg.closeResult();
			brg.closeConnection();
		}catch(Exception e){
			
			error = e.toString();
		}
		
	}
	
	public int getJml(){
		return this.jml;
	}
	
	public String[][] getHasil(){
		return this.daftar;
	}
	
	public String getError(){
		return this.error;
	}
	
	public void tambahBarang(String a,String b,String c){
		
		try{
			
			Barang brg = new Barang();
			brg.insertBarang(a, b, c);
			
			brg.closeResult();
			brg.closeConnection();
		}catch(Exception e){
			error = e.toString();
		}
		
	}
}