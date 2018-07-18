#include<bits/stdc++.h>
using namespace::std;

const int N = 1000000+5;

int n;
long long F[N];

long long f(int n){
	if(n == 1 or n == 2) return 1; // Casos base
	if(F[n]!=0) return F[n]; // Valor ya calculado, devolvemos respuesta
	if(n&1){ // Si n es impar
		int k = (n+1)/2;
		return F[n] = f(k)*f(k) + f(k-1)*f(k-1);
	}
	else{
		int k = n/2;
		return F[n] = (2*f(k-1)+f(k))*f(k);
	}
}

int main(){
	cin >> n;
	cout << "Numero de Fibonacci (" << n << ") = " << f(n) << endl;
	return 0;
}
