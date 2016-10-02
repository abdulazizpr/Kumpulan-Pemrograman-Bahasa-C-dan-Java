package model;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;
import java.sql.ResultSet;

public class Barang extends DB{
	
	private String kode_barang; //kode anggota
	private String qty_barang;	//qty barang
	private String harga_barang; //kode anggota
	
	public Barang() throws Exception, SQLException{
		//konstruktor
		super();
	}
	
	public void getDaftarBarang(){
		try{
			String query = "SELECT * FROM daftar_barang";
			createQuery(query);
		}catch(Exception e){
			System.out.println(e.toString());
		}
	}
	
	public void insertBarang(String kode, String qty, String harga){
		try{
			String query = "INSERT INTO `daftar_barang`(kode,qty,harga) values('"+kode+"','"+qty+"','"+harga+"')";
			createUpdate(query);
		}catch(Exception e){
			System.out.println(e.toString());
		}
	}
	
}