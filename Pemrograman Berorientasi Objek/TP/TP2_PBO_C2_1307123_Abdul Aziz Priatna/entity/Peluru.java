/*
	class ini digunakan untuk membuat peluru dengan berbentuk persegi
*/

package entity;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;

public class Peluru extends Rectangle{
	
	Peluru(double x, double y,int status){
		/*
		ini merupakan constructo
		nilai dari masukan/parameternya akan dijadikan koordinat awal dari peluru
		*/
		
		this.setX(x-5);
		this.setY(y);
		setHeight(10);
		setWidth(10);
		setStroke(Color.GREEN);
		
		if(status==0) setFill(Color.RED);
		if(status==1) setFill(Color.GREEN);
		if(status==2) setFill(Color.BLUE);
	}
	
}