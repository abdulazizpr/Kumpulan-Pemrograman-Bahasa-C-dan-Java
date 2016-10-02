#include <stdio.h>
#include <string.h>

/*
Saya Abdul Aziz Priatna tidak melakukan kecurangan seperti yang telah dispesifikasikan
pada mata kuliah Strurktur Data dalam mengerjakan TP6, jika saya melakukan kecurangan
maka Allah/Tuhan adalah saksi saya, dan saya bersedia menerima hukumanNya. Aamiin.

	
(STCKS1) Stack Kartu Mual


Pembuat Soal: Asdos

Batas Waktu Eksekusi	5 Detik
Batas Memori	1 MB

Gunakan stack representasi statis untuk soal ini.Gunakan konsep stack, (1)Ozin, (2)Iip, (3)Ahmad, dan (4)Fitri sedang bermain kartu, masing masing akan mendapatkan jumlah kartu yang sama, pemain mendapatkan giliran mmembuang, jika kartu yang akan dikeluarkan paling kecil diantara pemain yang lain. 

n, 0 < n < 50, banyaknya kartu n baris angka integer 1, 2, 3, dan 4 yang menandakan namab pemain diikuti dengan angka kartu dan jenis kartu, dibatasi dengan spasi. 

Urutan stack hasil pembuangan kartu pemain di tampilkan dari top.
clue : gunakan lima buah stack.
catatan : 
1. untuk permain ini kedudukan hati > tempe > keriting > sekop (berlaku jika angka sama)
2. kartu hanya terdiri dari angka 1 - 10
Contoh Masukan

8
1 3 hati 
2 2 hati
4 6 hati
3 1 sekop
1 7 keriting
2 2 tempe
3 1 tempe
4 5 tempe

Contoh Keluaran

3 hati
7 keriting
6 hati
5 tempe
2 hati
2 tempe
1 sekop
1 tempe

*/

//kontainer
typedef struct{
	int angka;
	char kartu[100];
	int prioritas;
}kontainer;

//stack
typedef struct{
	int top;
	kontainer data[50];
}stack;

//proses stack
void createEmpty(stack *);
int isEmpty(stack );
int isFull(stack );
void push(int ,char [],int ,stack *);
void pop(stack *);
kontainer lempardata(stack *);
void buang_kartu(stack *,stack *,stack *,stack *S4,stack *);