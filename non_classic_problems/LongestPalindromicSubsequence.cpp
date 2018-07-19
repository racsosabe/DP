#include<bits/stdc++.h>
using namespace::std;

const int N = 10005;

int n;
string x;
int LoPS[N][N];

int LPS(int i, int j){
	if(i == j) return 1; // Caso base 1: Un solo caracter
	if(i+1 == j){
		if(x[i] == x[j]) return LoPS[i][j] = 2; // Caso base 2: Dos caracteres iguales 
	}
	if(LoPS[i][j]!=-1) return LoPS[i][j]; // Respuesta ya calculada
	if(x[i] == x[j]) return LoPS[i][j] = 2 + LPS(i+1,j-1); // Coincidencia
	else return LoPS[i][j] = max(LPS(i+1,j),LPS(i,j-1)); // Maximizar el valor
}

int main(){
	memset(LoPS,-1, sizeof LoPS); // Inicializar todo a -1 (No Visitado)
	cin >> x;
	n = x.size();
	cout << "Longest Palindromic Subsequence = " << LPS(0,n-1) << endl;	
	return 0;
}
