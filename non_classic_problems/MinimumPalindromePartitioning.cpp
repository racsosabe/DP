#include<bits/stdc++.h>
using namespace::std;

const int N = 10005;
const int inf = 1<<20;

int n;
string x;
bool vis[N][N];
bool vis2[N][N];
int P[N][N]; // Se modificara luego
int memo[N][N];

bool palindromo(int i, int j){
	if(vis[i][j]) return P[i][j]; // Respuesta ya calculada
	vis[i][j] = true;
	for(int k=i; k<=int((i+j)>>1); k++){
		if(x[k]!=x[i+j-k]) return P[i][j] = 0; // Hay un fallo: Falso
	}
	return P[i][j] = 1; // Coincidencia: Verdadero
}

int MPP(int i, int j){
	if(i == j) return memo[i][j] = 0; // Un solo caracter es palindromo
	if(palindromo(i,j)) return memo[i][j] = 0; // Es palindromo
	if(vis2[i][j]) return memo[i][j]; // Respuesta ya calculada
	int ans = inf;
	for(int k=i; k<j; k++){
		ans = min(ans,MPP(i,k) + MPP(k+1,j) + 1); // Minimizar el valor
	}
	vis2[i][j] = true;
	return memo[i][j] = ans; // Almacenar y devolver respuesta
}

int main(){
	cin >> x;
	n = x.size();
	cout << "Minimum Palindrome Partitioning = " << MPP(0,n-1) << endl;
	return 0;
}
