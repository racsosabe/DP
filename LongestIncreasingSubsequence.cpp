#include<bits/stdc++.h>
using namespace::std;

const int N = 10005;

int n;
int A[N];
int LIS[N];

int main(){
	cin >> n;
	for(int i=0; i<n; i++) cin >> A[i];
	LIS[0] = 1; // Trivial
	int LonLIS = 1; // Valor minimo posible
	for(int i=1; i<n; i++){
		LIS[i] = 1; // Trivial
		for(int j=0; j<i; j++){
			if(A[j] < A[i]) // Candidato
				LIS[i] = max(LIS[i],1+LIS[j]); // Maximizar el valor actual
		}
		LonLIS = max(LonLIS,LIS[i]); // Maximizar el valor total
	}
	cout << "Longest Increasing Subsequence = " << LonLIS << endl;
	return 0;
}
