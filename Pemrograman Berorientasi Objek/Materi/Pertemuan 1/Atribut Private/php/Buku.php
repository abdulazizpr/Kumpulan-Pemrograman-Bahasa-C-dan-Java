<?php

class Buku{
	
	var $judul = "";
	var $pengarang = "";
	
	function buku($j="",$p=""){
		$this->judul = $j;
		$this->pengarang = $p;
	}
	
	function setJudul($j=""){
		$this->judul = $j;
	}
	
	function setPengarang($p=""){
		$this->pengarang = $p;
	}
	
	function getJudul(){
		return $this->judul;
	}
	
	function getPengarang(){
		return $this->pengarang;
	}
	
}


?>