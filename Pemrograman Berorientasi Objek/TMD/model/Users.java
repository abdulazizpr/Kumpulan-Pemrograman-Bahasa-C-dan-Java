package model;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;
import java.sql.ResultSet;

public class Users extends DB{
	
	private int id;
	private String username;
	private int energy;
	
	public Users() throws Exception, SQLException{
		//konstruktor
		super();
	}
	
	//method untuk mengambil semua data 
	public void getUsers(){
		try{
			String query = "SELECT * FROM user ORDER BY energy DESC";
			createQuery(query);
		}catch(Exception e){
			System.out.println(e.toString());
		}
	}
	
	//method untuk mengambil data berdasarkan username
	public void getUserByUsername(String username){
		try{
			String query = "SELECT * FROM user where username='"+username+"'";
			createQuery(query);
		}catch(Exception e){
			System.out.println(e.toString());
		}
	}
	
	//method untuk insert data username
	public void insertUser(String username){
		try{
			String query = "INSERT INTO user (username) VALUES('"+username+"')";
			createUpdate(query);
		}catch(Exception e){
			System.out.println(e.toString());
		}
	}
	
	//method untuk mengupdate energy terbaru
	public void updateUser(int id,int energy){
		try{
			String query = "UPDATE user SET energy='"+energy+"' where id='"+id+"'";
			createUpdate(query);
		}catch(Exception e){
			System.out.println(e.toString());
		}
	}
	
}