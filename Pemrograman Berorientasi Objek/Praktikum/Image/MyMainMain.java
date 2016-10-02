import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.ToggleGroup;
import javafx.scene.control.TextField;
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;
import javafx.scene.text.Text;
import javafx.scene.Group;
import javafx.scene.image.Image; // untuk menampung gambar
import javafx.scene.image.ImageView; //untuk menampilkan gambar
import javafx.stage.Stage;

public class MyMainMain extends Application{
	
	public static void main(String[] args){
		Application.launch(args);
	}
	
	
	@Override public void start(Stage stage){
/* --------- Scene 1*/
		/*Scene welcome*/
		Group root = new Group();
		Scene welcomeScene = new Scene(root, 300,200);
		
		Text scenetitle = new Text("Cari Gambar Hewan");//scene title
		scenetitle.setFont(Font.font("Tahoma",FontWeight.BOLD, 30));
		scenetitle.setLayoutX(0);//posisi X
		scenetitle.setLayoutY(30);//posisi Y
		root.getChildren().add(scenetitle);
		
		Label lHewan = new Label("Hewan");//label Hewan
		lHewan.setLayoutX(30);//posisi X
		lHewan.setLayoutY(80);//posisi Y
		root.getChildren().add(lHewan);
		
		TextField tHewan = new TextField();//Textfield Hewan
		tHewan.setLayoutX(100);//posisi X
		tHewan.setLayoutY(80);//posisi Y
		root.getChildren().add(tHewan);
		
		/*tombol cari*/
		Button bCari = new Button("Cari");//tombol cari
		bCari.setLayoutX(205);//posisi X
		bCari.setLayoutY(110);//posisi Y
		root.getChildren().add(bCari);
		
/* -----Scene 2*/
		Group rootM = new Group();
		Scene mainScene = new Scene(rootM, 400, 450);
		
		//set gambar
		Image img1 = new Image("img/img1.jpg");
		Image img2 = new Image("img/img2.jpg");
		Image img3 = new Image("img/img3.jpg");
		Image img4 = new Image("img/img4.jpg");
		Image img5 = new Image("img/img5.jpg");
		
		ImageView ViewM = new ImageView();
		ViewM.setImage(img5);
		ViewM.setFitHeight(400);//untuk ukuran panjang
		ViewM.setFitWidth(400);//untuk ukuran lebar
		
		Label mNama = new Label("Gambar tidak ditemukan ! ");
		mNama.setLayoutX(10);
		mNama.setLayoutY(415);
		
		Button mBack = new Button("Cari yang lain ! ");
		mBack.setLayoutX(300);
		mBack.setLayoutY(412);
		
		rootM.getChildren().add(mNama);
		rootM.getChildren().add(mBack);
		rootM.getChildren().add(ViewM);
		
		//tombol login yang ada di scene welcomeScene
		bCari.setOnAction(new EventHandler<ActionEvent>(){
			
			@Override
			public void handle(ActionEvent e){
				
				if(tHewan.getText().equals("burung")){
					ViewM.setImage(img1);
					mNama.setText("ini gambar burung");
				}else if(tHewan.getText().equals("ikan")){
					ViewM.setImage(img2);
					mNama.setText("ini gambar ikan");
				}else if(tHewan.getText().equals("harimau")){
					ViewM.setImage(img3);
					mNama.setText("ini gambar harimau");
				}else if(tHewan.getText().equals("gajah")){
					ViewM.setImage(img4);
					mNama.setText("ini gambar gajah");
				}else{
					ViewM.setImage(img5);
					mNama.setText("Gambar tidak ditemukan ! ");
				}
				
				stage.setScene(mainScene);//maka scene menjadi mainScene
			}
			
			
			
		});
		
		mBack.setOnAction(new EventHandler<ActionEvent>(){
			
			@Override
			public void handle(ActionEvent e){
				tHewan.setText("");
				stage.setScene(welcomeScene);
			}
			
		});
		
		stage.setScene(welcomeScene);
		stage.sizeToScene();
		stage.show();
	}
}