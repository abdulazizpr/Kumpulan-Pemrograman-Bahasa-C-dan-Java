<?php
	
	include "Titik.php";
	
	/*main untuk mengetes kelas Titik*/
	$t1 = new Titik();
	$t1->setX(18);
	$t1->setY(28);
	
	echo "t1 : nilai X : ".$t1->getX()."</br>";
	echo "t1 : nilai Y : ".$t1->getY()."</br>";

?>