#include "Titik.h"

template <class T>
Titik<T>::Titik(){
	/*konstruktor*/
	Titik<T>::x = 0;
	Titik<T>::y = 0;
}

template <class T>
Titik<T>::Titik(int xp,int yp){
	/*konstruktor*/
	Titik<T>::x = xp;
	Titik<T>::y = yp;
}

template <class T>
int Titik<T>::getX(){
	/*mengembalikan nilai x*/
	return Titik<T>::x;
}

template <class T>
void Titik<T>::setX(int xp){
	/*mengeset nilai x*/
	Titik<T>::x = xp;
}

template <class T>
int Titik<T>::getY(){
	/*mengembalikan nilai y*/
	return Titik<T>::y;
}

template <class T>
void Titik<T>::setY(int yp){
	/*mengeset nilai x*/
	Titik<T>::y = yp;
}

template <class T>
Titik<T>::~Titik(){
}
