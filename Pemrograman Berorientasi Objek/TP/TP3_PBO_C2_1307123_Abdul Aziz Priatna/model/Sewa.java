package model;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;
import java.sql.ResultSet;

public class Sewa extends DB{
	
	private String kode_sewa;
	private String no_flat_mobil;
	private String jenis_mobil;
	private String nama_penyewa;
	private int lama_sewa;
	
	public Sewa() throws Exception, SQLException{
		//konstruktor
		super();
	}
	
	public void getSewa(){
		try{
			String query = "SELECT * FROM sewa";
			createQuery(query);
		}catch(Exception e){
			System.out.println(e.toString());
		}
	}
	
	public void getSewaById(String kode_sewa){
		try{
			String query = "SELECT * FROM sewa WHERE kode_sewa='"+kode_sewa+"'";
			createQuery(query);
		}catch(Exception e){
			System.out.println(e.toString());
		}
	}
	
	public void insertSewa(String kode, String no, String jenis,String nama,int lama){
		try{
			String query = "INSERT INTO `sewa`(kode_sewa,no_flat_mobil,jenis_mobil,nama_penyewa,lama_sewa) values('"+kode+"','"+no+"','"+jenis+"','"+nama+"','"+lama+"')";
			createUpdate(query);
		}catch(Exception e){
			System.out.println(e.toString());
		}
	}
	
	public void updateSewa(String kode, String no, String jenis,String nama,int lama){
		try{
			String query = "UPDATE sewa SET no_flat_mobil='"+no+"' jenis_mobil='"+jenis+"' nama_penyewa='"+nama+"' lama_sewa='"+lama+"' where kode_sewa='"+kode+"'";
			createUpdate(query);
		}catch(Exception e){
			System.out.println(e.toString());
		}
	}
	
	public void deleteSewa(String kode){
		try{
			String query = "DELETE FROM SEWA where kode_sewa='"+kode+"'";
			createUpdate(query);
		}catch(Exception e){
			System.out.println(e.toString());
		}
	}
	
}