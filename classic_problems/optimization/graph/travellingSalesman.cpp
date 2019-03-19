#include<bits/stdc++.h>
using namespace::std;

const int N = 20;

int n;
int d[N][N];
bool vis[N][(1<<N)+2];
int memo[N][(1<<N)+2];

int TSP(int pos, int bitmask){
	if(bitmask+1 == (int)(1<<n)) return d[pos][0]; // Todos los nodos fueron visitados
	if(vis[pos][bitmask]) return memo[pos][bitmask]; // Respuesta ya calculada
	int ans = INT_MAX; // Inicializar un valor contradictorio a la optimizacion
	for(int next = 0; next < n; next++){
		if(next!=pos && int(bitmask&(int)(1<<next))==0)
			ans = min(ans,d[pos][next] + TSP(next,bitmask|(1<<next))); // Minizamos
	}
	vis[pos][bitmask] = true;
	return memo[pos][bitmask] = ans; // Almacenar y devolver respuesta
}

int main(){
	cin >> n;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++) cin >> d[i][j];
	cout << "Travelling Salesman = " << TSP(0,1) << endl; // Ciudad inicial: 1	
	return 0;
}
