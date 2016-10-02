/*
Class ini digunakan untuk membuat bola yang menembakan peluru terdapat juga pengaturan pada peluru
*/

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

public class BolaJagoan extends Circle{
	
	Rectangle rect;
	float velocity;
	double x,y;
	
	//array untuk menampung peluru
	ArrayList<Peluru> arrPeluru = new ArrayList<Peluru>();
	ArrayList<Peluru> arrPeluruKiri = new ArrayList<Peluru>();
	ArrayList<Peluru> arrPeluruKanan = new ArrayList<Peluru>();
	
	public BolaJagoan(){
		//constructor
		rect = new Rectangle();
		rect.setStroke(Color.GREEN);
		rect.setFill(null);
		setFill(Color.RED);
	}
	
	public void setWidth(double width){
		//procedure yang digunakan untuk menentukan ukuran bola
		setRadius(width/2);
		rect.setWidth(width);
		rect.setHeight(width);
	}
	
	public void setPosition(double x,double y){
		//procedure yang digunakan untuk mengatur posisi bola
		this.x = x;
		this.y = y;
		setLayoutX(x+getRadius());
		setLayoutY(y+getRadius());
		rect.setX(x);
		rect.setY(y);
	}
	
	public double getX(){
		//fungsi untuk mendapatkan nilai koordinat x dari bola jagoan
		return x;
	}
	
	public double getY(){
		//fungsi untuk mendapatkan nilai koordinat y dari bola jagoan
		return y;
	}
	
	public Rectangle getRectangle(){
		//fungsi untuk mendapatkan persegi dari bola jagoan
		return rect;
	}
	
	public float getVelocity(){
		//fungsi untuk mendapatkan nilai percepatan bola jagoan
		return velocity;
	}
	
	public void setVelocity(float velocity){
		//procedure untuk menentukan nilai percepatan bola jagoan
		this.velocity = velocity;
	}
	
	public void addToGroup(Group root){
		//add bola jagoan ke scene
		root.getChildren().add(this);
		root.getChildren().add(rect);
	}
	
	
	public void shoot(Group root){
		Peluru peluru = new Peluru(x+getRadius(),y);
		arrPeluru.add(peluru);
		root.getChildren().add(peluru);
	}
	
	public void shootKiri(Group root){
		//procedure untuk membuat peluru kiri
		Peluru peluru = new Peluru(x+getRadius(),y);
		arrPeluruKiri.add(peluru);
		root.getChildren().add(peluru);
	}
	
	public void shootKanan(Group root){
		//procedure untuk membuat peluru kanan
		Peluru peluru = new Peluru(x+getRadius(),y);
		arrPeluruKanan.add(peluru);
		root.getChildren().add(peluru);
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
	
	public void updatePeluruKiri(Group root){
		//procedure untuk menembakan peluru kiri
		//array untuk menampung peluru yang akan dihapus
		ArrayList<Peluru> delPeluru = new ArrayList<Peluru>();
		for(Peluru peluruKiri : arrPeluruKiri){
			//untuk menggrakan peluru
			peluruKiri.setY(peluruKiri.getY()-5);
			peluruKiri.setX(peluruKiri.getX()-3);
			//jika peluru sudah melewati batas
			//maka dimasukan ke array untuk hapus
			if(peluruKiri.getY()<0){
				delPeluru.add(peluruKiri);
			}
		}
		//menghapus peluru
		for(Peluru peluru:delPeluru){
			arrPeluruKiri.remove(peluru);
			root.getChildren().remove(peluru);
		}
	}
	
	public void updatePeluruKanan(Group root){
		//procedure untuk menembakan peluru kiri
		//array untuk menampung peluru yang akan dihapus
		ArrayList<Peluru> delPeluru = new ArrayList<Peluru>();
		for(Peluru peluruKanan : arrPeluruKanan){
			//untuk menggrakan peluru
			peluruKanan.setY(peluruKanan.getY()-5);
			peluruKanan.setX(peluruKanan.getX()+4);
			//jika peluru sudah melewati batas
			//maka dimasukan ke array untuk hapus
			if(peluruKanan.getY()<0){
				delPeluru.add(peluruKanan);
			}
		}
		//menghapus peluru
		for(Peluru peluru:delPeluru){
			arrPeluruKanan.remove(peluru);
			root.getChildren().remove(peluru);
		}
	}
}