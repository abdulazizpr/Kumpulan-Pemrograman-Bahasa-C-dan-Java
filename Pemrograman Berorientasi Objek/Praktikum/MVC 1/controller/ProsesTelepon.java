package controller;

import java.io.*;
import model.DB;
import model.Telepon;

public class ProsesTelepon{
	
	private String hasil;
	private String error;
	
	public ProsesTelepon(){
		//konstruktor
	}
	
	public void prosesTelp(){
		
		try{
			Telepon telepon = new Telepon();
			telepon.getTelepon();
			hasil = "***************************\n";
			
			while(telepon.getResult().next()){
				
				String kode_anggota = telepon.getResult().getString(1);
				String no_telepon = telepon.getResult().getString(2);
				
				hasil = hasil + "kode anggota: " + kode_anggota + "\n";
				hasil = hasil + "nomor telepon: " + no_telepon + "\n";
				
			}
			
			telepon.closeResult();
			telepon.closeConnection();
		}catch(Exception e){
			error = e.toString();
		}
		
	}
	
	public String getHasil(){
		return this.hasil;
	}
	
	public String getError(){
		return this.error;
	}
	
}