class Atribut{
	
	public:
		Atribut(){
		}
		
		/*method untuk mengakses kelas Tabel dan AlatTulis*/
		void AksesAtribut(Tabel tab,AlatTulis at[],int n){
			
			for(int i=0;i<n;i++){
				string str[3];
				str[0] = "" + at[i].getKodeAlatTulis();
				str[1] = "" + at[i].getNamaAlatTulis();
				str[2] = "" + at[i].getHarga();
				tab.buatBaris(str,3,3);
			}
			
		}
	
};