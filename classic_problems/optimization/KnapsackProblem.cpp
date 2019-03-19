#include<bits/stdc++.h>
using namespace::std;

const int N = 10005;

int n, S;
bool vis[N][N];
int KS[N][N];
int v[N], w[N];

int knap(int pos, int capacidad){
	if(pos == -1 || capacidad == 0) return 0; // No hay elemento o espacio restante
	if(vis[pos][capacidad]) return KS[pos][capacidad]; // Respuesta ya calculada
	int ans;
	if(w[pos] > capacidad) ans = knap(pos-1,capacidad); // Es imposible tomar el elemento
	else ans = max(knap(pos-1,capacidad),knap(pos-1,capacidad-w[pos]) + v[pos]); // Maximizar el valor
	vis[pos][capacidad] = true;
	return KS[pos][capacidad] = ans;
}

int main(){
	cin >> n;
	for(int i=0; i<n; i++) cin >> v[i] >> w[i];
	cin >> S;
	cout << "Knapsack Problem = " << knap(n,S) << endl;
	return 0;
}
