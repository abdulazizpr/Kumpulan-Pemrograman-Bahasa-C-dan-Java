package view;

import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.animation.AnimationTimer;
import javafx.event.EventHandler;
import javafx.event.ActionEvent;
import javafx.stage.StageStyle;
import javafx.event.Event;
import javafx.scene.Node;
import javafx.scene.paint.Color;
import javafx.geometry.Insets;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.ToggleGroup;
import javafx.scene.paint.Color;
import javafx.scene.text.FontWeight;
import javafx.scene.text.Text;
import javafx.scene.text.Font;
import javafx.scene.control.*;	//untuk combobox
import javafx.scene.input.KeyEvent; 
import javafx.scene.input.KeyCode;
import javafx.scene.control.Alert.AlertType;
import javafx.scene.control.*;
import javafx.scene.control.Dialog;
import javafx.scene.canvas.*;
import javafx.stage.Stage;
import java.util.ArrayList;
import java.util.Random;
import java.util.Iterator;
import java.io.*;

import view.Audio;


import controller.UsersController;
import controller.ProsesInput;
import controller.ProsesPergerakan;

public class AnimationGame extends Home{
	
	
	public AnimationGame(){
	}
	
	private UsersController users = new UsersController();
	private Home home = new Home(); 
	private boolean isUpPressed = false;
	private boolean isDownPressed = false;
	private boolean isLeftPressed = false;
	private boolean isRightPressed = false;
	private boolean isSpaceBarPressed = false;
	private int TIME;
	private int color=1;
	private int energy = 0;
	private int status = 0;
	private long longTime = System.nanoTime(); //
	
