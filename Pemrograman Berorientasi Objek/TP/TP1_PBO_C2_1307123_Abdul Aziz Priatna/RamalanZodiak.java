import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.control.*;	//untuk combobox
import javafx.geometry.Insets;	//untuk combobox
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.ToggleGroup;
import javafx.scene.control.TextField;
import javafx.scene.control.Alert.AlertType;	//untuk pop up alert
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;
import javafx.scene.text.Text;
import javafx.scene.control.PasswordField;	//untuk password
import javafx.scene.Group;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;
import javafx.scene.layout.HBox;	//untuk border image
import javafx.scene.image.Image; // untuk menampung gambar
import javafx.scene.image.ImageView; //untuk menampilkan gambar
import javafx.stage.Stage;

/*
Saya Abdul Aziz Priatna tidak melakukan kecurangan seperti yang telah dispesifikasikan 
pada mata kuliah Pemrograman Berorientasi Objek dalam mengerjakan TP1, jika saya melakukan kecurangan 
maka Allah/Tuhan adalah saksi saya, dan saya bersedia menerima hukumanNya. Aamiin.
*/

public class RamalanZodiak extends Application{
	
	String zodiak = "";
	
	public static void main(String[] args){
		Application.launch(args);
	}
	
	
	@Override public void start(Stage stage){
		
		/*--------------------Scene 1(login)--------------------------------*/
		Group root = new Group();
		Scene sceneLogin = new Scene(root,1000,800); 
		
		Text scenetitle = new Text("Ramalan Zodiak");//scene title
		scenetitle.setFont(Font.font("Tahoma",FontWeight.BOLD, 50));
		scenetitle.setLayoutX(300);//posisi X
		scenetitle.setLayoutY(180);//posisi Y
		root.getChildren().add(scenetitle);
		
		Label message = new Label();
		
		Label lNama = new Label("Nama");//label Nama
		lNama.setFont(Font.font("Tahoma",FontWeight.NORMAL, 20));//posisi X
		lNama.setLayoutX(200);//posisi X
		lNama.setLayoutY(260);//posisi Y
		root.getChildren().add(lNama);
		
		TextField tNama = new TextField();//Textfield Nama
		tNama.setLayoutX(300);//posisi X
		tNama.setLayoutY(260);//posisi Y
		tNama.setPrefColumnCount(40);
		root.getChildren().add(tNama);
		
		Label lPassowrd = new Label("Password");//label Password
		lPassowrd.setFont(Font.font("Tahoma",FontWeight.NORMAL, 20));//posisi X
		lPassowrd.setLayoutX(200);//posisi X
		lPassowrd.setLayoutY(330);//posisi Y
		root.getChildren().add(lPassowrd);
		
		PasswordField tPassword = new PasswordField();//PasswordField Password
		tPassword.setLayoutX(300);//posisi X
		tPassword.setLayoutY(330);//posisi Y
		tPassword.setPrefColumnCount(40);
		root.getChildren().add(tPassword);
		
		/*tombol login*/
		Button bLogin = new Button("Login");//tombol login
		bLogin.setLayoutX(720);//posisi X
		bLogin.setLayoutY(380);//posisi Y
		root.getChildren().add(bLogin);
		
		Label lCreated = new Label("dibuat oleh : 1307123_Abdul Aziz Priatna");//creator
		lCreated.setFont(Font.font("Tahoma",FontWeight.NORMAL, 20));//set font
		lCreated.setLayoutX(200);//posisi X
		lCreated.setLayoutY(480);//posisi Y
		root.getChildren().add(lCreated);
		
		/*----------------------Scene 2----------------------------*/
		Group rootM = new Group();
		Scene scene2 = new Scene(rootM,1000,800); 
		
		
		Text scenetitle2 = new Text("Ramalan Zodiak");//scene title
		scenetitle2.setFont(Font.font("Tahoma",FontWeight.BOLD, 50));
		scenetitle2.setLayoutX(300);//posisi X
		scenetitle2.setLayoutY(180);//posisi Y
		rootM.getChildren().add(scenetitle2);
		
		Label lWelcome = new Label();//label Welcome
		lWelcome.setFont(Font.font("Tahoma",FontWeight.NORMAL, 20));//posisi X
		lWelcome.setLayoutX(200);//posisi X
		lWelcome.setLayoutY(220);//posisi Y
		rootM.getChildren().add(lWelcome);
		
		Label lText = new Label("silahkan masukan tanggal dan bulan lahir anda");//label
		lText.setFont(Font.font("Tahoma",FontWeight.NORMAL, 20));//posisi X
		lText.setLayoutX(200);//posisi X
		lText.setLayoutY(240);//posisi Y
		rootM.getChildren().add(lText);
		
		Label lTanggal = new Label("Tanggal");//label tanggal
		lTanggal.setFont(Font.font("Tahoma",FontWeight.NORMAL, 20));//posisi X
		lTanggal.setLayoutX(250);//posisi X
		lTanggal.setLayoutY(280);//posisi Y
		rootM.getChildren().add(lTanggal);
		
		//combobox tanggal
		ComboBox Tanggal = new ComboBox();
        Tanggal.getItems().addAll(1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31);
		
		Tanggal.setValue("Tanggal");//set awal combobox
		Tanggal.setLayoutX(350);//posisi X
		Tanggal.setLayoutY(280);//posisi Y
		rootM.getChildren().add(Tanggal);
		
		
		Label lBulan= new Label("Bulan");//label Bulan
		lBulan.setFont(Font.font("Tahoma",FontWeight.NORMAL, 20));//posisi X
		lBulan.setLayoutX(250);//posisi X
		lBulan.setLayoutY(320);//posisi Y
		rootM.getChildren().add(lBulan);
		
		//combobox bulan
		ComboBox Bulan = new ComboBox();
        Bulan.getItems().addAll(
            "Januari","Februari","Maret","April","Mei","Juni",
            "Juli","Agustus","September","Oktober","Nopember","Desember"
        );
		
		Bulan.setValue("Bulan");//set awal bulan
		Bulan.setLayoutX(350);//posisi X
		Bulan.setLayoutY(320);//posisi Y
		rootM.getChildren().add(Bulan);
		
		Button bCari = new Button("Cari");//tombol login
		bCari.setLayoutX(720);//posisi X
		bCari.setLayoutY(400);//posisi Y
		rootM.getChildren().add(bCari);
		
		
		/*----------------------Scene 3----------------------------*/
		Group rootK = new Group();
		Scene scene3 = new Scene(rootK,1000,800); 
		
		Text scenetitle3 = new Text("Ramalan Zodiak");//scene title
		scenetitle3.setFont(Font.font("Tahoma",FontWeight.BOLD, 50));
		scenetitle3.setLayoutX(300);//posisi X
		scenetitle3.setLayoutY(180);//posisi Y
		rootK.getChildren().add(scenetitle3);
		
		
		//set gambar
		Image aquarius = new Image("img/aquarius.jpg");
		Image aries = new Image("img/aries.jpg");
		Image cancer = new Image("img/cancer.jpg");
		Image capricorn = new Image("img/capricorn.jpg");
		Image gemini = new Image("img/gemini.png");
		Image leo = new Image("img/leo.jpg");
		Image libra = new Image("img/libra.jpg");
		Image pisces = new Image("img/pisces.jpg");
		Image sagitarius = new Image("img/sagitarius.jpg");
		Image scorpio = new Image("img/scorpio.jpg");
		Image taurus = new Image("img/taurus.jpg");
		Image virgo = new Image("img/virgo.jpg");
		
		ImageView ViewM = new ImageView();
		ViewM.setImage(capricorn);
		ViewM.setFitHeight(400);//untuk ukuran panjang
		ViewM.setFitWidth(300);//untuk ukuran lebar
		
		//border image
		HBox hBox = new HBox();
		String style_outter = "-fx-border-color: black;"
				  + "-fx-border-width: 10;";
		hBox.setStyle(style_outter);
		hBox.setLayoutX(100);
		hBox.setLayoutY(240);
		hBox.getChildren().add(ViewM);
		rootK.getChildren().add(hBox);
		
		Label lZodiak= new Label();//label Zodiak
		lZodiak.setFont(Font.font("Tahoma",FontWeight.NORMAL, 20));
		lZodiak.setLayoutX(460);//posisi X
		lZodiak.setLayoutY(240);//posisi Y
		rootK.getChildren().add(lZodiak);
		
		/* Text t = new Text (10, 20, "This is a text sample");
		rootK.getChildren().add(t); */
		
		//border text keterangan
		Rectangle rect = new Rectangle(10,10,350,200);
		rect.setFill(Color.TRANSPARENT);
		rect.setStroke(Color.BLACK);
		rect.setLayoutX(450);
		rect.setLayoutY(280);
		rootK.getChildren().add(rect);
		
		//isi text keterangan
		Text keterangan = new Text();
		keterangan.setWrappingWidth(320);
		keterangan.setLayoutX(470);
		keterangan.setLayoutY(310);
		rootK.getChildren().add(keterangan);
		
		Button bBack = new Button("Kembali");//tombol kembali
		bBack.setLayoutX(720);//posisi X
		bBack.setLayoutY(520);//posisi Y
		rootK.getChildren().add(bBack);
		
		//button login
		bLogin.setOnAction(new EventHandler<ActionEvent>(){			
			
			@Override
			public void handle(ActionEvent e){
				
				if(tPassword.getText().equals("ilkom123")){
					lWelcome.setText("Selamat Datang " + tNama.getText() + " ! ");
					stage.setScene(scene2);//masuk ke scene 2
				}else{
					//jika salah muncul pop up
					if(tNama.getText().isEmpty() && tPassword.getText().isEmpty()){//jika nama dan password tidak diisi
						Alert alert = new Alert(AlertType.INFORMATION);
						alert.setTitle("Perhatian");
						alert.setHeaderText(null);
						alert.setContentText("Silahkan isi nama dan password terlebih dahulu !");

						alert.showAndWait();
					}else{
						Alert alert = new Alert(AlertType.ERROR);
						alert.setTitle("Kesalahan");
						alert.setHeaderText("Password anda salah !");
						alert.setContentText("Silahkan coba lagi");

						alert.showAndWait();
					}
				}
				
			}
			
			
			
		});
		
		//button cari
		bCari.setOnAction(new EventHandler<ActionEvent>(){
			
			@Override
			public void handle(ActionEvent e){
				int tgl = (int)Tanggal.getValue();
				String month = Bulan.getValue().toString();
				
				if((tgl>=22 && month=="Desember")||(tgl<=20 && month=="Januari")){
					//Capricorn
					ViewM.setImage(capricorn);
					lZodiak.setText("zodiak anda : Capricorn");
					keterangan.setText("Orang dengan zodiak Capricorn juga memiliki sifat pantang mundur. Jika sudah maju dengan tekad yang kuat, Dia akan sangat sulit digoyahkan. Capricorn senantiasa ingin berjuang untuk perubahan baik. Melawan hal-hal negatif untuk perubahan dengan penuh kesadaran jiwa.");
					stage.setScene(scene3);
				}else if(((tgl>20 && tgl<=31) && month=="Januari")||(tgl<=19 && month=="Februari")){
					//Aquarius
					ViewM.setImage(aquarius);
					lZodiak.setText("zodiak anda : Aquarius");
					keterangan.setText("Perasaannya sangat halus dan tajam sehingga sedikit mudah tersinggung. Pada umumnya Orang Aquarius suka menolong dan tidak suka keributan, cinta damai. Sehingga Orang Aquarius sangat cocok jika menjadi pendamai atau pemisah ketika ada Orang atau kelompok yang bertikai.");
					stage.setScene(scene3);
				}else if(((tgl>=20 && tgl<=28) && month=="Februari")||(tgl<=20 && month=="Maret")){
					//Pisces
					ViewM.setImage(pisces);
					lZodiak.setText("zodiak anda : Pisces");
					keterangan.setText("Orang pisces memiliki hati yang halus sehingga jiwa penolongnya sering ada terutama pada orang yang dikasihinya. Pada usia tua mengalami kehidupan yang terjamin. Umumnya memiliki tampilan melankolik yang tampak bersedih atau murung.");
					stage.setScene(scene3);
				}else if(((tgl>20 && tgl<=31) && month=="Maret")||(tgl<=20 && month=="April")){
					//Aries
					ViewM.setImage(aries);
					lZodiak.setText("zodiak anda : Aries");
					keterangan.setText("Sifat dasar Aries meskipun sering dikatakan keras kepala, akan tetapi suka dengan hal-hal baru dan cara berpikirnya berkembang. Sehingga akan mudah baginya memiliki wawasan luas dan memiliki kemungkinan besar menjadi Orang yang serba tahu. Jika mau berusaha menjadi yang terbaik, Aries bisa lebih cepat dan lebih mudah dalam mencapai kesuksesan.");
					stage.setScene(scene3);
				}else if(((tgl>20 && tgl<=30) && month=="April")||(tgl<=21 && month=="Mei")){
					//Taurus
					ViewM.setImage(taurus);
					lZodiak.setText("zodiak anda : Taurus");
					keterangan.setText("Taurus adalah Orang yang termasuk sabar, telaten, dan juga pintar dalam menyesuaikan diri. Akan tetapi meskipun sabar, jika sudah marah bisa sangat marah dan mengamuk seperti banteng. Jadi jangan macam-macam apalagi mencari masalah dengan Orang Taurus. Termasuk Orang yang bisa berhemat, akan tetapi jika memiliki keinginan atau tujuan, bisa mengeluarkan uang yang jumlahnya tidak sedikit.");
					stage.setScene(scene3);
				}else if(((tgl>=22 && tgl<=31) && month=="Mei")||(tgl<=21 && month=="Juni")){
					//Gemini
					ViewM.setImage(gemini);
					lZodiak.setText("zodiak anda : Gemini");
					keterangan.setText("Mempunyai sifat sosial yang cukup tinggi namun memiliki pendirian yang tidak tetap. Sering memiliki cara berpikir yang berbeda-beda untuk setiap keadaan. Namun meski begitu, Gemini memiliki cara berpikir yang luas, atas dasar itulah gemini sering mengalami perubahan pikiran.");
					stage.setScene(scene3);
				}else if(((tgl>21 && tgl<=30) && month=="Juni")||(tgl<=21 && month=="Juli")){
					//Cancer
					ViewM.setImage(cancer);
					lZodiak.setText("zodiak anda : Cancer");
					keterangan.setText("Sebenarnya Cancer merupakan sosok penyayang. Namun kadang karena suatu hal dia bisa menjadi jahat, kejam, atau sikap sejenis. Tapi meskipun begitu didalamnya sebenarnya masih ada sifat dasarnya yang lembut dan penyayang. Sehingga jika berpasangan dengan Pisces yang memiliki sifat dasar suka mengalah, kemungkinan besar hati Zodiak Cancer akan luluh.");
					stage.setScene(scene3);
				}else if(((tgl>21 && tgl<=31) && month=="Juli")||(tgl<=21 && month=="Agustus")){
					//Leo
					ViewM.setImage(leo);
					lZodiak.setText("zodiak anda : Leo");
					keterangan.setText("Leo yang dilambangkan dengan singa ini termasuk Orang yang suka kejujuran, berterus terang, dan juga terbuka. Sehingga tidak sedikit yang banyak dipercaya oleh Orang. Sayangnya Leo mudah sekali tersulut emosinya. Akan tetapi meski begitu mudah juga baginya untuk baik kembali. Jadi sabar saja jika menghadapi emosi leo yang naik turun.");
					stage.setScene(scene3);
				}else if(((tgl>21 && tgl<=31) && month=="Agustus")||(tgl<=22 && month=="September")){
					//Virgo
					ViewM.setImage(virgo);
					lZodiak.setText("zodiak anda : Virgo");
					keterangan.setText("Virgo merupakan orang yang kritis. Segala masukan dan pendapat dari Orang lain tidak akan ditelan mentah-mentah. Selalu diteliti dulu dan di sharing mana yang benar, tepat, atau masuk akal menurutnya. Jika dirasa tidak tepat maka Dia bisa dengan mudah menolaknya.");
					stage.setScene(scene3);
				}else if(((tgl>22 && tgl<=30) && month=="September")||(tgl<=23 && month=="Oktober")){
					//Libra
					ViewM.setImage(libra);
					lZodiak.setText("zodiak anda : Libra");
					keterangan.setText("Libra merupakan karakter yang halus dan juga lembut. Sayangnya dalam mengambil keputusan sering ceroboh dan itu sering membuatnya menyesal pada akhirnya. Libra juga merupakan Orang yang menonjol dan juga cerdas.");
					stage.setScene(scene3);
				}else if(((tgl>23 && tgl<=31) && month=="Oktober")||(tgl<=22 && month=="Nopember")){
					//Scorpio
					ViewM.setImage(scorpio);
					lZodiak.setText("zodiak anda : Scorpio");
					keterangan.setText("Scorpio merupakan Orang yang memiliki semangat dalam menempuh suatu tujuan atau cita-cita. Dalam memperjuangkan sesuatu selalu memiliki cara tersendiri yang kadang tidak begitu banyak dilakukan Orang lain. Jika Scorpio baik pada seseorang, maka Dia akan jadi Orang yang benar-benar baik. Sebaliknya, jika jahat pada seseorang maka Dia adalah Orang yang benar-benar jahat.");
					stage.setScene(scene3);
				}else if(((tgl>22 && tgl<=31) && month=="Nopember")||(tgl<=21 && month=="Desember")){
					//Sagitarius
					ViewM.setImage(sagitarius);
					lZodiak.setText("zodiak anda : Sagitarius");
					keterangan.setText("Pada dasarnya Sagitarius adalah Orang yang berani mengambil resiko. Jika Dia merasa bisa dalam melangkah, Dia tidak akan takut untuk mencoba. Akan semakin kuat jika mendapat dukungan penuh dari pihak lain. Dan lebih baik tidak mendapatkan masukan yang membuatnya pesimis.");
					stage.setScene(scene3);
				}else if(Tanggal.getValue().toString()=="Tanggal" && Bulan.getValue().toString()=="Bulan"){
					Alert alert = new Alert(AlertType.INFORMATION);
					alert.setTitle("Informasi");
					alert.setHeaderText(null);
					alert.setContentText("Silahkan pilih tanggal dan bulan !");
				}
				
				
			}
			
		});
		
		//button kembali
		bBack.setOnAction(new EventHandler<ActionEvent>(){
			
			@Override
			public void handle(ActionEvent e){
				stage.setScene(scene2);
			}
			
		});
		
		stage.setScene(sceneLogin);
		stage.sizeToScene();
		stage.show();
	}
	
}