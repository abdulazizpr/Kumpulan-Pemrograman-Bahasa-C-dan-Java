<?php

class Gudang extends Pabrik implements Aset{
	
	var $kodeAset;
	var $jenisAset;
	var $nilaiAset;
	var $kodeGudang;
	var $namaGudang;
	var $alamatGudang;
	
	function __construct(){
	}
	
	function setKodeAset($kodeAset){
		$this->kodeAset = $kodeAset;
	}
	
	function getKodeAset(){
		return $this->kodeAset;
	}
	
	function setJenisAset($jenisAset){
		$this->jenisAset = $jenisAset;
	}
	
	function getJenisAset(){
		return $this->jenisAset;
	}
	
	function setNilaiAset($nilaiGudang){
		$this->nilaiAset = $nilaiAset;
	}
	
	function getNilaiAset(){
		return $this->NilaiAset;
	}
	
	function setKodeGudang($kodeGudang){
		$this->kodeGudang = $kodeGudang;
	}
	
	function getKodeGudang(){
		return $this->kodeGudang;
	}
	
	function setNamaGudang($namaGudang){
		$this->namaGudang = $namaGudang;
	}
	
	function getNamaGudang(){
		return $this->namaGudang;
	}
	
	function setAlamatGudang($alamatGudang){
		$this->alamatGudang = $alamatGudang;
	}
	
	function getAlamatGudang(){
		return $this->alamatGudang;
	}
	
	function __destruct(){
	}
}

?>