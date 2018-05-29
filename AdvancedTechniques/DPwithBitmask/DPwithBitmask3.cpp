#include<bits/stdc++.h>
using namespace::std;

const int N = 105;
const int MAX = 60;

int n;
int a[N];
const int p = 17;
int primos[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59};
int B[MAX];
int memo[N][(1<<p)+2];
bool vis[N][(1<<p)+2];
int padre[N][(1<<p)+2];
int eleccion[N][(1<<p)+2];

int DP(int pos, int bm){
	if(pos == n) return 0; // Caso de salida
	if(vis[pos][bm]) return memo[pos][bm]; // Respuesta ya calculada
	int ans = INT_MAX; // Maximo posible
	for(int k=1; k<MAX; k++){
		if(int(B[k]&bm)!=0) continue;
		int candidato = abs(a[pos]-k)+DP(pos+1,bm|B[k]); // Calcular
		if(candidato < ans){ // Minimizamos
			ans = candidato; // Asignamos valor
			padre[pos][bm] = bm|B[k]; // Asignamos padre
			eleccion[pos][bm] = k; // Asignamos eleccion
		}
	}
	vis[pos][bm] = true; // Estado visitado
	return memo[pos][bm] = ans; // Almacenar y devolver respuesta
}

int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> a[i];
	}
	for(int i=2; i<MAX; i++){ // Preprocesamiento de cada valor
		for(int k=0; k<p; k++){ // Prueba con primos
			if(i%primos[k]==0){ // Factor presente
				B[i] |= int(1<<k); // Prender bit
			}
		}
	}
	int ans = DP(0,0); // Calcular respuesta y procesar
	int b_act = 0; // Valor inicial de bm
	for(int i=0; i<n; i++){ // Iteracion a traves de estados
		int nextb = padre[i][b_act]; // Siguiente bm
		int usado = eleccion[i][b_act]; // Eleccion
		printf("%d ",usado); // Imprimimos
		b_act = nextb; // Asignamos el nuevo valor
	}
	puts("");
	return 0;
}