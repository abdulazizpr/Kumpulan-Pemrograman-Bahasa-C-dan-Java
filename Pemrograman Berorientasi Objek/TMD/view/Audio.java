package view;

import java.io.*;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.sound.sampled.*;

//Setting BGM
public class Audio{

	private String wavefile; //nama file
	private Clip clip; //clip

	//konstruktor kosong
    public Audio(){
    	
    }
	
	public void setFile(String file){
		wavefile = file;
		clip = null;
	}

    //prosedur memainkan clip
	public void soundPlay(){
		try{
			File soundFile = new File(wavefile); //tipe file suara
			AudioInputStream soundIn = AudioSystem.getAudioInputStream(soundFile); 
			AudioFormat format = soundIn.getFormat(); //set format suara
			DataLine.Info info = new DataLine.Info(Clip.class, format);

			clip = (Clip)AudioSystem.getLine(info);
			clip.open(soundIn);
			clip.loop(Clip.LOOP_CONTINUOUSLY); //putar ulang clip secara terus menerus
		}
		catch(Exception e){

		}
	}
	
	//prosedur memainkan clip sekali
	public void soundPlayOnce(){
		try{
			File soundFile = new File(wavefile); //tipe file suara
			AudioInputStream soundIn = AudioSystem.getAudioInputStream(soundFile); 
			AudioFormat format = soundIn.getFormat(); //set format suara
			DataLine.Info info = new DataLine.Info(Clip.class, format);

			clip = (Clip)AudioSystem.getLine(info);
			clip.open(soundIn);
			clip.loop(0); //putar sekali
		}
		catch(Exception e){

		}
	}

	//prosedur menghentikan clip
	public void soundStop(){
		if(clip.isRunning()){
			clip.stop();
		}
	}
}
