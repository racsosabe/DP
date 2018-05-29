#include<bits/stdc++.h>
using namespace::std;

const int MOD = 1000000007;
const int N = 15;
const int M = 100+5;
const int B = (1<<11)+5;

// Suma modular

int add(long long a, long long b){
	return (a%MOD + MOD + b%MOD + MOD)%MOD;
}

int n,m;
int dn[] = {-1,1};
int memo[M][N][B];
bool vis[M][N][B];

int DP(int pos, int last, int used){
	if(pos >= m){
		// Condicion para que sea hermoso
		return used+1==1<<n;
	}
	if(vis[pos][last][used]) return memo[pos][last][used];
	int ans = used+1 == 1<<n; // El numero ya es hermoso
	for(int k=0; k<2; k++){
		int new_digit = last+dn[k];
		// Verificamos nuevo digito
		if(0 <= new_digit and new_digit < n){
			// Agregamos resultado de asignarlo
			ans = add(ans,DP(pos+1,new_digit,used|1<<new_digit));
		}
	}
	// Marcamos como visitado
	vis[pos][last][used] = true;
	// Almacenamos y devolvemos respuesta
	return memo[pos][last][used] = ans;
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&m);
		// Si m < n no hay numeros posibles
		if(m < n) puts("0");
		else{
			memset(vis,0,sizeof vis);
			int ans = 0;
			for(int i=1; i<n; i++){
				ans = add(ans,DP(1,i,1<<i));
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
