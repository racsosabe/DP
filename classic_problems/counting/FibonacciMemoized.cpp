#include<bits/stdc++.h>
using namespace::std;

const int N = 1000000+5;

int n;
bool vis[N];
long long F[N];

long long f(int n){
	if(n == 1 or n == 2) return 1;
	if(vis[n]) return F[n]; // Valor ya calculado, devolvemos respuesta
	vis[n] = true;
	return F[n] = f(n-1) + f(n-2);
}

int main(){
	cin >> n;
	cout << "Numero de Fibonacci (" << n << ") = " << f(n) << endl;
	return 0;
}
