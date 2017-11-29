#include<bits/stdc++.h>
using namespace::std;

int n;

long long F(int n){
	if(n == 1 or n == 2) return 1; // Casos base
	long long a = 1, b = 1, c; // a y b son los valores F_i-1 y F_i-2
	for(int i=3; i<=n; i++){ // Queremos hallar el n-esimo y ya sabemos los dos primeros
		c = a+b;
		a = b;
		b = c;
	}
	return c;
}

int main(){
	cin >> n;
	cout << "Numero de Fibonacci (" << n << ") = " << F(n) << endl;
	return 0;
}
