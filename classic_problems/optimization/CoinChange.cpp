#include<bits/stdc++.h>
using namespace::std;

const int N = 105;
const int K = 1000005;
const int inf = 1<<20; // Valor "infinito" pero evitando overflow

int n, V;
bool vis[K];
int v[N], memo[K];

int cambio(int valor){
	if(valor == 0) return 0; // No se usan monedas para el valor 0
	if(valor < 0) return inf; // Caso absurdo
	if(vis[valor]) return memo[valor]; // Respuesta ya calculada
	int ans = inf; // Inicializar con un valor contradictorio a la optimizacion
	for(int i=0; i<n; i++){
		ans = min(ans,1 + cambio(valor-v[i])); // Minimizar el valor
	}
	vis[valor] = true;
	return memo[valor] = ans; // Almacenar y devolver respuesta
}

int main(){
	cin >> n;
	for(int i=0; i<n; i++) cin >> v[i];
	cin >> V;
	cout << "Coin Change = " << cambio(V) << endl;
	return 0;
}
