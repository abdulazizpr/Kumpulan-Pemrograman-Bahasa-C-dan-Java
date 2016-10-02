package view;

import javafx.animation.Animation;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.ToggleGroup;
import javafx.scene.control.TextField;
import javafx.scene.control.PasswordField;	//untuk password
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;
import javafx.scene.text.Text;
import javafx.animation.KeyFrame;
import javafx.animation.Timeline;
import javafx.animation.FillTransition;
import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.Event;
import javafx.event.EventHandler;
import javafx.scene.Cursor;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.input.KeyEvent; 
import javafx.scene.input.KeyCode;
import javafx.scene.paint.Color;
import javafx.stage.Stage;
import javafx.util.Duration;
import entity.Pesawat;
import entity.Meteor;
import entity.Peluru;
import global.Constant;
import java.util.Random;
import javafx.geometry.Insets;
import javafx.geometry.Bounds;
import javafx.scene.Node;
import javax.swing.*;
import java.awt.event.*;
import javafx.scene.Node;
import javafx.scene.shape.Circle;
import javafx.scene.shape.Rectangle;
import javafx.scene.shape.*;

import controller.ProsesSkor;

/*
Saya Abdul Aziz Priatna tidak melakukan kecurangan seperti yang telah dispesifikasikan 
pada mata kuliah Pemrograman Berorientasi Objek dalam mengerjakan TP2, jika saya melakukan kecurangan 
maka Allah/Tuhan adalah saksi saya, dan saya bersedia menerima hukumanNya. Aamiin.
*/

public class GameLoop{
	
	private Pesawat pesawat;
	private Meteor meteor;
	private ProsesSkor skor = new ProsesSkor();
	private int TIME=0;
	private int status = 0;
	private int stop = 0;
	private boolean isLeftPressed = false;
	private boolean isRightPressed = false;
	private boolean isSpaceBarPressed = false;
	private int id;
	private String username;
	private String password;
	private int jml_skor;
	
	public GameLoop(){
	}
	
