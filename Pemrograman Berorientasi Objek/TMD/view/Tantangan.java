package view;

import javafx.geometry.Rectangle2D;
import javafx.scene.paint.Color;
import javafx.scene.canvas.*;

public class Tantangan {
	
	private double x;
	private double y;
	private double width;
	private double height;
	private double velocityX;
	private double velocityY;
	private Color color;
	private int status;
	
	//konstruktor
	public Tantangan(){
		this.status = 0;
	}
	
	//menggambar objek tantangan
	public void draw(GraphicsContext gc){
		gc.setFill(color);
		gc.fillRect(this.x,this.y,this.width,this.height);
	}
	
	//mengatur ukuran tantangan
	public void setSize(double width, double height){
		this.width = width;
		this.height = height;
	}
	
	//mengatur posisi tantangan
	public void setPosition(double x,double y){
		this.x = x;
		this.y = y;
	}
	
	//mengatur warna tantangan
	public void setColor(int i){
		if(i==1){//jika iterasi 1
			color = Color.RED;//warna merah
		}else if(i==2){//iterasi 2
			color = Color.BLUE;//warna biru
		}else if(i==3){//iterasi 3
			color = Color.GREEN;//warna hijau
		}else if(i==4){//iterasi 4
			color = Color.YELLOW;//warna kuning
		}
		
	}
	
	//mengatur kecepatan tantangan
	public void setVelocity(double x,double y){
		this.velocityX += x;
        this.velocityY += y;
	}
	
	//update posisi tantangan
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
	
	//mendapatkan boundary untuk collision
	public Rectangle2D getBoundary(){
        return new Rectangle2D(this.x,this.y,this.width,this.height-18);
    }
	
	//set status jika sudah lewat
	public void setStatus(int stat){
		this.status = stat;
	}
	
	//dapatkan status
	public int getStatus(){
		return this.status;
	}
	
	
}