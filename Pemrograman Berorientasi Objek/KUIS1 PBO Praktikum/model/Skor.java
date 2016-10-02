package model;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;
import java.sql.ResultSet;

public class Skor extends DB{
	
	private int id;
	private String username;
	private String password;
	private int skor;
	
	public Skor() throws Exception, SQLException{
		//konstruktor
		super();
	}
	
	//method untuk mengambil data berdasarkan username dan password 
	public void getSkor(String username,String password){
		try{
			String query = "SELECT * FROM skor where username='"+username+"' and password='"+password+"'";
			createQuery(query);
		}catch(Exception e){
			System.out.println(e.toString());
		}
	}
	
	//method untuk mengupdate skor terbaru
	public void updateSkor(int id,int skor){
		try{
			String query = "UPDATE skor SET skor='"+skor+"' where id='"+id+"'";
			createUpdate(query);
		}catch(Exception e){
			System.out.println(e.toString());
		}
	}
	
}