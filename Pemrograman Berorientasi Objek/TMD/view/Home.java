package view;

import javafx.application.Application;
import javafx.collections.ObservableList;
import javafx.collections.FXCollections;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.event.ActionEvent;
import javafx.event.Event;
import javafx.geometry.Insets;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.control.TextField;
import javafx.scene.control.TableCell;
import javafx.scene.control.ToggleGroup;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.scene.text.FontWeight;
import javafx.scene.text.Text;
import javafx.scene.text.Font;
import javafx.scene.control.*;	//untuk combobox
import javafx.scene.input.KeyEvent; 
import javafx.scene.input.KeyCode;
import javafx.scene.control.Alert.AlertType;
import javafx.scene.canvas.*;
import javafx.scene.control.*;
import javafx.scene.control.Dialog;
import javafx.scene.Node;
import javafx.scene.control.TabPane.*;
import javafx.stage.Stage;
import javafx.stage.StageStyle;
import java.io.*;
import java.util.ArrayList;


import controller.UsersController;
import controller.ProsesInput;
import controller.ProsesPergerakan;

import view.Petualang;
import view.Tantangan;
import view.AnimationGame;
import view.Audio;

public class Home{
	
	private UsersController users = new UsersController();
	private HBox hbox1 = new HBox();
	private HBox hbox2 = new HBox();
	private int id;
	private String username;
	private int energy;
	
	private	TableView<UsersController.DataUsers> usersTable = new TableView();
	
	public Home(){
	}

	
	public void show(Stage stage){
		
		stage.setTitle("TUGAS MASA DEPAN");
		Group root1 = new Group();
		Scene scene1 = new Scene(root1,500,400,Color.CYAN);
		
		//backsound
		Audio klik = new Audio();
		
		/*header text*/
		Text header = new Text("FIGHT THE CHALLENGES");
		header.setFont(Font.font("Tahoma",FontWeight.BOLD, 20));
		header.setLayoutX(400);//posisi X
		header.setLayoutY(180);//posisi Y
		
		/*tabel*/
		usersTable.setPrefSize( 300, 200 ); //ukuran tabel
		usersTable.setColumnResizePolicy(TableView.CONSTRAINED_RESIZE_POLICY);//mengukur setiap kolom agar pas dengan ukuran tabel
		
		
		TableColumn<UsersController.DataUsers, String> usernameCol = new TableColumn<>("Username");
		usernameCol.setMaxWidth(500);
		usernameCol.setCellValueFactory(new PropertyValueFactory<>("username"));
		
		TableColumn<UsersController.DataUsers, String> energyCol = new TableColumn<>("Energy");
		energyCol.setMaxWidth(200);
		energyCol.setCellValueFactory(new PropertyValueFactory<>("energy"));
		
		usersTable.getColumns().addAll(usernameCol,energyCol);
		
		/*item diisi dari database*/
		usersTable.setItems(users.getDataUsersList());
		
		/*urutan tampilan menggunakan vbox*/
		final VBox vbox = new VBox();
		vbox.setSpacing(10);
		vbox.setLayoutX(90);
		vbox.setPadding(new Insets(20,0,0,20));
		vbox.getChildren().addAll(header,usersTable,hbox1,hbox2);
		
		//---------Texfield untuk mengisi username
		final Label lUsername = new Label("Username");//label username
		lUsername.setFont(Font.font("Tahoma",FontWeight.NORMAL, 13));
		
		/*Textfield username*/
		final TextField addUsename = new TextField();
		addUsename.setPromptText("Username");
		addUsename.setMaxWidth(100);
		addUsename.setPrefColumnCount(40);
		
		final Button mainButton = new Button("Main");	//button untuk main game
		mainButton.setStyle("-fx-font: 22 arial; -fx-base: #64FE2E;");
		final Button exitButton = new Button("Keluar"); 
		//button untuk exit
		exitButton.setStyle("-fx-font: 22 arial; -fx-base: #FF0000;");
		
		/*mengatur tata letak tombol di hbox*/	
		hbox1.setSpacing(10);
		hbox1.getChildren().addAll(lUsername,addUsename);
		
		hbox2.setSpacing(10);
		hbox2.getChildren().addAll(mainButton,exitButton);
		
		root1.getChildren().addAll(vbox);
		
		//root untuk scene 2
		Group root2 = new Group();
		AnimationGame anim = new AnimationGame();
		
		mainButton.setOnAction(new EventHandler<ActionEvent>(){
			@Override
			public void handle(ActionEvent e){				
				
				if(addUsename.getText().trim().isEmpty()){
					//tampilkan pop up dengan suara
					klik.setFile("assets/klik.wav");
					klik.soundPlayOnce();
					Alert alert = new Alert(AlertType.ERROR);
					alert.setTitle("Error !");
					alert.setHeaderText(null);
					alert.setContentText("Harap isi username !");

					alert.showAndWait();
				}else{
					//musik jika menekan tombol main jika tidak kosong
					klik.setFile("assets/success.wav");
					klik.soundPlayOnce();
					
					//mengecek adanya username
					users.getUser(addUsename.getText());
					id = users.getId();
					username =  users.getUsername();
					energy = users.getEnergy();
					
					//jika username belum ada
					if(username == null){
						//insert ke tabel
						users.insert(addUsename.getText());
						
						//kemudian ambil datanya
						users.getUser(addUsename.getText());
						
						//masukan data ke atribut id , username dan energy
						id = users.getId();
						username =  users.getUsername();
						energy = users.getEnergy();
					}
					
					addUsename.setText("");
					//masuk ke animasi
					anim.run(stage,root2,id,username,energy,klik);
				}
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
		stage.setScene(scene1);
		stage.show();
		
	}
	
	/*untuk merefresh tabel*/
	public void refresh(){
		users.remove();
		usersTable.setItems(users.getDataUsersList());
	}
	
}	