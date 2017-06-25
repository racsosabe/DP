#include<bits/stdc++.h>
using namespace::std;

const int N = 9;

int n;
int x[2*N], y[2*N];
double memo[1<<(2*N)], d[2*N][2*N];
bool vis[1<<(2*N)];

double dp(int bitmask){
	if(bitmask+1==(int)(1<<(2*n))) return 0.0; // Ya es el ultimo grupo que se forma
	if(vis[bitmask]) return memo[bitmask]; // Respuesta ya calculada
	int m1=0; // Primer elemento de la pareja a formar
	while(bitmask&(int)(1<<m1)) m1++;
	double ans = DBL_MAX;
	for(int m2 = m1+1; m2 < 2*n; m2++){ // Iterar para obtener el segundo elemento
		if(int(bitmask&(int)(1<<m2))==0)
			ans = min(ans,d[m1][m2] + dp(bitmask | (1<<m1) | (1<<m2))); // Minimizar el valor
	}
	vis[bitmask] = true; // Estado visitado
	return memo[bitmask] = ans; // Almacenar y devolver respuesta
}

int main(){
	string name;
	int t = 1;
	while(cin >> n && n!=0){ // Leer los datos hasta el End of File
		memset(vis,0,sizeof vis);
		for(int i=0; i<2*n; i++) cin >> name >> x[i] >> y[i]; // Recibir los datos
		for(int i=0; i<2*n; i++){
			for(int j=0; j<2*n; j++){
				d[i][j] = hypot((x[i]-x[j]),(y[i]-y[j])); // Calcular las distancias
			}
		}
		printf("Case %d: %.2f\n",t++,dp(0));
	}
	return 0;
}