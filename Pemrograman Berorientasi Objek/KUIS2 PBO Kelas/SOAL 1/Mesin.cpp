/*method untuk array of integer*/
void tulis(int arr[],int n,int m){
	int counter = 0;
	for(int i=0;i<n;i++){
		counter++;
		cout << arr[i] << ends;
		if(counter%m==0){
			cout << endl;
		}
	}
}

/*method untuk array of string*/
void tulis(string arr[],int n,int m){
	int counter = 0;
	for(int i=0;i<n;i++){
		counter++;
		cout << arr[i] << ends;
		if(counter%m==0){
			cout << endl;
		}
	}
}

/*method untuk array of double*/
void tulis(double arr[],int n,int m){
	int counter = 0;
	for(int i=0;i<n;i++){
		counter++;
		cout << arr[i] << ends;
		if(counter%m==0){
			cout << endl;
		}
	}
}

/*template untuk semua method*/
template <class A,class B>
void tulis(A arr,B n,B m){
	int counter = 0;
	for(int i=0;i<n;i++){
		counter++;
		cout << arr[i] << ends;
		if(counter%m==0){
			cout << endl;
		}
	}
}