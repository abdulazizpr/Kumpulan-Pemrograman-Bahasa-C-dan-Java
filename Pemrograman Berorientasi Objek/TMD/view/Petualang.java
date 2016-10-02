package view;

import javafx.geometry.Rectangle2D;
import javafx.scene.paint.Color;
import javafx.scene.canvas.*;
import javafx.scene.image.Image;

public class Petualang{
	
	private double x;
	private double y;
	private double width;
	private double height;
	private double velocityX;
	private double velocityY;
	private Image image;
	private int status;
	
	public Petualang(){
		status = 0;
	}
	
	//menggambar objek petualang
	public void draw(GraphicsContext gc){
		image = new Image("assets/petualang.png");
		this.width = image.getWidth();
		this.height = image.getHeight();
		gc.drawImage(image,this.x,this.y+20);
	}
	
	//set posisi petualang
	public void setPosition(double x,double y){
		this.x = x;
		this.y = y;
	}
	
	//set kecepatan petualang
	public void setVelocity(double x,double y){
		this.velocityX = x;
        this.velocityY = y;
	}
	
	//tambah kecepatan petualang
	public void addVelocity(double x,double y){
		this.velocityX += x;
        this.velocityY += y;
	}
	
	//update posisi petualang
	public void update(double time){
		this.x += this.velocityX * time;
		this.y += this.velocityY * time;
	}
	
	//mendapatkan posisi X
	public double getX(){
		return this.x;
	}
	
	//mendapatkan posisi Y
	public double getY(){
		return this.y;
	}
	
	//lempar boundary untuk collision
	public Rectangle2D getBoundary(){
        return new Rectangle2D(this.x,this.y,this.width,this.height);
    }
	
}