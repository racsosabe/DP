#include<bits/stdc++.h>
using namespace::std;

const int N = 10005;

int n, l;
int p[N], memo[N];

int RodCut(int len){
	if(len == 0 ) return 0; // l = 0 -> p = 0
	if(memo[len]!=-1) return memo[len]; // Respuesta ya calculada
	int ans = 0; // Inicializar con un valor contradictorio a la optimizacion
	for(int i=1; i<=len; i++)
		ans = max(ans,p[i]+RodCut(len-i)); // Maximizar el valor
	return memo[len] = ans;
}

int main(){
	memset(memo,-1,sizeof memo); // Inicializar todo a -1 (No visitado)
	p[0] = 0;
	cin >> n;
	for(int i=1; i<=n; i++) cin >> p[i];
	cin >> l;
	cout << "Rod Cutting = " << RodCut(l) << endl;
	return 0;
}
