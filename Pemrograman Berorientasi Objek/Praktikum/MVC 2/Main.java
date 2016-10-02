import view.Table;
import javafx.application.Application;
import javafx.stage.Stage;

public class Main extends Application{
	
	public static void main(String[] args){
		launch(args);
	}
	
	@Override
	public void start(Stage stage){
		Table tampilBrg = new Table();
		tampilBrg.tampil(stage);
	}
	
}