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
	int LonLIS = 1;
	for(int i=1; i<n; i++){
		LIS[i] = 1;
		for(int j=0; j<i; j++){
			if(A[j] < A[i])
				LIS[i] = max(LIS[i],1+LIS[j]);
		}
		LonLIS = max(LonLIS,LIS[i]);
	}
	cout << "Longest Increasing Subsequence = " << LonLIS << endl;
	return 0;
}
