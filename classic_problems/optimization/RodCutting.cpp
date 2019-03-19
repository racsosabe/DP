#include<bits/stdc++.h>
using namespace::std;

const int N = 10005;

int n, l;
bool vis[N];
int p[N], memo[N];

int RodCut(int len){
	if(len == 0) return 0; // l = 0 -> p = 0
	if(vis[len]) return memo[len]; // Respuesta ya calculada
	int ans = 0; // Inicializar con un valor contradictorio a la optimizacion
	for(int i=1; i<=len; i++)
		ans = max(ans, p[i] + RodCut(len-i)); // Maximizar el valor
	vis[len] = true;
	return memo[len] = ans;
}

int main(){
	p[0] = 0;
	cin >> n;
	for(int i=1; i<=n; i++) cin >> p[i];
	cin >> l;
	cout << "Rod Cutting = " << RodCut(l) << endl;
	return 0;
}
