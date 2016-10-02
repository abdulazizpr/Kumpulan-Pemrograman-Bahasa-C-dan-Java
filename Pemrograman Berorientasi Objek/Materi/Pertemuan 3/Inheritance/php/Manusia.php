<?php

	class Manusia{
		
		var $nama;
		var $alamat;
		var $no_ktp;
		var $no_telepon;
		
		function Manusia(){
		}
		
		function setNama($nama){
			$this->nama = $nama;
		}
		
		function getNama(){
			return $this->nama;
		}
		
		function setAlamat($alamat){
			$this->alamat = $alamat;
		}
		
		function getAlamat(){
			return $this->alamat;
		}
		
		function setNoKTP($no_ktp){
			$this->no_ktp = $no_ktp;
		}
		
		function getNoKTP(){
			return $this->no_ktp;
		}
		
		function setNoTelepon($no_telepon){
			$this->no_telepon = $no_telepon;
		}
		
		function getNoTelepon(){
			return $this->no_telepon;
		}
		
		
		
	}

?>