#include<bits/stdc++.h>
using namespace::std;

const int N = 505;
const int inf = 1<<20; // Valor "infinito" pero evitando overflow

int n;
bool vis[N][N];
int p[N], MCM[N][N];

int mcm(int i, int j){
	if(i == j) return 0; // Una sola matriz. Costo 0
	if(vis[i][j]) return MCM[i][j]; // Respuesta ya calculada
	int ans = inf; // Inicializar con un valor contradictorio a la optimizacion
	for(int k=i+1; k<=j; k++)
		ans = min(ans,mcm(i,k-1) + mcm(k,j) + p[i]*p[k]*p[j+1]); // Minimizar el valor
	vis[i][j] = true;
	return MCM[i][j] = ans; // Almacenar y devolver respuesta
}

int main(){
	cin >> n;
	for(int i=0; i<=n; i++) cin >> p[i];
	cout << "Matrix Chain Multiplication = " << mcm(0,n-1) << endl;
	return 0;
}
