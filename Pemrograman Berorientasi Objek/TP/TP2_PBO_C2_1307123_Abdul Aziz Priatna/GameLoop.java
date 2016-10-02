import javafx.animation.Animation;
import javafx.scene.control.Label;
import javafx.scene.text.Font;
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

/*
Saya Abdul Aziz Priatna tidak melakukan kecurangan seperti yang telah dispesifikasikan 
pada mata kuliah Pemrograman Berorientasi Objek dalam mengerjakan TP2, jika saya melakukan kecurangan 
maka Allah/Tuhan adalah saksi saya, dan saya bersedia menerima hukumanNya. Aamiin.
*/

public class GameLoop extends Application{
	
	private Pesawat pesawat;
	private Meteor meteor;
	private int TIME=0;
	private int skor = 0;
	private int status = 0;
	private boolean isLeftPressed = false;
	private boolean isRightPressed = false;
	private boolean isSpaceBarPressed = false;
	
	@Override
	public void start(Stage stage){
		
		stage.setTitle(Constant.TITLE);
		Group root = new Group();
		Scene scene = new Scene(root,Constant.WIDTH,Constant.HEIGHT,Color.WHITE);
		
		// Label Skor
		Label lskor = new Label("Skor : " + skor);
		lskor.setFont(new Font("Comic Sans MS", 15));
		lskor.setLayoutX(50);
		lskor.setLayoutY(10);
		root.getChildren().add(lskor);
		
		/*membuat objek pesawat*/
		pesawat = new Pesawat();
		pesawat.setImage("assets/pesawat.jpg");//set aset pesawat
		pesawat.setSize(40,60);//set ukuran pesawat
		pesawat.setPosition(Constant.WIDTH/2,Constant.HEIGHT-80);//set posisi awal pesawat
		pesawat.addToGroup(root);
		
		/*instatisasi untuk random*/
		Random rand1 = new Random();
		Random random1 = new Random();
		
		/*membuat objek meteor*/
		meteor = new Meteor();
		meteor.setImage("assets/meteor.jpg");
		meteor.setSize(30,30);//set ukuran meteor
		meteor.setPosition(10 + rand1.nextInt(750),(random1.nextInt(5)));//set posisi secara random
		meteor.setVelocity(3);//atur percepatan meteor
		meteor.addToGroup(root);
		
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
						pesawat.shoot(root,status);
						status++;
						if(status==3){
							status = 0;
						}
					}
					
				}
				
				checkCollision(root); //mengecek collision
				lskor.setText("Skor : " + skor); //set untuk nilai skor
				pesawat.updatePeluru(root);	//update peluru
				TIME++;
				
			}
		}); 
		
		/*Timeline Animasi*/
		Timeline t1 = new Timeline();
		t1.setCycleCount(Animation.INDEFINITE);
		t1.getKeyFrames().add(oneFrame);
		t1.play();
		
		/*akses tombol keyboard jika di tekan lama*/
		scene.setOnKeyPressed(new EventHandler<KeyEvent>(){
			@Override 
			public void handle(KeyEvent Key) {
				if(Key.getCode()==KeyCode.LEFT) isLeftPressed = true;
				if(Key.getCode()==KeyCode.RIGHT) isRightPressed = true;
				if(Key.getCode() == KeyCode.SPACE ) isSpaceBarPressed = true;
			}
		});
		
		/*akses tombol keyboard jika di tekan sekali*/
		scene.setOnKeyReleased(new EventHandler<KeyEvent>(){
			@Override 
			public void handle(KeyEvent Key) {
				if(Key.getCode()==KeyCode.LEFT) isLeftPressed = false;
				if(Key.getCode()==KeyCode.RIGHT) isRightPressed = false;
				if(Key.getCode()==KeyCode.SPACE) isSpaceBarPressed = false;
			}
		});
		
	
		stage.setScene(scene);
		stage.show();
		
	}
	
	//method untuk mengecek collision
	private void checkCollision(Group root){
		Random rand1 = new Random();
		Random random1 = new Random();
	
		for(Peluru peluru : pesawat.get()){
			//jika peluru mengenai meteor
			if(peluru.getBoundsInParent().intersects(meteor.getMeteor().getBoundsInParent())){
				//posisi meteor di set awal secara random
				meteor.setPosition(10 + rand1.nextInt(750),(random1.nextInt(5)));
				skor = skor + 10;	//menambahkan skor
				pesawat.removePeluru(root);//hapus peluru
			}
		}
		
	}
	
	public static void main(String[] args) {
		launch(args);
	}

}	