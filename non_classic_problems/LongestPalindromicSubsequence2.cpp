#include<bits/stdc++.h>
using namespace::std;

const int N = 10005;

int n, m;
string x, y;
bool vis[N][N];
int LoCS[N][N];

int LCS(int i, int j){
	if(i < 0 || j < 0) return 0; // Comparando con cadena vacia
	if(vis[i][j]) return LoCS[i][j]; // Respuesta ya calculada
	vis[i][j] = true;
	if(x[i] == y[j]) return LoCS[i][j] = 1 + LCS(i-1,j-1); // Coincidencia
	else return LoCS[i][j] = max(LCS(i-1,j),LCS(i,j-1)); // Maximizar el valor
}

int main(){
	cin >> x;
	n = x.size();
	y = x;
	reverse(y.begin(),y.end());
	m = y.size();
	cout << "Longest Palindromic Subsequence = " << LCS(n-1,m-1) << endl;
	return 0;
}
