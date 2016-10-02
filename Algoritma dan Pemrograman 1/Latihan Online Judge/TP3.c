//Saya Yuda Wijaya Prawira tidak melakukan kecurangan seperti yang telah dispesifikasikan pada mata kuliah Algoritma dan Pemrograman I dalam mengerjakan TP2, jika saya melakukan kecurangan maka Allah/Tuhan adalah saksi saya, dan saya bersedia menerima hukumanNya. Aamiin.
#include <stdio.h>

typedef struct{
	int hari;
	int jam;
	int menit;
	int detik;
	int jumlah;
}waktu;

typedef struct{
	int tempuh; //perjalanan waktu yang dipake kendaraan
	int perbedaan; //perbedaan waktu kendaraan
	int kemarin; //apabila berangkatnya kemarin
	int tipe; //memilih jenis kendaraan
}kendaraan;

int main(){
	kendaraan mobil; //type kendaraan mobil
	kendaraan bus; // type kendaraan bus
	kendaraan pesawat; //type kendaraan pesawat
	kendaraan tipe; // memilih type kendaraan
	waktu berangkat; // waktu moni berangkat
	waktu sampai; //waktu moni sampai
	
	scanf ("%d", &tipe.tipe);
	scanf ("%d", &sampai.hari);
	scanf ("%d %d %d", &sampai.jam, &sampai.menit, &sampai.detik);

	sampai.jumlah = (sampai.hari * 86400) + (sampai.jam * 3600) + (sampai.menit * 60) + sampai.detik;
	
	//deklarasi perjalanan mobil, bus, pesawat
	mobil.tempuh = 145818; //konversi detik 40 jam 30 menit 18 detik 
	bus.tempuh = 181230; // konversi detik 50 jam 20 menit 30 detik
	pesawat.tempuh = 26740; // konversi detik 7 jam 25 menit 40 detik
	
	//switch tipe kendaraan
		switch (tipe.tipe){
			case 1: {
			if (sampai.hari > 0 && sampai.hari <= 7){
				if (sampai.jumlah < mobil.tempuh){//mengjitung waktu sampai
					mobil.kemarin = sampai.jumlah - mobil.tempuh;
					mobil.perbedaan = 604800 + mobil.kemarin;
					//apabila perginya menaren
					
					berangkat.hari = mobil.perbedaan / 86400;//apabila perginya hari ini
					berangkat.jam = (mobil.perbedaan % 86400) / 3600;//menghitung jam
					berangkat.menit = ((mobil.perbedaan % 86400) %3600) / 60;//menghitung menit
					berangkat.detik =  ((mobil.perbedaan % 86400) % 3600) % 60;//menghitung detik
						printf ("mobil\n");
						printf ("%d\n", berangkat.hari);
						printf ("%.2d %.2d %.2d\n", berangkat.jam, berangkat.menit, berangkat.detik);
			
				}else{
					mobil.perbedaan = sampai.jumlah - mobil.tempuh;
					
					berangkat.hari = mobil.perbedaan / 86400;
					berangkat.jam = (mobil.perbedaan % 86400) / 3600;
					berangkat.menit = ((mobil.perbedaan % 86400) %3600) / 60;
					berangkat.detik =  ((mobil.perbedaan % 86400) % 3600) % 60;
						printf ("mobil\n");
						printf ("%d\n", berangkat.hari);
						printf ("%.2d %.2d %.2d\n", berangkat.jam, berangkat.menit, berangkat.detik);
					}
			
				}
			}break;
		case 2: {
			if (sampai.hari > 0 && sampai.hari <= 7){
				if (sampai.jumlah < bus.tempuh){
					bus.kemarin = sampai.jumlah - bus.tempuh;
					bus.perbedaan = 604800 + bus.kemarin;
					
					berangkat.hari = bus.perbedaan / 86400;
					berangkat.jam = (bus.perbedaan % 86400) / 3600;
					berangkat.menit = ((bus.perbedaan % 86400) %3600) / 60;
					berangkat.detik =  ((bus.perbedaan % 86400) % 3600) % 60;
						printf ("bus\n");
						printf ("%d\n", berangkat.hari);
						printf ("%.2d %.2d %.2d\n", berangkat.jam, berangkat.menit, berangkat.detik);
			
			}else{
				bus.perbedaan = sampai.jumlah - bus.tempuh;
					
				berangkat.hari = bus.perbedaan / 86400;
				berangkat.jam = (bus.perbedaan % 86400) / 3600;
				berangkat.menit = ((bus.perbedaan % 86400) %3600) / 60;
				berangkat.detik =  ((bus.perbedaan % 86400) % 3600) % 60;
					printf ("bus\n");
					printf ("%d\n", berangkat.hari);
					printf ("%.2d %.2d %.2d\n", berangkat.jam, berangkat.menit, berangkat.detik);
					}
			
				}
			}break;
		case 3: {
			if (sampai.hari > 0 && sampai.hari <= 7){
				if (sampai.jumlah < pesawat.tempuh){
					pesawat.kemarin = sampai.jumlah - pesawat.tempuh;
					pesawat.perbedaan = 604800 + pesawat.kemarin;
					
					berangkat.hari = pesawat.perbedaan / 86400;
					berangkat.jam = (pesawat.perbedaan % 86400) / 3600;
					berangkat.menit = ((pesawat.perbedaan % 86400) %3600) / 60;
					berangkat.detik =  ((pesawat.perbedaan % 86400) % 3600) % 60;
						printf ("pesawat\n");
						printf ("%d\n", berangkat.hari);
						printf ("%.2d %.2d %.2d\n", berangkat.jam, berangkat.menit, berangkat.detik);
			
			}else{
				pesawat.perbedaan = sampai.jumlah - pesawat.tempuh;
			
				berangkat.hari = pesawat.perbedaan / 86400;
				berangkat.jam = (pesawat.perbedaan % 86400) / 3600;
				berangkat.menit = ((pesawat.perbedaan % 86400) %3600) / 60;
				berangkat.detik =  ((pesawat.perbedaan % 86400) % 3600) % 60;
					printf ("pesawat\n");
					printf ("%d\n", berangkat.hari);
					printf ("%.2d %.2d %.2d\n", berangkat.jam, berangkat.menit, berangkat.detik);
					}
			
				}
			}break;
		default : {
			printf ("pilihan tidak ada\n");
			break;
		}
	}
		
return 0;		
}
