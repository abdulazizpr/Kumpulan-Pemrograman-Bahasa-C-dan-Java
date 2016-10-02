package controller;

import java.io.*;
import model.DB;
import model.Skor;

public class ProsesSkor{
	
	private int jml;
	private int id;
	private String user;
	private String pass;
	private int jml_skor;
	private String[][] daftar = new String[100][5];
	
	public String error;
	
	public ProsesSkor(){		
	}
	
	//method untuk masukan data skor berdasarkan username dan password
	public void tampilSkor(String username, String password){
		try{
			Skor skor = new Skor();
			skor.getSkor(username,password);
			
			if(skor.getResult().next()){
				this.id = Integer.parseInt(skor.getResult().getString("id"));
				this.user = skor.getResult().getString("username");
				this.pass = skor.getResult().getString("password");
				this.jml_skor = Integer.parseInt(skor.getResult().getString("skor"));
				
			}
			skor.closeResult();
			skor.closeConnection();
		}catch(Exception e){
			error = e.toString();
		}
	}
	
	//method untuk mengambil id
	public int getId(){
		return this.id;
	}
	
	//method untuk mengambil username
	public String getUsername(){
		return this.user;
	}
	
	//method untuk mengambil password
	public String getPassword(){
		return this.pass;
	}
	
	//method untuk mengambil skor
	public int getSkor(){
		return this.jml_skor;
	}
	
	public String getError(){
		return this.error;
	}
	
	//method controller untuk memperbarui skor
	public void perbaruiSkor(int id,int jml_skor){
		try{
			
			Skor skor = new Skor();
			skor.updateSkor(id,jml_skor);
			
			skor.closeResult();
			skor.closeConnection();
		}catch(Exception e){
			error = e.toString();
		}
	}
	
}	