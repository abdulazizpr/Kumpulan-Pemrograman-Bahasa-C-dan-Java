void tulisMasukan(int n){
	cout << "masukan : " << n << endl;
}

void tulisMasukan(double n){
	cout << "masukan : " << n << endl;
}

template <class Masukan> 
void tulisMasukan(Masukan n){
	cout << "masukan : " << n << endl;
}

int keluaran(int n,double m){
	cout << "keluaran 2 tipe " << n << m << endl;
	
	return n;
}

char keluaran(char n,int m){
	cout << "keluaran 2 tipe " << n << m << endl;
	return n;
	
}

template <class A, class B>
A keluaran(A n,B m){
	cout << "keluaran 2 tipe " << n << m << endl;
	return n;
}

template <class T>
T keluaranO(T n){
	cout << "keluaran overloading " << n << endl;
	return n;
}

template <class T>
T keluaranO(T x, T y){
	cout << "keluaran overloading " << x << y << endl;
	return (x * y);
}
