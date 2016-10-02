package view;

import controller.ProsesTelepon;

public class TampilTelepon{
	
	public TampilTelepon(){
		//konstruktor
	}
	
	public void tampil(){
		ProsesTelepon ptelepon = new ProsesTelepon();
		
		try{
			ptelepon.prosesTelp();
			System.out.println(ptelepon.getHasil());
		}catch(Exception e){
			System.out.println(ptelepon.getError());
		}
	}
	
}