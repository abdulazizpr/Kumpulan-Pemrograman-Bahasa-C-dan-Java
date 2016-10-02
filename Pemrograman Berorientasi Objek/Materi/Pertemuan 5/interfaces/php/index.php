<?php

	include "BangunDatar.php";
	include "Persegi.php";
	include "SegitigaSiku.php";

	$opersegi = new persegi();
	$osegitiga = new SegitigaSiku();
	
	echo $opersegi->luas(5,8)."</br>";
	echo $osegitiga->luas(5,8)."</br>";
	
?>