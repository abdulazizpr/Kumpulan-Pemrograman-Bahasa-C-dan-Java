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
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.scene.text.Font;
import javafx.stage.Stage;

import controller.ProsesBarang;

public class Table{
	
	public Table(){
	}
	
	public static class BarangBeli{
		private final SimpleStringProperty No;
		private final SimpleStringProperty KodeBarang;
		private final SimpleStringProperty QtyBarang;
		private final SimpleStringProperty HargaBarang;
		
		private BarangBeli(String NO,String KB,String QB,String HB){
			this.No = new SimpleStringProperty(NO);
			this.KodeBarang = new SimpleStringProperty(KB);
			this.QtyBarang = new SimpleStringProperty(QB);
			this.HargaBarang = new SimpleStringProperty(HB);
		}
		
		public String geNo(){
			return No.get();
		}
		
		public void setNo(String NO){
			No.set(NO);
		}
		
		public String getKodeBarang(){
			return KodeBarang.get();
		}
		
		public void setKodeBarang(String KB){
			KodeBarang.set(KB);
		}
		
		public String getQtyBarang(){
			return QtyBarang.get();
		}
		
		public void setQtyBarang(String QB){
			QtyBarang.set(QB);
		}
		
		public String getHargaBarang(){
			return HargaBarang.get();
		}
		
		public void setHargaBarang(String HB){
			HargaBarang.set(HB);
		}
	}
	
	private TableView<BarangBeli> table = new TableView<BarangBeli>();
	private final ObservableList<BarangBeli> data2 = FXCollections.observableArrayList();
	private HBox hb = new HBox();
	private int no = 1;
	
	
	public void tampil(Stage stage){
		
		ProsesBarang pbrg = new ProsesBarang();
		Scene scene = new Scene(new Group());
		Group root = new Group();
		
		final Label label = new Label("Tabel Pembelian Barang");
		
		TableColumn NoCol = new TableColumn("No");
		NoCol.setMaxWidth(50);
		NoCol.setCellValueFactory(
			new PropertyValueFactory<BarangBeli,String>("No")
		);
		
		TableColumn kodebarangCol = new TableColumn("Kode Barang");
		kodebarangCol.setMaxWidth(120);
		kodebarangCol.setCellValueFactory(
			new PropertyValueFactory<BarangBeli,String>("KodeBarang")
		);
		
		TableColumn qtyCol = new TableColumn("Quantity");
		qtyCol.setMaxWidth(120);
		qtyCol.setCellValueFactory(
			new PropertyValueFactory<BarangBeli,String>("qtyBarang")
		);
		
		TableColumn hargaCol = new TableColumn("Harga");
		hargaCol.setMaxWidth(120);
		hargaCol.setCellValueFactory(
			new PropertyValueFactory<BarangBeli,String>("HargaBarang")
		);
		
		table.getColumns().addAll(NoCol,kodebarangCol,qtyCol,hargaCol);
		table.setItems(data2);
		
		final VBox vbox = new VBox();
		vbox.setSpacing(5);
		vbox.getChildren().addAll(label,table,hb);
		vbox.setPadding(new Insets(10,0,0,10));
		
		//----------Memasukan data ke dalam table (Proses Read)
		int jumlah = 0, i = 0;
		String[][] daftar = new String[25][5];
		
		try{
			pbrg.prosesBrg();
			jumlah = pbrg.getJml();
			daftar = pbrg.getHasil();
		}catch(Exception e){
			System.out.println(pbrg.getError());
		}
		
		for(i=0;i<jumlah;i++){
			String nomor = "" + no;
			data2.add(new BarangBeli(
				nomor,
				daftar[i][0],
				daftar[i][1],
				daftar[i][2]
			));
			no++;
		}
		
		//----------Tambah Data ke table (Proses Add)
		final TextField addKodeBarang = new TextField();
		addKodeBarang.setPromptText("Kode Barang");
		addKodeBarang.setMaxWidth(kodebarangCol.getPrefWidth());
		
		//untuk add kuantiti barang
		final TextField addQtyBarang = new TextField();
		addQtyBarang.setPromptText("Qty Barang");
		addQtyBarang.setMaxWidth(qtyCol.getPrefWidth());
		
		
		//untuk add harga barang
		final TextField addHargaBarang = new TextField();
		addHargaBarang.setPromptText("Harga Barang");
		addHargaBarang.setMaxWidth(hargaCol.getPrefWidth());
		
		final Label label1 = new Label("");
		label1.setLayoutX(30);
		label1.setLayoutY(550);
		
		final Label label2 = new Label("");
		label2.setLayoutX(60);
		label2.setLayoutY(550);
		
		final Label label3 = new Label("");
		label3.setLayoutX(90);
		label3.setLayoutY(550);
		root.getChildren().addAll(label1,label2,label3);
		
		final Button addButton = new Button("Tambah");
		addButton.setOnAction(new EventHandler<ActionEvent>(){
			@Override
				public void handle(ActionEvent e){
					//add data ke list
					//secara otomatis tabel akan terupdate secara otomatis menyesuaikan data yang ada di dalam list
					
					/* data2.add(new BarangBeli(
						""+no,
						addKodeBarang.getText(),
						addQtyBarang.getText(),
						addHargaBarang.getText())
					); */
					
					pbrg.tambahBarang(addKodeBarang.getText(),addQtyBarang.getText(),addHargaBarang.getText());
										
					addKodeBarang.setText("");
					addQtyBarang.setText("");
					addHargaBarang.setText("");
					label1.setText(addQtyBarang.getText());
					label1.setText(addHargaBarang.getText());
					no++;
					stage.show();
				}
		});
		
		
		
		//add ke scene
		hb.getChildren().addAll(addKodeBarang,addQtyBarang,addHargaBarang,addButton);
		
		((Group) scene.getRoot()).getChildren().addAll(vbox);
		
		stage.setScene(scene);
		stage.show();
	}
	
}
