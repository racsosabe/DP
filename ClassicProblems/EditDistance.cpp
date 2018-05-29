#include<bits/stdc++.h>
using namespace::std;

const int N = 10005;

int n, m;
string x, y;
int ED[N][N];

int min(int a, int b, int c){ return min(a,min(b,c));}

int editD(int i, int j){
	if(i == -1 && j == -1) return 0; // Dos cadenas vacias dan 0
	if(i == -1 || j == -1) return i+j+1; // Solo queda insertar lo restante
	if(ED[i][j]!=-1) return ED[i][j];
	int ans;
	if(x[i] == y[j]) ans = editD(i-1,j-1); // Son iguales, no es necesario nigun cambio
	else ans = 1 + min(editD(i,j-1),editD(i-1,j),editD(i-1,j-1)); // Minimizar el valor
	return ED[i][j] = ans; // Almacenar y devolver respuesta
}

int main(){
	memset(ED,-1, sizeof ED); // Inicializar todo a -1 (No Visitado)
	cin >> x >> y;
	n = x.size();
	m = y.size();
	cout << "Edit Distance = " << editD(n-1,m-1) << endl;
	return 0;
}
