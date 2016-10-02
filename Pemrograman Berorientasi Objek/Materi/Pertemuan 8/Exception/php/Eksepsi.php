<?php

class Eksepsi{
	
		function __construct(){
			/*konstruktor*/
		}
		
		function eksepsiThrowStandar($kode){
			if($kode < 1){
				throw new Exception("error kode");
			}
		}
		
		function eksepsiThrowSendiri($kode){
			if($kode < 1){
				throw new Exception("error");
			}
		}
		
		function eksepsiThrowIndexOutOfBonds($jumlah, $index, $nilai, $tab){
			
			if($jumlah-1 < $index){
				throw new Exception("array index out of bonds");
			}else{
				$tab = $nilai;
			}
			
		}
	
}

?>