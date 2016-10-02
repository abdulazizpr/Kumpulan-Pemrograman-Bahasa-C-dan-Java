package controller;

import java.io.*;

import java.util.ArrayList;
import javafx.event.EventHandler;
import javafx.scene.input.KeyEvent;
import javafx.scene.input.KeyCode;

public class ProsesInput{
	
	private boolean up;
	private boolean down;
	private boolean left;
	private boolean right;
	private boolean space;
	
	public ProsesInput(){
	}
	
	public void press(KeyEvent Key){
		if(Key.getCode()==KeyCode.UP) up = true;
		if(Key.getCode()==KeyCode.DOWN) down = true;
		if(Key.getCode()==KeyCode.LEFT) left = true;
		if(Key.getCode()==KeyCode.RIGHT) right = true;
		if(Key.getCode() == KeyCode.SPACE ) space = true;
	}
		
	
	public void release(KeyEvent Key){
		if(Key.getCode()==KeyCode.UP) up = false;
		if(Key.getCode()==KeyCode.DOWN) down = false;
		if(Key.getCode()==KeyCode.LEFT) left = false;
		if(Key.getCode()==KeyCode.RIGHT) right = false;
		if(Key.getCode() == KeyCode.SPACE ) space = false;
	}
	
	public boolean getUp(){
		return up;
	}
	
	public boolean getDown(){
		return down;
	}
	
	public boolean getLeft(){
		return left;
	}
	
	public boolean getRight(){
		return right;
	}
	
	public boolean getSpace(){
		return space;
	}
	
}