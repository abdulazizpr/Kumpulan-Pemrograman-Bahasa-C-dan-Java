<?php

class Pabrik{
	
	var $kodePabrik;
	var $namaPabrik;
	var $alamatPabrik;
	var $teleponPabrik;
	
	function __construct(){
	}
	
	function setKodePabrik($kodePabrik){
		$this->kodePabrik = $kodePabrik; 
	}
	
	function getKodePabrik(){
		return $this->kodePabrik;
	}
	
	function setNamaPabrik($namaPabrik){
		$this->namaPabrik = $namaPabrik;
	}
	
	function getNamaPabrik(){
		return $this->namaPabrik;
	}
	
	function setAlamatPabrik($alamatPabrik){
		$this->alamatPabrik = $alamatPabrik;
	}
	
	function getAlamatPabrik(){
		return $this->alamatPabrik;
	}
	
	function setTeleponPabrik($teleponPabrik){
		$this->teleponPabrik = $teleponPabrik;
	}
	
	function getTeleponPabrik(){
		return $this->teleponPabrik;
	}
	
	
	function __destruct(){
	}
}

?>