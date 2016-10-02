package controller;

import view.*;
import java.util.Random;
import java.util.ArrayList;

public class ProsesPergerakan{
	
	public ProsesPergerakan(){
		
	}
	
	//proses pergerakan petualang
	public void movepetualang(Petualang petualang,boolean up,boolean down,boolean left,boolean right){
		/*tombol atas*/
		if(up==true){
			petualang.addVelocity(0,-50);
			if(petualang.getY()<5){
				petualang.setPosition(petualang.getX(),petualang.getY());
			}
			
		}
		
		/*tombol bawah*/
		if(down==true){
			petualang.addVelocity(0,50);
			if(petualang.getY()>300){
				petualang.setPosition(petualang.getX(),petualang.getY()-10);
			}
			
		}
		
		/*tombol kiri*/
		if(left==true){
			petualang.addVelocity(-50,0);
			
			if(petualang.getX()<10){
				petualang.setPosition(petualang.getX()+10,petualang.getY());
			}
			
		}
		
		/*tombol kanan*/
		if(right==true){
			petualang.addVelocity(50,0);
			if(petualang.getX()>440){
				petualang.setPosition(petualang.getX()-10,petualang.getY());
			}
		}
	}
	
}