#include<bits/stdc++.h>
using namespace::std;

const int N = 10005;
const int inf = 1<<20;

int n;
string x;
bool vis[N][N];
int P[N][N]; // Se modificara luego
int memo[N][N];

void init(){
	for(int i=0; i<n; i++) P[i][i] = 1; // Un solo caracter es palindromo
	for(int L=2; L<n; L++){ // Longitud de la cadena a evaluar
		for(int i=0; i<n-L+1; i++){ // Inicio de la cadena a evaluar
			if(L == 2) P[i][i+L-1] = (x[i] == x[i+L-1]);
			else P[i][i+L-1] = (x[i] == x[i+L-1]) && P[i+1][i+L-2];
		}
	}
}

int MPP(int i, int j){
	if(i == j) return memo[i][j] = 0; // UN solo caracter es palindromo
	if(P[i][j]) return memo[i][j] = 0; // Es palindromo
	if(vis[i][j]) return memo[i][j]; // Respuesta ya calculada
	int ans = inf;
	for(int k=i; k<j; k++){
		ans = min(ans,MPP(i,k) + MPP(k+1,j) + 1); // Minimizar el valor
	}
	vis[i][j] = true;
	return memo[i][j] = ans; // Almacenar y devolver respuesta
}

int main(){
	cin >> x;
	n = x.size();
	init();
	cout << "Minimum Palindrome Partitioning = " << MPP(0,n-1) << endl;
	return 0;
}
