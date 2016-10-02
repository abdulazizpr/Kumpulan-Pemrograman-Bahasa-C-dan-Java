package model;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;
import java.sql.ResultSet;

public class Telepon extends DB{
	
	private String kode_anggota; //kode_anggota
	private String no_telepon;	 //nomor telepon
	
	public Telepon() throws Exception,SQLException{
		//konstruktor
		super();
	}
	
	public void getTelepon(){
		try{
			String query = "SELECT * FROM telepon";
			createQuery(query);
		}catch(Exception e){
			System.out.println(e.toString());
		}
	}
	
}