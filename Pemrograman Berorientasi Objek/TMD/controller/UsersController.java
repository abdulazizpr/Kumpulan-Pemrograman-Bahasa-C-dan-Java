package controller;

import java.io.*;
import model.DB;
import model.Users;
import java.util.List ;
import java.util.ArrayList ;
import javafx.beans.property.StringProperty;
import javafx.beans.property.SimpleStringProperty;
import javafx.collections.ObservableList;
import javafx.collections.FXCollections;


public class UsersController{
	
	//inner class untuk menampung data user ke tabel
	public class DataUsers{
		
		//username
		private final StringProperty username = new SimpleStringProperty(this,"username");
		
			//get property username
			public StringProperty usernameProperty() {
				return username ;
			}
			
			//get username
			public final String getUsername(){
				return usernameProperty().get();
			}
			
			//set username
			public final void setUsername(String username){
				usernameProperty().set(username);
			}
		
		//energy
		private final StringProperty energy = new SimpleStringProperty(this,"energy");
		
		//get property energy
		public StringProperty energyProperty() {
			return energy;
		}
		
		//get energy
		public final String getEnergy(){
			return energyProperty().get();
		}
		
		//set energy
		public final void setEnegy(String energy){
			energyProperty().set(energy);
		}
		
		//konstruktor kosong
		public DataUsers(){
		}
		
		//konstruktor berisi
		public DataUsers(String username,String energy){
			usernameProperty().set(username);
			energyProperty().set(energy);
		}
		
	}
	
	private int id;
	private String username;
	private int energy;
	private final ObservableList<DataUsers> du = FXCollections.observableArrayList(); //ambil list
	
	public String error;
	
	//konstruktor kosong
	public UsersController(){
	}
	
	//method mengambil semua data user dari database dan di tampung ke list
	public ObservableList<DataUsers> getDataUsersList(){
			
		try{
			Users users = new Users();
			users.getUsers();
			
			while(users.getResult().next()){
				String username = users.getResult().getString("username");
				String energy = users.getResult().getString("energy");
				
				DataUsers data = new DataUsers(username,energy);
				du.add(data);
			}
			users.closeResult();
			users.closeConnection();
		}catch(Exception e){
			error = e.toString();
		}
		
		return du;
	}
	
	//untuk menghapus list
	public void remove(){
		du.clear();
	}
	
	/*method untuk mengambil data user berdasarkan username*/
	public void getUser(String username){
		
		try{
			Users users = new Users();
			users.getUserByUsername(username);
			
			if(users.getResult().next()){
				this.id = Integer.parseInt(users.getResult().getString("id"));
				this.username = users.getResult().getString("username");
				this.energy = Integer.parseInt(users.getResult().getString("energy"));
			}
			users.closeResult();
			users.closeConnection();
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
		return this.username;
	}
	
	//method untuk mengambil energy
	public int getEnergy(){
		return this.energy;
	}
	
	public String getError(){
		return this.error;
	}
	
	//method controller untuk memasukan username
	public void insert(String username){
		try{
			
			Users user = new Users();
			user.insertUser(username);
			
			user.closeResult();
			user.closeConnection();
		}catch(Exception e){
			error = e.toString();
		}
	}
	
	//method controller untuk memperbarui energy
	public void update(int id,int energy){
		try{
			
			Users user = new Users();
			user.updateUser(id,energy);
			
			user.closeResult();
			user.closeConnection();
		}catch(Exception e){
			error = e.toString();
		}
	}
	
}