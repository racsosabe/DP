#include<bits/stdc++.h>
using namespace::std;

const int N = 20;

int n;
double v[N][N];
double memo[N][1<<N];
bool vis[N][1<<N];

double DP(int last, int bm){
	if(bm+1 == int(1<<n)) return 1.0; // Caso final
	if(vis[last][bm]) return memo[last][bm]; // Respuesta ya calculada
	double ans = 0.0; // Minimo posible
	if(last == 0){ // Caso 1
		for(int i=0; i<n; i++){
			if((bm>>i)&1) continue; // Ignorar los que ya se tomaron
			ans = max(ans,1.0*v[last][i]*DP(last,bm|int(1<<i)));
		}
	}
	else{ // Caso 2
		for(int i=0; i<n; i++){
			if((bm>>i)&1) continue; // Ignorar los que ya se tomaron
			if(i == 0){
				ans = max(ans,1.0*v[i][last]*DP(i,bm|int(1<<i))); // Subcaso 1
			}
			else{
				double carry = 1.0*v[last][i]*DP(last,bm|int(1<<i));
				carry += 1.0*v[i][last]*DP(i,bm|int(1<<i));
				ans = max(ans,carry);
			}
		}
	}
	vis[last][bm] = true; // Estado visitado
	return memo[last][bm] = ans; // Almacenar y devolver respuesta
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