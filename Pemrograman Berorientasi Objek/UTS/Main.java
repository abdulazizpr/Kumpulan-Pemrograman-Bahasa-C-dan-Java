import java.util.Scanner;

/*
ASUMSI :
Dalam rancangan saya, Pasien memiliki 2 bapak yaitu Penyakit dan Kamar karena memiliki
atribut KodePenyakit dan KodeKamar yang ada di dalam pasien(Penyakit sebagai interface dan Kamar menjadi inheritance). Lalu kamar memiliki 2 bapak juga yaitu Gedung dan Ruangan karena dalam dunia nyata Gedung 
memiliki Banyak ruangan dan kamar sendiri memiliki ukuran luas panjang lebar ruangan.

Gedung--|
		-> Kamar-------|
Ruangan-|  			   -->Pasien
		   Penyakit ---|
			
				
				
Sumpah :
Saya Abdul Aziz Priatna tidak melakukan kecurangan seperti yang telah dispesifikasikan 
pada mata kuliah Pemrograman Berorientasi Objek dalam mengerjakan UTS, jika saya melakukan kecurangan 
maka Allah/Tuhan adalah saksi saya, dan saya bersedia menerima hukumanNya. Aamiin.				
*/

class Main{
	
	public static void main(String[] args){
		
		Pasien[] arrPasien = new Pasien[100];
		Kamar[] arrKamar = new Kamar[100];
		
		//data kamar
		arrKamar[0] = new Kamar();
		arrKamar[0].setNomorKamar("KMR001");
		arrKamar[0].setNamaKamar("Melati");
		arrKamar[0].setKegunaan("Ruang Pasien");
		arrKamar[0].setKelas("A");
		
		arrKamar[1] = new Kamar();
		arrKamar[1].setNomorKamar("KMR002");
		arrKamar[1].setNamaKamar("Kamar Bunga");
		arrKamar[1].setKegunaan("Ruang Pasien");
		arrKamar[1].setKelas("B");
		
		arrKamar[2] = new Kamar();
		arrKamar[2].setNomorKamar("KMR003");
		arrKamar[2].setNamaKamar("Tulip");
		arrKamar[2].setKegunaan("Ruang Pasien");
		arrKamar[2].setKelas("A");
		
		arrKamar[2] = new Kamar();
		arrKamar[2].setNomorKamar("KMR004");
		arrKamar[2].setNamaKamar("Melayu");
		arrKamar[2].setKegunaan("Ruang Pasien");
		arrKamar[2].setKelas("C");
		
		arrKamar[3] = new Kamar();
		arrKamar[3].setNomorKamar("KMR005");
		arrKamar[3].setNamaKamar("Kamar Teh");
		arrKamar[3].setKegunaan("Ruang Pasien");
		arrKamar[3].setKelas("C");
		
		//data pasien
		arrPasien[0] = new Pasien();
		arrPasien[0].setKodePasien("PS001");
		arrPasien[0].setNamaPasien("Aziz");
		arrPasien[0].setNomorPenyakit("PN001");
		arrPasien[0].setNomorKamar("KMR001");
		
		arrPasien[1] = new Pasien();
		arrPasien[1].setKodePasien("PS002");
		arrPasien[1].setNamaPasien("Afrizal");
		arrPasien[1].setNomorPenyakit("PN002");
		arrPasien[1].setNomorKamar("KMR004");
		
		arrPasien[2] = new Pasien();
		arrPasien[2].setKodePasien("PS003");
		arrPasien[2].setNamaPasien("Fadhil");
		arrPasien[2].setNomorPenyakit("PN003");
		arrPasien[2].setNomorKamar("KMR003");
		
		System.out.println("Silahkan pilih kategori pencarian : ");
		System.out.println("1. Kamar");
		System.out.println("2. Pasien");
		System.out.print("Pilih : ");
		
		int menu = 0;
		String cari = "";
		Scanner sc = new Scanner(System.in);
		try{
			menu = sc.nextInt();
		}catch(Exception e){
		}
		
		
		//pilihan menu
		switch(menu){
			case 1:{//menu pencarian kamar
				int i = 0;
				System.out.println("+--------------------+");
				System.out.println("|    DATA KAMAR      |");
				System.out.println("+--------------------+");
				for(i=0;i<4;i++){
					System.out.println("| " + arrKamar[i].getNamaKamar());
				}
				System.out.println("+--------------------+");
				
				System.out.print("Masukan nama kamar : ");
				
				try{
					cari = sc.next();
				}catch(Exception e){
				}
				
				int status = 0;
				i = 0;
				while(i<4 && status==0){
					if(cari.equals(arrKamar[i].getNamaKamar())){//jika data kamar sama dengan yang di cari
						//maka status 1
						status = 1;
					}else{
						i++;
					}
				}
				
				//jika ketemu tampilkan
				if(status==1){
					System.out.println("+--------------------+");
					System.out.println("|   HASIL PENCARIAN  |");
					System.out.println("+--------------------+");
					System.out.println("| Kode Kamar : " + arrKamar[i].getNomorKamar());
					System.out.println("| Nama Kamar : " + arrKamar[i].getNamaKamar());
					System.out.println("| Kegunaan   : " + arrKamar[i].getKegunaan());
					System.out.println("| Kelas      : " + arrKamar[i].getKelas());
					System.out.println("+--------------------+");
				}
			}
			break;
			
			case 2:{//menu pencarian pasien
				int i = 0;
				System.out.println("+--------------------+");
				System.out.println("|    DATA PASIEN     |");
				System.out.println("+--------------------+");
				for(i=0;i<3;i++){
					System.out.println("| " + arrPasien[i].getNamaPasien());
				}
				System.out.println("+--------------------+");
				
				System.out.print("Masukan nama pasien : ");
				
				try{
					cari = sc.next();
				}catch(Exception e){
				}
				
				int status = 0;
				i = 0;
				while(i<4 && status==0){
					if(cari.equals(arrPasien[i].getNamaPasien())){//jika nama pasien sama dengan yang di cari
						//maka status 1
						status = 1;
					}else{
						i++;
					}
				}
				
				//jika ketemu tampilkan
				if(status==1){
					System.out.println("+--------------------+");
					System.out.println("|   HASIL PENCARIAN  |");
					System.out.println("+--------------------+");
					System.out.println("| Kode Pasien     : " + arrPasien[i].getKodePasien());
					System.out.println("| Nama Pasien     : " + arrPasien[i].getNamaPasien());
					System.out.println("| Kode Penyakit   : " + arrPasien[i].getNomorPenyakit());
					System.out.println("| Kode Kamar      : " + arrPasien[i].getNomorKamar());
					System.out.println("+--------------------+");
				}
			}
			break;
		}
		
		
		
		
	}
	
}