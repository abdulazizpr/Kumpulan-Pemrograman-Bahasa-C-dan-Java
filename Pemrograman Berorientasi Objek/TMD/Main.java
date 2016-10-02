import view.Home;
import view.Audio;
import javafx.application.Application;
import javafx.stage.Stage;
import javafx.stage.StageStyle;

public class Main extends Application{
	
	public static void main(String[] args){
		launch(args);
	}
	
	@Override
	public void start(Stage stage){
		Home awal = new Home();
		//untuk menghilangkan panel atas
		stage.initStyle(StageStyle.UNDECORATED);
		
		//play music background
		Audio bgm = new Audio();
		bgm.setFile("assets/musik.wav");
		bgm.soundPlay();
		
		awal.show(stage);
	}
	
}