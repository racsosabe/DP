#include<bits/stdc++.h>
using namespace::std;

const int N = 100000+5;

int n;
vector<int> G[N];
int memo[N][3];
bool vis[N][3];

int DP(int u, int tomo, int parent){
	if(vis[u][tomo]) return memo[u][tomo];
	int ans = 0;
	if(tomo){ // Tomare el nodo u
		ans += 1; // Cuento el nodo u
		for(int i=0; i<G[u].size(); i++){
			int v = G[u][i];
			if(v!=parent){ // Condicion para pseudo - DAG
				ans += min(DP(v,0,u),DP(v,1,u)); // Minimizo
			}
		}
	}
	else{
		for(int i=0; i<G[u].size(); i++){
			int v = G[u][i];
			if(v!=parent){ // Condicion para pseudo - DAG
				ans += DP(v,1,u); // Unica opcion
			}
		}
	}
	vis[u][tomo] = true;
	return memo[u][tomo] = ans;
}

int main(){
	int u,v;
	cin >> n;
	for(int i=0; i<n-1; i++){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);	
	}
	cout << "El Minimum Vertex Cover del arbol es " << min(DP(1,0,0),DP(1,1,0)) << endl;
	return 0;
}
