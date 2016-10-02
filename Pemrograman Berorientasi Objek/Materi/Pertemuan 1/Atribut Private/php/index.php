<?php

	include "Buku.php";
	
	$b2 = new Buku("J2EE","Orang_1");
	echo $b2->getJudul()."</br>";
	echo $b2->getPengarang()."</br>";

?>