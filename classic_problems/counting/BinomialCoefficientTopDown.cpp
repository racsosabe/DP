#include<bits/stdc++.h>
using namespace::std;

const int N = 10000+5;

int a, b;
bool vis[N][N];
long long memo[N][N];

long long C(int n, int m){
	if(m == 0 || n==m) return memo[n][m] = 1;
	if(vis[n][m]) return memo[n][m];
	vis[n][m] = true; // Marcamos el estado como visitado
	return memo[n][m] = memo[n][n-m] = C(n-1,m-1) + C(n-1,m);
}

int main(){
	cin >> a >> b;
	cout << "Combinatoria de " << a << " en " << b << ": " << C(a,b) << endl;
	return 0;
}
