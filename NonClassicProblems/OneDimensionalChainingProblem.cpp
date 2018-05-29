#include<bits/stdc++.h>
using namespace::std;

const int N = 10005;

struct nodo{
	int l; // Limite inferior del intervalo
	int r; // Limite superior del intervalo
	int w; // Peso del intervalo
};

bool menor(nodo a, nodo b){
	if(a.l < b.l) return true;
	if(a.l == b.l) return a.r < b.r;
	return false;
}

int n;
nodo A[N];
int ODCP[N];

int main(){
	cin >> n;
	for(int i=0; i<n; i++) cin >> A[i].l >> A[i].r >> A[i].w;
	sort(A,A+n,menor);
	int SumODCP = -1;
	ODCP[n-1] = A[n-1].w; // Trivial
	for(int i=n-2; i>=0; i--){
		ODCP[i] = A[i].w; // Trivial
		for(int j=n-1; j>i; j--){
			if(A[i].r < A[j].l)
				ODCP[i] = max(ODCP[i],ODCP[j]+A[i].w);
		}
		SumODCP = max(SumODCP,ODCP[i]);
	}
	cout << "One Dimensional Chaining Problem = " << SumODCP << endl;
	return 0;
}
