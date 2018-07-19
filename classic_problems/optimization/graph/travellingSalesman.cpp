/**
 *	Traveling Salesman Problem
 * 	@author {v\'ictor racs\'o}
 *	@overview Minimum Hamiltonian Path
 *	@params {int} number of vertices 
 *	@params {array} adjacent matrix of the Graph 
 */


#include<bits/stdc++.h>
using namespace::std;

const int MAX_N = 20;
const int OFF_SET = 2;
const int inf = INT_MAX;
int n;
int d[MAX_N][MAX_N];
int memo[MAX_N][(1<<MAX_N)+OFF_SET];
int completeSet;
int nullSet = 0;

int TSP(int pos, int bitmask) {
	if(bitmask == completeSet) return d[pos][0]; // Todos los nodos fueron visitados
	if(~memo[pos][bitmask]) return memo[pos][bitmask]; // Respuesta ya calculada
	int ans = inf; // Inicializar un valor contradictorio a la optimizacion
	for (int next = 0; next < n; next++) {
		if(next!=pos and (bitmask&(1<<next)) == nullSet) {
			ans = min(ans, d[pos][next] + TSP(next,bitmask|(1<<next))); //Minizar el valor
		}
	}
	return memo[pos][bitmask] = ans; // Almacenar y devolver respuesta
}

int main()
{
	//input
	cin >> n;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin >> d[i][j];
		}
	}

	//Traveling salesman problem
	completeSet = (1<<n)-1;
	memset(memo,-1,sizeof memo); // iniciar a -1 (No Visitado)
	cout << "Travelling Salesman = " << TSP(0,1) << endl; // Ciudad inicial: 1	
	return 0;
}
