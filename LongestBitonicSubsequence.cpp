#include<bits/stdc++.h>
using namespace::std;

const int N = 10005;

int n;
int A[N];
int LIS[N], LDS[N];

int main(){
	cin >> n;
	for(int i=0; i<n; i++) cin >> A[i];
	LIS[0] = 1; // Trivial
	for(int i=1; i<n; i++){
		LIS[i] = 1; // Trivial
		for(int j=0; j<i; j++){ 
			if(A[j] < A[i]) // Candidato
				LIS[i] = max(LIS[i],LIS[j]+1); // Maximizar el valor
		}
	}
	LDS[n-1] = 1; // Trivial
	for(int i=n-2; i>=0; i--){
		LDS[i] = 1;
		for(int j=n-1; j>i; j--){
			if(A[i] > A[j]) // Candidato
				LDS[i] = max(LDS[i],LDS[j]+1); // Maximizar el valor
			
		}
	}
	int LonLBS = 1; // Trivial
	for(int i=0; i<n; i++)
		LonLBS = max(LonLBS,LIS[i]+LDS[i]-1); // Maximizar el valor
	cout << "Longest Bitonic Subsequence = " << LonLBS << endl;
	return 0;
}
