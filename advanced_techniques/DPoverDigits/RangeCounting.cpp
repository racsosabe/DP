#include<bits/stdc++.h>
using namespace::std;

const int K = 100+5;

int n;
int k;
int r[15];
vector<int> v;
int memo[10][K][82][2];
bool vis[10][K][82][2];

int DP(int pos, int res, int sum, bool menor){
	if(pos == n) return res==0 and sum == 0; // Caso base
	if(vis[pos][res][sum][menor]) return memo[pos][res][sum][menor];
	int ans = 0;
	if(menor){ // Caso menor = 1
		for(int i=0; i<10; i++){
			int new_res = (res+i*r[n-1-pos])%k;
			int new_sum = (sum+i)%k;
			ans += DP(pos+1,new_res,new_sum,1);
		}

	}
	else{ // Caso menor = 0
		for(int i=0; i<=v[pos]; i++){
			int new_res = (res+i*r[n-1-pos])%k;
			int new_sum = (sum+i)%k;
			bool new_menor = i<v[pos];
			ans += DP(pos+1,new_res,new_sum,new_menor);
		}
	}
	vis[pos][res][sum][menor] = true;
	return memo[pos][res][sum][menor] = ans;
}

int f(int x){ // Funcion de conteo acumulado
	if(x == 0) return 1; // Caso trivial
	// Preprocesamiento necesario para el DP
	v.clear();
	while(x){
		v.push_back(x%10);
		x /= 10;
	}
	reverse(v.begin(),v.end());
	n = v.size();
	memset(vis,0,sizeof vis);
	// Conteo con todos los digitos posibles
	int ans = 0;
	for(int i=0; i<=v[0]; i++){
		ans += DP(1,(i*r[n-1])%k,i%k,i<v[0]);
	}
	return ans;
}

int g(int a, int b){ // Funcion de conteo en rango
	return f(b) - f(a-1);
}


int main(){
	int t;
	scanf("%d",&t);
	int caso = 1;
	int a,b;
	while(t--){
		scanf("%d %d %d",&a,&b,&k);
		if(k > 81){ // Caso descartado, no hay numeros
			printf("Case %d: %d\n",caso++,0);
			continue;
		}
		if(k == 1){ // Caso trivial, todos cumplen
			printf("Case %d: %d\n",caso++,b-a+1);
			continue;
		}
		r[0] = 1;
		for(int i=1; i<10; i++){
			r[i] = (r[i-1]*10)%k; // Inicializamos potencias
		}
		printf("Case %d: %d\n",caso++,g(a,b));
	}
	return 0;
}
