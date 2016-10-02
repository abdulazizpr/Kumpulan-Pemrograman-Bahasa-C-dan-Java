<?php
	
	include "Aset.php";
	include "Pabrik.php";
	include "Gudang.php";

	$opabrik = new Pabrik();
	$ogudang = new Gudang();
	
	$opabrik->setKodePabrik(1);
	$opabrik->setNamaPabrik("Gangsir");
	$opabrik->setAlamatPabrik("Bandung");
	$opabrik->setTeleponPabrik("08188899977");
	
	echo $opabrik->getKodePabrik()."</br>";
	echo $opabrik->getNamaPabrik()."</br>";
	echo $opabrik->getAlamatPabrik()."</br>";
	echo $opabrik->getTeleponPabrik()."</br>";
	
	
?>