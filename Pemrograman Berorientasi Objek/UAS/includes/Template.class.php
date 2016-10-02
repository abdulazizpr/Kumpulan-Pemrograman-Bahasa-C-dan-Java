<?php

class Template{
	
	var $filename = '';
	var $content = '';
	
	function Template($filename = ''){
		//konstruktor
		$this->filename = $filename;
		//membaca file tampilan
		$this->content = implode('',file($filename));
	}
	
	function clear(){
		//membersihkan isi kode yang seharusnya diganti
		//mengganti tulisan DATA_..... dengan kosong jika ada yang lupa untuk diganti
		//jika tidak ingin menggunakan kode DATA_... dapat diganti di bagian pola ekspresi
		$this->content = preg_replace("/DATA_[A-Z]_[0-9]+/","",$this->content);
	}
	
	function write(){
		//menulisakan isi file ke layar
		//menghapus DATA_... yang belum diganti
		$this->clear();
		//mengembalikan isi tampilan
		print $this->content;
	}
	
	public function getContent(){
		//mengambil isi file yang sudah di proses
		//menghapus DATA_... yang belum diganti
		$this->clear();
		//mengembalikan isi tampilan
		return $this->content;
	}
	
	function replace($old = '',$new=''){
		//mengganti kode dalam file(DATA_.....)
			//pemrosesan nilai yang akan menggatikan
		if(is_int($new)){
			//jika penggantinya bilangan bulat (diubah formatnya teks)
			$value = sprintf("%d",$new);
		}elseif(is_float($new)){
			//jika penggantinya bilangan real (diubah formatnya teks)
			$value = sprintf("%f",$new);
		}elseif(is_array($new)){
			//jika penggantinya array/tabel (diubah formatnya teks)
			$value = '';
			//pemrosesan setiap elemen array/tabel
			foreach($new as $item){
				$value .= $item.' ';
			}
		}else{
			//jika selain tipe yang ada di atas maka langsung diisikan untuk menggatikan
			$value = $new;
		}
		//menggantikan suatu text dengan text baru (misal DATA_... diganti dengan <table>...</table>)
		$this->content = preg_replace("/$old/",$value,$this->content);
	}
	
}

?>