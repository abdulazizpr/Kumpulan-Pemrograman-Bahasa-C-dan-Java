package view;

import javafx.application.Application;
import javafx.beans.property.SimpleStringProperty;
import javafx.beans.property.StringProperty;
import javafx.collections.ObservableList;
import javafx.collections.FXCollections;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Insets;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.control.TextField;
import javafx.scene.control.TableCell;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.scene.text.FontWeight;
import javafx.scene.text.Text;
import javafx.scene.text.Font;
import javafx.scene.control.*;	//untuk combobox
import javafx.scene.input.MouseEvent;
import javafx.stage.Stage;

import controller.ProsesSewa;

public class Tabel{
	
	public Tabel(){
	}
	
	public static class Penyewaan{
		
		//jenis datanya
		private final SimpleStringProperty No;
		private final SimpleStringProperty KodeSewa;
		private final SimpleStringProperty NoFlat;
		private final SimpleStringProperty JenisMobil;
		private final SimpleStringProperty NamaPenyewa;
		private final SimpleStringProperty LamaSewa;
		
		//constructor
		private Penyewaan(String NO,String KS,String NF,String JM,String NP,String LS){
			this.No = new SimpleStringProperty(NO);
			this.KodeSewa = new SimpleStringProperty(KS);
			this.NoFlat = new SimpleStringProperty(NF);
			this.JenisMobil = new SimpleStringProperty(JM);
			this.NamaPenyewa = new SimpleStringProperty(NP);
			this.LamaSewa = new SimpleStringProperty(LS);
		}
		
		public String getNo(){
			return No.get();
		}
		
		public void setNO(String NO){
			No.set(NO);
		}
		
		
		public String getKodeSewa(){
			return KodeSewa.get();
		}
		
		public void setKodeSewa(String KS){
			KodeSewa.set(KS);
		}
		
		public String getNoFlat(){
			return NoFlat.get();
		}
		
		public void setNoFlat(String NF){
			NoFlat.set(NF);
		}
		
		public String getJenisMobil(){
			return JenisMobil.get();
		}
		
		public void setJenisMobil(String JM){
			JenisMobil.set(JM);
		}	
		
		public String getNamaPenyewa(){
			return NamaPenyewa.get();
		}
		
		public void setNamaPenyewa(String NP){
			NamaPenyewa.set(NP);
		}

		public String getLamaSewa(){
			return LamaSewa.get();
		}
		
		public void setLamaSewa(String LS){
			LamaSewa.set(LS);
		}
	}

	private ProsesSewa sewa = new ProsesSewa();
	private TableView<Penyewaan> table = new TableView<Penyewaan>();
	private final ObservableList<Penyewaan> data2 = FXCollections.observableArrayList();
	private HBox hb = new HBox();
	private HBox hb1 = new HBox();
	private HBox hb2 = new HBox();
	private HBox hb3 = new HBox();
	private HBox hb4 = new HBox();
	private HBox hb5 = new HBox();
	private int status = 1;
	private int nomor = 0;
	private int cek = 0;
	
	private String kode_sewa;
	private String no_flat_mobil;
	private String jenis_mobil;
	private String nama_penyewa;
	private String lama_sewa;
	
	private void load_data(){
		int jumlah = 0, i = 0;
		String[][] daftar = new String[25][5];
		
		
		int no = 1;
		
		try{
			sewa.show();
			jumlah = sewa.getJml();
			daftar = sewa.getHasil();
		}catch(Exception e){
			System.out.println(sewa.getError());
		}
		
		for(i=0;i<jumlah;i++){
			data2.add(new Penyewaan(
				"" + no,
				daftar[i][0],
				daftar[i][1],
				daftar[i][2],
				daftar[i][3],
				daftar[i][4] + " hari"
			));
			no++;
		}
		
		if(jumlah == 0){
			nomor = 1;
		}else{
			nomor = no;
		}
	}
	
