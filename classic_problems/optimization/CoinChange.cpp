#include<bits/stdc++.h>
using namespace::std;

const int N = 1000005;

int n, V;
int v[N], memo[N];

int cambio(int valor){
	if(valor == 0) return 0; // No se usan monedas para el valor 0
	if(valor < 0) return (1<<30); // Caso absurdo
	if(memo[valor]!=-1) return memo[valor]; // Respuesta ya calculada
	int ans = INT_MAX; // Inicializar con un valor contradictorio a la optimizacion
	for(int i=0; i<n; i++){
		ans = min(ans,1+cambio(valor-v[i])); // Minimizar el valor
	}
	return memo[valor] = ans; // Almacenar y devolver respuesta
}

int main(){
	memset(memo,-1,sizeof memo); // Inicializar todo a -1 (No Visitado)
	cin >> n;
	for(int i=0; i<n; i++) cin >> v[i];
	cin >> V;
	cout << "Coin Change = " << cambio(V) << endl;
	return 0;
}
