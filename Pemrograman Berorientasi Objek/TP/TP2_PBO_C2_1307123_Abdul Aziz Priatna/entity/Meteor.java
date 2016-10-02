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
import javafx.scene.text.Font;
import javafx.scene.text.Text;
import javafx.scene.text.TextBoundsType;
import javafx.scene.layout.StackPane;

public class Meteor{
	
	Rectangle rect;
	ImageView ViewMeteor;
	Image ImgMeteor;
	float velocity;
	double x,y;
	
	public Meteor(){
		//constructor
		rect = new Rectangle();
		rect.setStroke(Color.GREEN);
		rect.setFill(null);
	}
	
	public void setImage(String str){
		ImgMeteor = new Image(str);
		ViewMeteor = new ImageView();
		ViewMeteor.setImage(ImgMeteor);
	}
	
	public void setSize(double width,double height){
		//procedure yang digunakan untuk menentukan ukuran pesawat
		ViewMeteor.setFitHeight(height);
		ViewMeteor.setFitWidth(width);
		rect.setWidth(width);
		rect.setHeight(width);
	}
	
	public void setPosition(double x,double y){
		//procedure yang digunakan untuk mengatur posisi pesawat
		this.x = x;
		this.y = y;
		ViewMeteor.setX(x);
		ViewMeteor.setY(y);
		rect.setX(x);
		rect.setY(y);
	}
	
	public void addToGroup(Group root){
		//add pesawat ke scene
		root.getChildren().add(ViewMeteor);
	}
	
	
	public double getX(){
		//fungsi untuk mendapatkan nilai koordinat x dari pesawat
		return x;
	}
	
	public double getY(){
		//fungsi untuk mendapatkan nilai koordinat y dari pesawat
		return y;
	}
	
	public float getVelocity(){
		//fungsi untuk mendapatkan nilai percepatan meteor
		return velocity;
	}
	
	public void setVelocity(float velocity){
		//procedure untuk menentukan nilai percepatan meteor
		this.velocity = velocity;
	}
	
	public Rectangle getMeteor(){
		return rect;
	}
	
	public void removeMeteor(Group root){
		root.getChildren().remove(ViewMeteor);
	}

}