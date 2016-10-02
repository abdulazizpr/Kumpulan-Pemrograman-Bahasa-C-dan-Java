import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.Group;
import javafx.scene.text.Text;
import javafx.stage.Stage;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.PasswordField;
import javafx.scene.control.TextField;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;

public class FormLogin extends Application{
	
	@Override public void start (Stage stage){
		/**Scene1**/
		Group root1 = new Group();
		Scene scene1 = new Scene(root1,300,400);
		
		/*Username*/
		Label lUname = new Label("Username");
		lUname.setLayoutX(30);
		lUname.setLayoutY(40);
		root1.getChildren().add(lUname);
		
		TextField tfUname = new TextField();
		tfUname.setLayoutX(100);
		tfUname.setLayoutY(40);
		root1.getChildren().add(tfUname);
		
		/*Password*/
		Label lPass = new Label("Password");
		lPass.setLayoutX(30);
		lPass.setLayoutY(100);
		root1.getChildren().add(lPass);
		
		PasswordField pass = new PasswordField();
		pass.setLayoutX(100);
		pass.setLayoutY(100);
		root1.getChildren().add(pass);
			
		/*Button Login*/
		Button bLogin = new Button("Masuk");
		bLogin.setLayoutX(100);
		bLogin.setLayoutY(160);
		root1.getChildren().add(bLogin);
		
		/*Scene 2*/
		Group root2 = new Group();
		Scene scene2 = new Scene(root2,300,400);
		
		Label masuk = new Label("Selamat Datang");
		masuk.setLayoutX(100);
		masuk.setLayoutY(100);
		root2.getChildren().add(masuk);
		
		/*Pencocokan Username dan Password*/
		bLogin.setOnAction(new EventHandler<ActionEvent>(){
			@Override
				public void handle(ActionEvent e){
					if(pass.getText().equals("ilkom")&&tfUname.getText().equals("ilkom")){
						stage.setScene(scene2);
					}
				}
		});
		
			stage.setScene(scene1);
			stage.sizeToScene();
			stage.show();
	}
	
	public static void main(String[] args){
		Application.launch(args);
	}
	
}