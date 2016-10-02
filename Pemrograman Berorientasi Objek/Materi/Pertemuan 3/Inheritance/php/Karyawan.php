<?php

	class Karyawan extends Manusia{
		
		var $nomor_pegawai;
		var $jabatan;
		var $departemen;
		
		function Karyawan(){
		}
		
		function setNomorPegawai($nomor_pegawai){
			$this->nomor_pegawai = $nomor_pegawai;
		}
		
		function getNomorPegawai(){
			return $this->nomor_pegawai;
		}
		
		function setJabatan($jabatan){
			$this->jabatan = $jabatan;
		}
		
		function getJabatan(){
			return $this->jabatan;
		}
		
		function setDepartemen($departemen){
			$this->departemen = $departemen;
		}
		
		function getDepartemen(){
			return $this->departemen;
		}
		
	}

?>