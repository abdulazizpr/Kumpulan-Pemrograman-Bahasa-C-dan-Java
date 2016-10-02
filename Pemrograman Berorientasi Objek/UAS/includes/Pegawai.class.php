<?php

class Pegawai extends DB{
	
	function getPegawai(){
		//method_exists untuk mengambil data gaji pegawai
		$query = "select *from tgajipegawai";
		return $this->execute($query);
	}
	
	function insertPegawai($kode,$nama,$jenis,$jumlah){
		//untuk memasukan data gaji pegawai
		$query = "insert into tgajipegawai values('".$kode."','".$nama."','".$jenis."','".$jumlah."')";
		return $this->execute($query);
	}
	
	function getId($kode){
		//mengambil data dari kode
		$query = "select *from tgajipegawai where kode='$kode'";
		return $this->execute($query);
	}
	
	function updatePegawai($kode,$nama,$jenis,$jumlah){
		//untuk update gaji pegawai
		$query = "update tgajipegawai set nama='".$nama."', jenis_gaji='".$jenis."', jumlah='".$jumlah."' where kode='".$kode."'";
		return $this->execute($query);
	}
	
	function deletePegawai($kode){
		//untuk menghapus data pegawai berdasarkan kode
		$query = "delete from tgajipegawai where kode='$kode'";
		return $this->execute($query);
	}
	
}

?>