#include<bits/stdc++.h>
using namespace::std;

const int N = 10005;

int n;
string x;
int P[N][N]; // Se modificara luego
int memo[N][N];

bool palindromo(int i, int j){
	if(P[i][j]!=-1) return P[i][j]; // Respuesta ya calculada
	for(int k=i; k<=int((i+j)>>1); k++){
		if(x[k]!=x[i+j-k]) return P[i][j] = 0; // Hay un fallo: Falso
	}
	return P[i][j] = 1; // Coincidencia: Verdadero
}

int MPP(int i, int j){
	if(i == j) return memo[i][j] = 0; // Un solo caracter es palindromo
	if(palindromo(i,j)) return memo[i][j] = 0; // Es palindromo
	if(memo[i][j]!=-1) return memo[i][j]; // Respuesta ya calculada
	int ans = INT_MAX;
	for(int k=i; k<j; k++){
		ans = min(ans,MPP(i,k)+MPP(k+1,j)+1); // Minimizar el valor
	}
	return memo[i][j] = ans; // Almacenar y devolver respuesta
}

int main(){
	memset(P,-1,sizeof P); // Inicializar todo a -1 (No Visitado)
	memset(memo,-1, sizeof memo); // Inicializar todo a -1 (No Visitado)
	cin >> x;
	n = x.size();
	cout << "Minimum Palindrome Partitioning = " << MPP(0,n-1) << endl;
	return 0;
}