	public void tampil(Stage stage){
		
		stage.setTitle(Constant.TITLE);
		Group root = new Group();
		Scene scene1 = new Scene(root,Constant.WIDTH,Constant.HEIGHT,Color.WHITE);
		
		Text scenetitle = new Text("Welcome");//scene title
		scenetitle.setFont(Font.font("Tahoma",FontWeight.BOLD, 50));
		scenetitle.setLayoutX(300);//posisi X
		scenetitle.setLayoutY(180);//posisi Y
		root.getChildren().add(scenetitle);
		
		Label message = new Label();
		
		Label lUsername = new Label("Username");//label username
		lUsername.setFont(Font.font("Tahoma",FontWeight.NORMAL, 20));//posisi X
		lUsername.setLayoutX(200);//posisi X
		lUsername.setLayoutY(260);//posisi Y
		root.getChildren().add(lUsername);
		
		TextField tUsername = new TextField();//Textfield username
		tUsername.setLayoutX(300);//posisi X
		tUsername.setLayoutY(260);//posisi Y
		tUsername.setPrefColumnCount(21);
		root.getChildren().add(tUsername);
		
		Label lPassowrd = new Label("Password");//label Password
		lPassowrd.setFont(Font.font("Tahoma",FontWeight.NORMAL, 20));//posisi X
		lPassowrd.setLayoutX(200);//posisi X
		lPassowrd.setLayoutY(330);//posisi Y
		root.getChildren().add(lPassowrd);
		
		PasswordField tPassword = new PasswordField();//PasswordField Password
		tPassword.setLayoutX(300);//posisi X
		tPassword.setLayoutY(330);//posisi Y
		tPassword.setPrefColumnCount(21);
		root.getChildren().add(tPassword);
		
		/*tombol login*/
		Button bLogin = new Button("Login");//tombol login
		bLogin.setLayoutX(500);//posisi X
		bLogin.setLayoutY(380);//posisi Y
		root.getChildren().add(bLogin);
		
		Group root2 = new Group();
		Scene scene2 = new Scene(root2,Constant.WIDTH,Constant.HEIGHT,Color.WHITE);
		
		/*instatisasi untuk random*/
		Random rand1 = new Random();
		Random random1 = new Random();
		
		// Label jml_skor
		Label lskor = new Label("Skor : " + jml_skor);
		lskor.setFont(new Font("Comic Sans MS", 15));
		lskor.setLayoutX(700);
		lskor.setLayoutY(10);
		root2.getChildren().add(lskor);
		
		/*membuat objek pesawat*/
		pesawat = new Pesawat();
		pesawat.setImage("assets/pesawat.jpg");//set aset pesawat
		pesawat.setSize(40,60);//set ukuran pesawat
		pesawat.setPosition(Constant.WIDTH/2,Constant.HEIGHT-80);//set posisi awal pesawat
		pesawat.addToGroup(root2);
		
		/*membuat objek meteor*/
		meteor = new Meteor();
		meteor.setImage("assets/meteor.jpg");
		meteor.setSize(50,50);//set ukuran meteor
		meteor.setPosition(10 + rand1.nextInt(750),(random1.nextInt(5)));//set posisi secara random
		meteor.setVelocity(3);//atur percepatan meteor
		meteor.addToGroup(root2);
		
		Group root3 = new Group();
		Scene scene3 = new Scene(root3,Constant.WIDTH,Constant.HEIGHT,Color.WHITE);
		
		Text tScene3 = new Text("Skor "+username+" menjadi "+jml_skor);//scene title
		tScene3.setFont(Font.font("Tahoma",FontWeight.BOLD, 10));
		tScene3.setLayoutX(300);//posisi X
		tScene3.setLayoutY(180);//posisi Y
		root3.getChildren().add(tScene3);
		
		//Animasi Meteor
		Duration fps = Duration.millis(1000/60);
		KeyFrame oneFrame = new KeyFrame(fps,new EventHandler<ActionEvent>(){
			@Override
			public void handle(ActionEvent event){
				
				meteor.setPosition(meteor.getX(),meteor.getY() + meteor.getVelocity());
				
				//jika meteor melebihi batas
				if(meteor.getY() > Constant.HEIGHT - 80){
					//set meteor di posisi awal secara random
					meteor.setPosition(10 +rand1.nextInt(750),(random1.nextInt(5)));
				}
				
				//jika press tombol kiri
				if(isLeftPressed == true){
					pesawat.setPosition(pesawat.getX()-10,pesawat.getY());
					
					//batas kiri agar tidak menabrak
					if(pesawat.getX()==10){
						pesawat.setPosition(pesawat.getX()+10,pesawat.getY()); 
					}
				}
				
				//jika press tombol kanan
				if(isRightPressed == true){
					pesawat.setPosition(pesawat.getX()+10,pesawat.getY());
					
					//batas kanan agar tidak menabrak
					if(pesawat.getX()==750){
						pesawat.setPosition(pesawat.getX()-10,pesawat.getY());
					}
				}
				
				//jika press tombol spasi
				if(isSpaceBarPressed == true){
					if(TIME%10==0){
						pesawat.shoot(root2,status);
						status++;
						if(status==3){
							status = 0;
						}
					}
					
				}
				
				checkCollision(root2); //mengecek collision	
				lskor.setText("skor : " + jml_skor); //set untuk nilai jml_skor
				
				//jika pesawat bertabrakan dengan meteor
				if(pesawat.getBounds().getBoundsInParent().intersects(meteor.getBounds().getBoundsInParent())){
					tScene3.setText("Skor "+ username +" menjadi "+jml_skor);//skor ditampilkan di scene3
					skor.perbaruiSkor(id,jml_skor);//lalu update di database
					stage.setScene(scene3);					
				}
				pesawat.updatePeluru(root2);	//update peluru
				TIME++;
				
			}
		}); 
		
		/*Timeline Animasi*/
		Timeline t1 = new Timeline();
		t1.setCycleCount(Animation.INDEFINITE);
		t1.getKeyFrames().add(oneFrame);
		
		/*akses tombol keyboard jika di tekan lama*/
		scene2.setOnKeyPressed(new EventHandler<KeyEvent>(){
			@Override 
			public void handle(KeyEvent Key) {
				if(Key.getCode()==KeyCode.LEFT) isLeftPressed = true;
				if(Key.getCode()==KeyCode.RIGHT) isRightPressed = true;
				if(Key.getCode() == KeyCode.SPACE ) isSpaceBarPressed = true;
			}
		});
		
		/*akses tombol keyboard jika di tekan sekali*/
		scene2.setOnKeyReleased(new EventHandler<KeyEvent>(){
			@Override 
			public void handle(KeyEvent Key) {
				if(Key.getCode()==KeyCode.LEFT) isLeftPressed = false;
				if(Key.getCode()==KeyCode.RIGHT) isRightPressed = false;
				if(Key.getCode()==KeyCode.SPACE) isSpaceBarPressed = false;
			}
		});
		
		//akses tombol login
		bLogin.setOnAction(new EventHandler<ActionEvent>(){
			@Override
			public void handle(ActionEvent e){
				
				//mengambil data dari database
				try{
					skor.tampilSkor(tUsername.getText(),tPassword.getText());
				}catch(Exception r){
					System.out.println(skor.getError());
				}
				
				//masukan ke setiap atribut
				id = skor.getId();
				username = skor.getUsername();
				password = skor.getPassword();
				jml_skor = skor.getSkor();
				
				//mencocokan username dan password di database
				if(tUsername.getText().equals(username) && tPassword.getText().equals(password)){
					stage.setScene(scene2);//masuk ke scene2
					t1.play();//animasi di play
				}else{
					//kosongkan texfield username dan password
					tUsername.setText("");
					tPassword.setText("");
				}
			}
		});
		
		stage.setScene(scene1);
		stage.show();
		
	}
	
	//method untuk mengecek collision
	private void checkCollision(Group root){
		Random rand1 = new Random();
		Random random1 = new Random();
	
		for(Peluru peluru : pesawat.get()){
			//jika peluru mengenai meteor
			if(peluru.getBoundsInParent().intersects(meteor.getBounds().getBoundsInParent())){
				//posisi meteor di set awal secara random
				meteor.setPosition(10 + rand1.nextInt(750),(random1.nextInt(5)));
				jml_skor = jml_skor + 10;	//menambahkan jml_skor
				pesawat.removePeluru(root);//hapus peluru
			}
			
		}
		
		
		
	}

}	