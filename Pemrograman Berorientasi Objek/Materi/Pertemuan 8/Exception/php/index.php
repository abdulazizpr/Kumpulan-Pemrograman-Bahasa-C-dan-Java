<?php

	include "Eksepsi.php";

	$eks = new Eksepsi();
	echo "eksepsi throw standar </br>";
	
	/*eksepsi throw standar*/
	try{
		$eks->eksepsiThrowStandar(-1);
	}catch(Exception $e){
		echo $e->getMessage()."</br>";
	}
	
	echo "-------------------------</br>";
	
	echo "eksepsi throw sendiri</br>";
	
	/*eksepsi throw dengan kalimat sendiri*/
	try{
		$eks->eksepsiThrowSendiri(-1);
	}catch(Exception $e){
		echo $e->getMessage()."</br>";
	}

	echo "-------------------------</br>";
	
	/*eksepsi try catch karena mengakses indeks array lebih dari jumlah tempat array*/
	try{
		$eks->eksepsiThrowIndexOutOfBounds(10,10,10,$tabInt[10]);
	}catch(Exception $e){
		echo $e->getMessage()."<br/>";
	}
	
	
?>