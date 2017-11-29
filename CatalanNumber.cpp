#include<bits/stdc++.h>
using namespace::std;

const int N = 10000+5;

int n;
long long C[N];

void Catalan(int n){
	C[0] = 1; // Caso base
	for(int i=1; i<=n; i++){
		for(int j=0; j<=i-1; j++){
			C[i] += C[j]*C[i-1-j]; // Global, inicializado en 0 por lo que solamente sumamos cada aporte
		}
	}
}

int main(){
	cin >> n;
	Catalan(n);
	cout << "Numero de Catalan (" << n << ") = " << C[n] << endl;
	return 0;
}
