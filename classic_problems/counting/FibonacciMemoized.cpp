#include<bits/stdc++.h>
using namespace::std;

const int N = 1000000+5;

int n;
long long F[N];

long long f(int n){
	if(F[n]!=0) return F[n]; // Valor ya calculado, devolvemos respuesta
	F[1] = 1; // Caso base
	F[2] = 1; // Caso base
	for(int i=2; i<=n; i++){
		F[i] = F[i-1] + F[i-2]; // Almacenamos los valores de la serie
	}
	return F[n];
}

int main(){
	cin >> n;
	cout << "Numero de Fibonacci (" << n << ") = " << f(n) << endl;
	return 0;
}
