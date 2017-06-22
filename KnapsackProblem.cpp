#include<bits/stdc++.h>
using namespace::std;

const int N = 10005;

int n, S;
int KS[N][N];
int v[N], w[N];

int knap(int pos, int capacidad){
	if(pos == -1 || capacidad == 0) return 0; // No hay elemento o espacio restante
	if(KS[pos][capacidad]!=-1) return KS[pos][capacidad];
	int ans;
	if(w[pos] > capacidad) ans = knap(pos-1,capacidad); // Es imposible tomar el elemento
	else ans = max(knap(pos-1,capacidad),knap(pos-1,capacidad-w[pos])+v[pos]);
	return KS[pos][capacidad] = ans;
}

int main(){
	memset(KS,-1,sizeof KS);
	cin >> n;
	for(int i=0; i<n; i++) cin >> v[i] >> w[i];
	cin >> S;
	cout << "Knapsack Problem = " << knap(n,S) << endl;
	return 0;
}
