<?php

	include "Manusia.php";
	include "Karyawan.php";
	
	$kmanusia = new Manusia();
	$kmanusia->setNama("Gina");
	$kmanusia->setAlamat("Bandung");
	$kmanusia->setNoKTP("320.120.777");
	$kmanusia->setNoTelepon("08188899977");
	
	echo $kmanusia->getNama()."</br>";
	echo $kmanusia->getAlamat()."</br>";
	echo $kmanusia->getNoKTP()."</br>";
	echo $kmanusia->getNoTelepon()."</br>";
	
	$kkaryawan = new Karyawan();
	$kkaryawan->setNama("Gina");
	$kkaryawan->setAlamat("Bandung");
	$kkaryawan->setNoKTP("320.120.777");
	$kkaryawan->setNoTelepon("08188899977");
	$kkaryawan->setNomorPegawai("13202020");
	$kkaryawan->setJabatan("-");
	$kkaryawan->setDepartemen("-");
	
	echo $kkaryawan->getNama()."</br>";
	echo $kkaryawan->getAlamat()."</br>";
	echo $kkaryawan->getNoKTP()."</br>";
	echo $kkaryawan->getNoTelepon()."</br>";
	echo $kkaryawan->getNomorPegawai()."</br>";
	echo $kkaryawan->getJabatan()."</br>";
	echo $kkaryawan->getDepartemen()."</br>";
	
?>