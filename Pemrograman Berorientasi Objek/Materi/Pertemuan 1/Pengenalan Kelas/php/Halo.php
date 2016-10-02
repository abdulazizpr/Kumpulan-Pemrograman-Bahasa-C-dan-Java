<?php

	class Halo{
		
		var $kata = "";
		
		function Halo(){
			$this->kata = "Halo Dunia";
		}
		
		function tulis(){
			echo $this->kata."</br>";
		}
		
	}

?>