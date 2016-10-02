package controller;

import java.io.*;
import model.DB;
import model.Sewa;

public class ProsesSewa{
	
	private int jml;
	private String kode_sewa;
	private String no_flat_mobil;
	private String jenis_mobil;
	private String nama_penyewa;
	private String lama_sewa;
	private String[][] daftar = new String[100][5];
	
	private String error;
	
	public ProsesSewa(){
		//konstruktor
		this.jml = 0;
	}
	
	public void show_id(String kode_sewa){
		try{
			Sewa sewa = new Sewa();				
			sewa.getSewaById(kode_sewa);
			
			if(sewa.getResult().next()){				
				this.kode_sewa = sewa.getResult().getString("kode_sewa");
				this.no_flat_mobil = sewa.getResult().getString("no_flat_mobil");
				this.jenis_mobil = sewa.getResult().getString("jenis_mobil");
				this.nama_penyewa = sewa.getResult().getString("nama_penyewa");
				this.lama_sewa = sewa.getResult().getString("lama_sewa");
			}
			
			sewa.closeResult();
			sewa.closeConnection();
		}catch(Exception e){
			
			error = e.toString();
		}
	}
	
	public void show(){
		jml = 0;
		try{
			Sewa sewa = new Sewa();
			sewa.getSewa();
			
			while(sewa.getResult().next()){
				
				String kode = sewa.getResult().getString("kode_sewa");
				String no = sewa.getResult().getString("no_flat_mobil");
				String jenis = sewa.getResult().getString("jenis_mobil");
				String nama = sewa.getResult().getString("nama_penyewa");
				String lama = sewa.getResult().getString("lama_sewa");
				
				daftar[jml][0] = kode;
				daftar[jml][1] = no;
				daftar[jml][2] = jenis;
				daftar[jml][3] = nama;
				daftar[jml][4] = lama;
				
				jml++;
			}
			sewa.closeResult();
			sewa.closeConnection();
		}catch(Exception e){
			
			error = e.toString();
		}
		
	}
	
	public String getKodeSewa(){
		return this.kode_sewa;
	}
	
	public String getNoFlatMobil(){
		return this.no_flat_mobil;
	}
	
	public String getJenisMobil(){
		return this.jenis_mobil;
	}
	
	public String getNamaPenyewa(){
		return this.nama_penyewa;
	}
	
	public String getLamaSewa(){
		return this.lama_sewa;
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
	
	public void tambahSewa(String a,String b,String c,String d,int f){
		
		try{
			
			Sewa sewa = new Sewa();
			sewa.insertSewa(a, b, c, d, f);
			
			sewa.closeResult();
			sewa.closeConnection();
		}catch(Exception e){
			error = e.toString();
		}
		
	}
}