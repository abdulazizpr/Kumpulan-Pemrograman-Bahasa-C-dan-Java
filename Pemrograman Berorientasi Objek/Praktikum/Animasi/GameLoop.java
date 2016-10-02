import javafx.animation.Animation;
import javafx.animation.KeyFrame;
import javafx.animation.Timeline;
import javafx.animation.FillTransition;
import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Cursor;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.input.MouseEvent;
import javafx.scene.paint.Color;
import javafx.stage.Stage;
import javafx.util.Duration;
import entity.BolaJagoan;
import global.Constant;

public class GameLoop extends Application{
	
	private BolaJagoan bola;
	//variabel untuk menentukan kapan kemunculan peluru
	private int TIME=0;
	
	@Override
	public void start(Stage stage){
		stage.setTitle(Constant.TITLE + "v" + Constant.VERSION);
		Group root = new Group();
		Scene scene = new Scene(root,Constant.WIDTH,Constant.HEIGHT,Color.WHITE);
		
		//membuat bola jagoan
		bola = new BolaJagoan();
		bola.setWidth(50);
		bola.setPosition(0,Constant.HEIGHT - (bola.getRadius()*2));
		bola.setVelocity(1);
		bola.setCursor(Cursor.HAND);
		bola.setOnMouseDragged(draggedCircle);
		bola.addToGroup(root);
		
		//untuk transisi bola
		FillTransition ft = new FillTransition(Duration.millis(5000), bola, Color.RED, Color.BLUE);
		ft.setCycleCount(4);
		ft.setAutoReverse(true);
	 
		ft.play();
		
		//untuk anmasi
		Duration fps = Duration.millis(1000/60);
		KeyFrame oneFrame = new KeyFrame(fps,new EventHandler<ActionEvent>(){
			@Override
			public void handle(ActionEvent event){
				if(TIME%30==0){
					//untuk memunculkan bola peluru
					bola.shoot(root);
					bola.shootKiri(root);
					bola.shootKanan(root);
				}
				
				//untuk menggerakan peluru
				bola.updatePeluru(root);
				bola.updatePeluruKiri(root);
				bola.updatePeluruKanan(root);
				TIME++;
			}
		});
		
		stage.setScene(scene);
		stage.show();
		
		Timeline t1 = new Timeline();
		t1.setCycleCount(Animation.INDEFINITE);
		t1.getKeyFrames().add(oneFrame);
		t1.play();
	}
	
	//untuk menggerakan bolajagoan dengan mouse
	EventHandler<MouseEvent> draggedCircle = new EventHandler<MouseEvent>(){
		@Override
		public void handle(MouseEvent mouse){
			//untuk merubah posisi bola
			bola.setPosition(mouse.getSceneX()-bola.getRadius(),mouse.getSceneY()-bola.getRadius());
		}
	};
	
}