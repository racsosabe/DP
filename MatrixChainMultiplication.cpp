#include<bits/stdc++.h>
using namespace::std;

const int N = 505;

int n;
int p[N], MCM[N][N];

int mcm(int i, int j){
	if(i == j) return 0; // Una sola matriz. Costo 0
	if(MCM[i][j]!=-1) return MCM[i][j];
	int ans = INT_MAX;
	for(int k=i+1; k<=j; k++)
		ans = min(ans,mcm(i,k-1)+mcm(k,j)+p[i]*p[k]*p[j+1]);
	return MCM[i][j] = ans;
}

int main(){
	memset(MCM,-1,sizeof MCM); // 
	cin >> n;
	for(int i=0; i<=n; i++) cin >> p[i];
	cout << "Matrix Chain Multiplication = " << mcm(0,n-1) << endl;
	return 0;
}
