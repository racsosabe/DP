#include<bits/stdc++.h>
using namespace::std;

const int N = 20;

int n;
double v[N][N];
double memo[N][1<<N];
bool vis[N][1<<N];

double DP(int last, int bitmask){
	if(bitmask+1 == int(1<<n)) return 1.0; // Caso final
	if(vis[last][bitmask]) return memo[last][bitmask]; // Respuesta ya calculada
	double ans = 0.0; // Minimo posible
	if(last == 0){ // Caso 1
		for(int i=0; i<n; i++){
			if((bitmask>>i)&1) continue; // Ignorar los que ya se tomaron
			ans = max(ans,1.0*v[last][i]*DP(last,bitmask|int(1<<i)));
		}
	}
	else{ // Caso 2
		for(int i=0; i<n; i++){
			if((bitmask>>i)&1) continue; // Ignorar los que ya se tomaron
			if(i == 0){
				ans = max(ans,1.0*v[i][last]*DP(i,bitmask|int(1<<i))); // Subcaso 1
			}
			else{
				double carry = 1.0*v[last][i]*DP(last,bitmask|int(1<<i));
				carry += 1.0*v[i][last]*DP(i,bitmask|int(1<<i));
				ans = max(ans,carry);
			}
		}
	}
	vis[last][bitmask] = true; // Estado visitado
	return memo[last][bitmask] = ans; // Almacenar y devolver respuesta
}

int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> v[i][j];
		}
	}
	double ans = 0.0;
	for(int i=0; i<n; i++){
			ans = max(ans,DP(i,1<<i));
	}
	cout << setprecision(10) << fixed << ans << endl;
	return 0;
}