	public void run(Stage stage,Group root,int id,String username,int e,Audio klik){
	
		Scene scene = new Scene(root,500,400,Color.CYAN);
		
		//buat canvas
		final Canvas canvas = new Canvas(500,400);
		GraphicsContext gc = canvas.getGraphicsContext2D();
		
		//intansiasi petualang
		Petualang petualang = new Petualang();
		petualang.setPosition((canvas.getWidth()/2)+9,300);//set posisi awal petualang
		
		// Label jml_skor
		Label lskor = new Label();
		lskor.setFont(new Font("Comic Sans MS", 20));
		lskor.setLayoutX(350);
		lskor.setLayoutY(362);
		
		/*method random digunakan untuk mengacak tampilnya tantangan*/
		Random rand1 = new Random();
		Random rand2 = new Random();
		
		/*instansiasi prosesinput dan pergerakan*/
		ProsesInput PI = new ProsesInput();
		ProsesPergerakan pg = new ProsesPergerakan();
		
		root.getChildren().addAll(canvas,lskor);
		
		/*tampilan scene3 jika petualang menabrak tantangan(GAME OVER)*/
		Group root3 = new Group();
		Scene scene3 = new Scene(root3,500,400,Color.CYAN);
		
		Text go = new Text("GAME OVER");
		go.setFont(Font.font("Tahoma",FontWeight.BOLD, 20));
		go.setLayoutX(180);//posisi X
		go.setLayoutY(176);//posisi Y
		go.setFill(Color.RED);
		
		Text tScene3 = new Text();//scene title
		tScene3.setFont(Font.font("Tahoma",FontWeight.BOLD, 20));
		tScene3.setLayoutX(120);//posisi X
		tScene3.setLayoutY(200);//posisi Y
		
		final Button menuButton = new Button("Kembali ke menu");	//button untuk main game
		menuButton.setLayoutX(80);
		menuButton.setLayoutY(250);
		menuButton.setStyle("-fx-font: 22 arial; -fx-base: #64FE2E;");
		
		final Button exitButton = new Button("Keluar"); //button untuk exit
		exitButton.setLayoutX(300);
		exitButton.setLayoutY(250);
		exitButton.setStyle("-fx-font: 22 arial; -fx-base: #FF0000;");
		
		root3.getChildren().addAll(go,tScene3,menuButton,exitButton);
		
		//untuk menampung tantangan
		ArrayList<Tantangan> arrTantangan = new ArrayList<Tantangan>();
		
		TIME = 0;
		energy = e;
		AnimationTimer run = new AnimationTimer(){
            public void handle(long currentTime){
					
					//update estimasi waktu
					double estimateTime = (currentTime - longTime) / 1000000000.0;
					longTime = currentTime;
					
					//jika waktu lebih 50
					if(TIME > 50){
						//maka buat tantangan
						Tantangan tantangan = new Tantangan();
						tantangan.setSize(20,20);//atur ukuran size
						tantangan.setColor(color);//atur warna
						tantangan.setPosition(10 + rand1.nextInt(480),rand2.nextInt(1));//set posisi secara random
						tantangan.setVelocity(0,50);//atur kecepatan
						arrTantangan.add(tantangan);//masukan tantangan ke dalam arraylist
						
						color++;//iterasi untuk pergantian warna
						if(color>4){//jika warna suda ke 4
							color = 1;//atur ke 1 lagi
						}
						
						//waktu di set 0
						TIME = 0;
					}	
					
					//set kecepatan petualang 0 untuk awal
					petualang.setVelocity(0,0);
					
					//proses pergerakan petualang menggunakan keyboard
					pg.movepetualang(petualang,isUpPressed,isDownPressed,isLeftPressed,isRightPressed);					
					//update pergerakan petualang
					petualang.update(estimateTime*2);
					
					//jika menekan spasi
					if(isSpaceBarPressed==true){
						/*berhenti kemudian update energy terakhir dan masuk ke scene awal*/
						stop();
						users.update(id,energy);
						refresh();
						home.show(stage);
					}
					
					//untuk mengecek collision setiap tantangan
					Iterator<Tantangan> it = arrTantangan.iterator();
					while(it.hasNext()){
						Tantangan ttg = it.next();
						
						//jika petualang melewati tantangan
						if(petualang.getY()<=ttg.getY() && ttg.getStatus()==0){
							energy+=10;	//energy bertambah 10
							//tandai status jika sudah terlewat
							ttg.setStatus(1);
						}						
						
						//jika petualang menabrak tantangan
						if(petualang.getBoundary().intersects(ttg.getBoundary())){
							/*maka game berakhir*/
							stop();
							users.update(id,energy);
							tScene3.setText("Energi "+username+" menjadi "+energy);
							stage.setScene(scene3);
						}
						
						//jika tantangan melewati batas
						if(ttg.getY() > 362){
							it.remove();//hapus
						}
						
					}
					
					
					TIME++;//iterasi waktu pergantian tantangan
					
					//clear canvas
					gc.clearRect(0, 0, canvas.getWidth(),canvas.getHeight());
					
					//gambar setiap tantangan ke dalam list
					for (Tantangan ttg : arrTantangan) {
						ttg.update(estimateTime);//update kemunculan tantangan
						ttg.draw(gc);						
					}
					
					//gambar petualang
					petualang.draw(gc);
					
					//tampilan untuk melihat energi terakhir
					lskor.setText("Energi : " + energy);
				}
			};
			run.start();
		
		//tombol keyboard di tekan
		scene.setOnKeyPressed(new EventHandler<KeyEvent>(){
			@Override 
			public void handle(KeyEvent Key) {
				PI.press(Key);
				isUpPressed = PI.getUp();
				isDownPressed = PI.getDown();
				isLeftPressed = PI.getLeft();
				isRightPressed = PI.getRight();
				isSpaceBarPressed = PI.getSpace();
			}
		});
		
		//jika tombol keyboard di lepas
		scene.setOnKeyReleased(new EventHandler<KeyEvent>(){
			@Override 
			public void handle(KeyEvent Key) {
				PI.release(Key);
				isUpPressed = PI.getUp();
				isDownPressed = PI.getDown();
				isLeftPressed = PI.getLeft();
				isRightPressed = PI.getRight();
				isSpaceBarPressed = PI.getSpace();
			}
		});
		
		/*jika menekan tombol exit*/
		menuButton.setOnAction(new EventHandler<ActionEvent>(){
			@Override
			public void handle(ActionEvent e){
				klik.setFile("assets/success.wav");
				klik.soundPlayOnce();
				refresh();
				home.show(stage);
			}
		});
		
		/*jika menekan tombol exit*/
		exitButton.setOnAction(new EventHandler<ActionEvent>(){
			@Override
			public void handle(ActionEvent e){
				klik.setFile("assets/success.wav");
				klik.soundPlayOnce();
				System.exit(0);
			}
		});	
		
		stage.setScene(scene);
	}
	
	
}