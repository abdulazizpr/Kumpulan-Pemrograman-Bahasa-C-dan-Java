<?php
	
	include("conf.php");
	include("includes/Template.class.php");
	include("includes/DB.class.php");
	include("includes/Pegawai.class.php");
	
	//meproses data
	//yang akan menggantikan kode tampilan
	$pegawai = new Pegawai($db_host,$db_user,$db_password,$db_name);
	
	//membaca template skin tampilan
	$tpl = new Template("templates/skin1.html");
	
	//proses penyimpanan data
	if(isset($_POST['simpan'])){
		$pegawai->open();
		//jika data kosong maka muncul notifikasi
		if(empty($_POST['kode']) && empty($_POST['nama']) && empty($_POST['jenis_gaji']) && empty($_POST['jumlah'])){
			echo "<p style='color:red;'>Harap isi data terlebih dahulu</p>";
		}else{
			
			$pegawai->getId($_POST['kode']);
			//jika data sudah ada
			if($pegawai->getResult()){
				//maka update data telepon
				$pegawai->updatePegawai($_POST['kode'],$_POST['nama'],$_POST['jenis_gaji'],$_POST['jumlah']);
			}else{
				//maka masukan data ke dalam tabel telepon
				$pegawai->insertPegawai($_POST['kode'],$_POST['nama'],$_POST['jenis_gaji'],$_POST['jumlah']);
			}
		}
		$pegawai->close();
	}
	
	//variabel kosong
	$kode = '';
	$nama = '';
	$jenis_gaji = '';
	$jumlah = '';
	$form = '';
	$notification = '';
	$lembur = '';
	$pokok = '';
	
	//jika tombol menekan edit
	if(isset($_POST['edit'])){
		//masukan ke dalam variabel
		$kode = $_POST['kode'];
		$nama = $_POST['nama'];		
		$jenis_gaji = $_POST['jenis_gaji'];
		
		//jika jenis gajinya lembur
		if($jenis_gaji=='Lembur'){
			//maka lembur di select di combo box
			$lembur = "selected";
		//jika jenis gajinya pokok
		}else if($jenis_gaji=='Pokok'){
			//maka pokok di select di combo box
			$pokok = "selected";
		}
	
		$jumlah = $_POST['jumlah'];		
	}
	
	//jika tombol menekan delete
	if(isset($_POST['delete'])){
		//maka delete berdasarkan kode
		$pegawai->open();
		$pegawai->deletePegawai($_POST['kode']);
		$pegawai->close();
	}
	
	//membuat data form
	$form .= "<tr>
					<td>Kode</td>
					<td>:</td>
					<td><input type='text' name='kode' value='".$kode."'/></td>
				</tr>
				<tr>
					<td>Nama</td>
					<td>:</td>
					<td><input type='text' name='nama' value='".$nama."'/></td>
				</tr>
				<tr>
					<td>Jenis Gaji</td>
					<td>:</td>
					<td>
						<select name='jenis_gaji'>
							<option value=''>-Pilih Jenis Gaji-</option>
							<option value='Lembur' ".$lembur.">Lembur</option>
							<option value='Pokok' ".$pokok.">Pokok</option>
						</select>
					</td>
				</tr>
				<tr>
					<td>Jumlah</td>
					<td>:</td>
					<td><input type='text' name='jumlah' value='".$jumlah."'/></td>
				</tr>
				";
	//dengan data yang sudah diproses
	$tpl->replace("DATA_FORM",$form);
	
	$data = '';
	//mengambil data telepon
	$pegawai->open();
	$pegawai->getPegawai();
	while(list($kode,$nama,$jenis_gaji,$jumlah) = $pegawai->getResult()){
		$data .= "<tr>
					<td>".$kode."</td>
					<td>".$nama."</td>
					<td>".$jenis_gaji."</td>
					<td>".$jumlah."</td>
					<td>
						<form action='index.php' method='post'>
							<input type='hidden' name='kode' value='".$kode."'>
							<input type='hidden' name='nama' value='".$nama."'>
							<input type='hidden' name='jenis_gaji' value='".$jenis_gaji."'>
							<input type='hidden' name='jumlah' value='".$jumlah."'>
							<input type='submit' name='edit' value='Edit'> |
							<input type='submit' name='delete' value='Delete'>
						</form>
					</td>
				</tr>";
	}
	$pegawai->close();
	
	//mengganti kode DATA_TABEL
	//dengan data yang sudah diproses
	$tpl->replace("DATA_TABEL",$data);
	
	
	//menampilkan ke layar
	$tpl->write();
	
?>	