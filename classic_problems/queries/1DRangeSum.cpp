/**
 * kadane algorithm
 * @overview maximum 1D range sum	
 * @author {victor racs\'o}
 * @params {int} N: number of elements
 * @params {array} A: array int  
 */

#include<bits/stdc++.h>
using namespace::std;
const int MAX_N = 1e6;
const int OFF_SET = 2;
const int SIZE = MAX_N + OFF_SET;
const int inf = INT_MAX;

int N;
int A[SIZE];

int main()
{

	//input
	cin >> N;
	for (int i=0; i<N; i++) {
		 cin >> A[i];
	}


	//kadane algorithm
	int sum = 0;
	int ans = -inf; // inicializacion importante 
	for (int i=0; i<N; i++) { // O(n)
		
		// dp[i] = A[i] + max(dp[i-1], 0)  
		sum = A[i] + max(0, sum);

		// ans = max dp[i]
		ans = max(ans, sum);
	}

	cout << "maximum 1D range sum = " << ans << endl;

	return 0;
}
