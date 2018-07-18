#include<bits/stdc++.h>
using namespace::std;

const int N = 10000+5;

int n;
long long memo[N][N];

void Coeficientes(int n){
	for(int i=0; i<=n; i++){
		for(int j=0; j<=i; j++){
			if(j == 0 || j==i) memo[i][j] = 1;
			else memo[i][j] = memo[i-1][j-1] + memo[i-1][j];
		}
	}
}

int main(){
	cin >> n;
	Coeficientes(n);
	cout << "Coeficientes del binomio de grado " << n << ":" << endl;
	for(int i=0; i<=n; i++){
		cout << memo[n][i] << " ";
	}
	puts("");
	return 0;
}
