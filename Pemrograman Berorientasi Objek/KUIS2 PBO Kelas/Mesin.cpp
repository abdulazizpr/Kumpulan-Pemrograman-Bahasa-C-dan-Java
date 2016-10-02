template <class A,class B>
void tulis(A arr,B n,B m){
	int j = 0;
	for(int i=0;i<n;i++){
		j++;
		cout << arr[i] << ends;
		if(j%m==0){
			cout << endl;
		}
	}
}