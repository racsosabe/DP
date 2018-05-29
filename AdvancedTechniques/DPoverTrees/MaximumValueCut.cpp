#include<bits/stdc++.h>
using namespace::std;

const int N = int(1<<20)+5;
const int K = 25;

int n, h, k;
int v[N];
long long memo[N][K];
bool vis[N][K];

long long DP(int u, int l){
	if(u > n) return 0; // No es un nodo del arbol
       	if(l == 1 || 2*u > n) return v[u]; // Casos base
	if(vis[u][l]) return memo[u][l];
	long long ans = v[u]; // Caso minimo
	for(int i=1; i<=l-1; i++){
		ans = max(ans,DP(2*u,i)+DP(2*u+1,l-i)); // Maximizamos
	}
	vis[u][l] = true;
	return memo[u][l] = ans;
}

void LeerPreOrden(int pos, int nivel){
	if(nivel == h){
		cin >> v[pos];
		return;
	 }
	cin >> v[pos];
	LeerPreOrden(2*pos,nivel+1);
	LeerPreOrden(2*pos+1,nivel+1);
}

int main(){
	cin >> h >> k;
	n = (1<<(h+1))-1; // Cantidad de nodos en todo el arbol
	LeerPreOrden(1,0);
	cout << "El Corte de Maximo Valor es " << DP(1,k) << endl;
	return 0;
}