	public void tampil(Stage stage){
		
		Scene scene = new Scene(new Group());
		Group root = new Group();
		
		stage.setTitle("TP3 PBO");
		stage.setWidth(800);
		stage.setHeight(550);
		
		Text header = new Text("Tabel Penyewaan Mobil");
		header.setFont(Font.font("Tahoma",FontWeight.BOLD, 10));
		header.setLayoutX(400);//posisi X
		header.setLayoutY(180);//posisi Y
		
		TableColumn NoCol = new TableColumn("No");
		NoCol.setMaxWidth(30);
		NoCol.setCellValueFactory(new PropertyValueFactory<Penyewaan, String>("No"));
		
		TableColumn kodesewaCol = new TableColumn("Kode Sewa");
		kodesewaCol.setMaxWidth(100);
		kodesewaCol.setCellValueFactory(new PropertyValueFactory<Penyewaan, String>("KodeSewa"));
		
		TableColumn noflatCol = new TableColumn("Flat Nomor");
		noflatCol.setMaxWidth(150);
		noflatCol.setCellValueFactory(new PropertyValueFactory<Penyewaan, String>("NoFlat"));
		
		TableColumn jenismobilCol = new TableColumn("Jenis Mobil");
		jenismobilCol.setMaxWidth(120);
		jenismobilCol.setCellValueFactory(new PropertyValueFactory<Penyewaan, String>("JenisMobil"));
		
		//kolom harga
		TableColumn namapenyewaCol = new TableColumn("Nama Penyewa");
		namapenyewaCol.setMaxWidth(200);
		//mengintegrasikan kolom pada tabel dengan data
		namapenyewaCol.setCellValueFactory(new PropertyValueFactory<Penyewaan, String>("NamaPenyewa"));
		
		TableColumn lamasewaCol = new TableColumn("Lama Sewa");
		lamasewaCol.setMaxWidth(120);
		//mengintegrasikan kolom pada tabel dengan data
		lamasewaCol.setCellValueFactory(new PropertyValueFactory<Penyewaan, String>("LamaSewa"));
		
		//add kolom ke tabel
		table.getColumns().addAll(NoCol,kodesewaCol,noflatCol,jenismobilCol,namapenyewaCol,lamasewaCol);
		//mengisi tabel dengan data
		table.setItems(data2);
		
		final VBox vbox = new VBox();
		vbox.setSpacing(10);
		vbox.setLayoutX(100);
		vbox.getChildren().addAll(header,table,hb,hb1,hb2);
		vbox.setPadding(new Insets(20,0,0,20));
		
		//----------Memasukan data ke dalam table (Proses Read)
		load_data();
		
		//----------Tambah Data ke table (Proses Add)
			final Label lNomorFlat = new Label("Flat Nomor");
			lNomorFlat.setVisible(false);
			
			final TextField addNomorFlat = new TextField();
			addNomorFlat.setPromptText("Flat Nomor");
			addNomorFlat.setMaxWidth(noflatCol.getPrefWidth());
			addNomorFlat.setPrefColumnCount(40);
			addNomorFlat.setVisible(false);
			
			
			//combobox jenismobilCol
			final Label lJenis = new Label("Jenis Mobil");
			lNomorFlat.setVisible(false);
			
			final ComboBox addJenisMobil = new ComboBox();
			addJenisMobil.getItems().addAll(
				"Sedan",
				"Convertible",
				"Coupe",
				"Sport Utility Vehicle (SUV)"
			);
			
			addJenisMobil.setValue("Jenis Mobil");//set awal bulan
			addJenisMobil.setVisible(false);
			
			final Label lNamaPenyewa = new Label("Nama Penyewa");
			lNamaPenyewa.setVisible(false);
			
			final TextField addNamaPenyewa = new TextField();
			addNamaPenyewa.setPromptText("Nama Penyewa");
			addNamaPenyewa.setPrefColumnCount(40);
			addNamaPenyewa.setMaxWidth(namapenyewaCol.getPrefWidth());
			addNamaPenyewa.setVisible(false);
			
			final Label lLamaSewa = new Label("Lama Sewa");
			lLamaSewa.setVisible(false);
			
			final TextField addLamaSewa= new TextField();
			addLamaSewa.setPromptText("Lama Sewa");
			addLamaSewa.setPrefColumnCount(40);
			addLamaSewa.setMaxWidth(namapenyewaCol.getPrefWidth());
			addLamaSewa.setVisible(false);
			
			final Button addButton = new Button("Tambah");
			final Button editButton = new Button("Ubah");
			final Button deleteButton = new Button("Hapus");
			
			final Button addButton1 = new Button("Tambahkan");
			final Button editButton1 = new Button("Simpan");
			final Button backButton = new Button("Kembali");
			addButton1.setVisible(false);
			editButton1.setVisible(false);
			backButton.setVisible(false);
			
			addButton.setOnAction(new EventHandler<ActionEvent>(){
				@Override
					public void handle(ActionEvent e){
						
						status = status * (-1);
						if(status==-1){
							stage.setHeight(720);
							cek = 1;
							
							lNomorFlat.setVisible(true);
							lJenis.setVisible(true);
							lNamaPenyewa.setVisible(true);
							lLamaSewa.setVisible(true);
							
							addNomorFlat.setVisible(true);
							addJenisMobil.setVisible(true);
							addNamaPenyewa.setVisible(true);
							addLamaSewa.setVisible(true);
							addButton1.setVisible(true);
							backButton.setVisible(true);
							
							addButton.setDisable(true);
							editButton.setDisable(true);
							deleteButton.setDisable(true);
							
							
						}else{
							addNomorFlat.setVisible(false);
							addJenisMobil.setVisible(false);
							addNamaPenyewa.setVisible(false);
							addLamaSewa.setVisible(false);
						}
					}
			});
			
			addButton1.setOnAction(new EventHandler<ActionEvent>(){
				@Override
					public void handle(ActionEvent e){
						
						//add data ke list
						//secara otomatis tabel akan terupdate secara otomatis menyesuaikan data yang ada di dalam list
						String kode_sewa = "";
						if(nomor < 10){
							kode_sewa = "SWG00" + nomor;
						}else if(nomor >= 10 && nomor < 100){
							kode_sewa = "SWG0" + nomor;
						}else{
							kode_sewa = "SWG" + nomor;
						}
						
						sewa.tambahSewa(kode_sewa,addNomorFlat.getText(),addJenisMobil.getValue().toString(),addNamaPenyewa.getText(),Integer.parseInt(addLamaSewa.getText()));
						
						//refresh data
						data2.removeAll(data2);
						load_data();
						
						addNomorFlat.setText("");
						addNamaPenyewa.setText("");
						addLamaSewa.setText("");
						
						stage.setHeight(550);
						
						lNomorFlat.setVisible(false);
						lJenis.setVisible(false);
						lNamaPenyewa.setVisible(false);
						lLamaSewa.setVisible(false);
						
						addNomorFlat.setVisible(false);
						addJenisMobil.setVisible(false);
						addNamaPenyewa.setVisible(false);
						addLamaSewa.setVisible(false);
						addButton1.setVisible(false);
						backButton.setVisible(false);
						
						addButton.setDisable(false);
						editButton.setDisable(false);
						deleteButton.setDisable(false);
					}
			});
			
			editButton.setOnAction(new EventHandler<ActionEvent>(){
				@Override
					public void handle(ActionEvent e){
						
						status = status * (-1);
						if(status==-1){
							stage.setHeight(720);
							cek = 2;
							
							addNomorFlat.setVisible(true);
							addJenisMobil.setVisible(true);
							addNamaPenyewa.setVisible(true);
							addLamaSewa.setVisible(true);
							editButton1.setVisible(true);
							backButton.setVisible(true);
							
							addNomorFlat.setText(no_flat_mobil);
							addJenisMobil.setValue(jenis_mobil);
							addNamaPenyewa.setText(nama_penyewa);
							addLamaSewa.setText(lama_sewa);
							
							addButton.setDisable(true);
							editButton.setDisable(true);
							deleteButton.setDisable(true);
							
							
						}else{
							addNomorFlat.setVisible(false);
							addJenisMobil.setVisible(false);
							addNamaPenyewa.setVisible(false);
							addLamaSewa.setVisible(false);
						}
					}
			});
		
		
		table.setOnMousePressed(new EventHandler<MouseEvent>() {
        @Override 
			public void handle(MouseEvent event) {
				//int index = table.getSelectedRow();
				int index = table.getSelectionModel().getSelectedIndex();
				
				try{
					sewa.show_id(data2.get(index).getKodeSewa());
				}catch(Exception e){
					System.out.println(sewa.getError());
				}
				
				kode_sewa = sewa.getKodeSewa();
				no_flat_mobil = sewa.getNoFlatMobil();
				jenis_mobil = sewa.getJenisMobil();
				nama_penyewa = sewa.getNamaPenyewa();
				lama_sewa = sewa.getLamaSewa();
			
			}
		});
		
		

		
		//add ke scene
		hb.getChildren().addAll(addButton,editButton,deleteButton);
		hb.setSpacing(3);
		
		hb1.getChildren().addAll(addNomorFlat,addJenisMobil,addNamaPenyewa,addLamaSewa);
		hb1.setSpacing(5);
		
		if(cek==1){
			hb2.getChildren().addAll(addButton1,backButton);
		}else if(cek==2){
			hb2.getChildren().addAll(editButton1,backButton);
		}
		
		hb2.setSpacing(3);
		
		((Group) scene.getRoot()).getChildren().addAll(vbox);
		
		stage.setScene(scene);
		stage.show();
	}
	
}
