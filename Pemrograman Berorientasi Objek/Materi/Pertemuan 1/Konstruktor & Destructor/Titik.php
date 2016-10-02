<?php

	class Titik{
		/*kelas yang digunakan untuk mengimplementasikan sebuah tipe titik*/
		
		private $x; /*koordinat x*/
		private $y; /*koordinat y*/
		
		public function __construct(){
			/*konstruktor*/
			$this->x = 0;
			$this->y = 0;
		}
		
		public function setX($xp){
			/*mengeset nilai koordinat x*/
			$this->x = $xp;
		}
		
		public function getX(){
			/*mengembalikan nilai koordinat x*/
			return $this->x;
		}
		
		public function setY($yp){
			/*mengeset nilai koordinat y*/
			$this->y = $yp;
		}
		
		public function getY(){
			/*mengembalikan nilai koordinat x*/
			return $this->y;
		}
		
		function __destruct(){
			/*destruktor*/
		}
		
	}


?>