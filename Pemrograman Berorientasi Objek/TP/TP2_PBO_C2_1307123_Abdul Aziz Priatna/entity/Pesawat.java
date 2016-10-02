package entity;
import java.util.ArrayList;
import javafx.scene.Group;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;
import javafx.scene.shape.Rectangle;
import javafx.scene.shape.*;
import javafx.animation.FillTransition;
import javafx.animation.Animation;
import javafx.animation.KeyFrame;
import javafx.animation.Timeline;
import javafx.util.Duration;
import javafx.scene.image.Image; // untuk menampung gambar
import javafx.scene.image.ImageView; //untuk menampilkan gambar
import java.util.Random;

public class Pesawat extends Circle{
	
	Rectangle rect;
	ImageView ViewPesawat;
	Image ImgPesawat;
	Peluru peluru;
	float velocity;
	double x,y;
	int skor;
	
	//array untuk menampung peluru
	ArrayList<Peluru> arrPeluru = new ArrayList<Peluru>();
	ArrayList<Peluru> arrPeluruKiri = new ArrayList<Peluru>();
	ArrayList<Peluru> arrPeluruKanan = new ArrayList<Peluru>();
	
	public Pesawat(){
		//constructor
		rect = new Rectangle();
		rect.setStroke(Color.GREEN);
		rect.setFill(null);
		setFill(Color.RED);
	}
	
	public void setImage(String str){
		ImgPesawat = new Image(str);
		ViewPesawat = new ImageView();
		ViewPesawat.setImage(ImgPesawat);
		ViewPesawat.setFitHeight(400);//untuk ukuran panjang
		ViewPesawat.setFitWidth(300);//untuk ukuran lebar
	}
	
	public void setSize(double width,double height){
		//procedure yang digunakan untuk menentukan ukuran pesawat
		setRadius(width/2);
		ViewPesawat.setFitHeight(height);
		ViewPesawat.setFitWidth(width);
	}
	
	public void setPosition(double x,double y){
		//procedure yang digunakan untuk mengatur posisi pesawat
		this.x = x;
		this.y = y;
		setLayoutX(x+getRadius());
		setLayoutY(y+getRadius());
		ViewPesawat.setX(x);
		ViewPesawat.setY(y);
	}
	
	public void addToGroup(Group root){
		//add pesawat ke scene
		root.getChildren().add(ViewPesawat);
	}
	
	
	public double getX(){
		//fungsi untuk mendapatkan nilai koordinat x dari pesawat
		return x;
	}
	
	public double getY(){
		//fungsi untuk mendapatkan nilai koordinat y dari pesawat
		return y;
	}
	
	public void shoot(Group root,int status){
		peluru = new Peluru(x+getRadius(),y,status);
		arrPeluru.add(peluru);
		root.getChildren().add(peluru);
	}
	
	public Peluru getPeluru(){
		return peluru;
	}
	
	
	
	public void updatePeluru(Group root){
		//procedure untuk menembakan peluru tengah
		//array untuk menampung peluru yang akan dihapus
		ArrayList<Peluru> delPeluru = new ArrayList<Peluru>();
		for(Peluru peluru : arrPeluru){
			//untuk menggrakan peluru
			peluru.setY(peluru.getY()-5);
			
			//jika peluru sudah melewati batas
			//maka dimasukan ke array untuk hapus
			if(peluru.getY()<0){
				delPeluru.add(peluru);
			}
		}
		//menghapus peluru
		for(Peluru peluru:delPeluru){
			arrPeluru.remove(peluru);
			root.getChildren().remove(peluru);
		}
	}
	
	public Rectangle getBounds(){
		//fungsi untuk mendapatkan persegi dari bola jagoan
		return rect;
	}
	
	//untuk mengambil semua peluru
	public ArrayList<Peluru> get(){
		return arrPeluru;
	}
	
	public void removePeluru(Group root){
		root.getChildren().remove(peluru);
	}
	
}