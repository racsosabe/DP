#include<bits/stdc++.h>
using namespace::std;

const int N = 105;

int n;
int A[N][N];

int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> A[i][j];
			if(i > 0) A[i][j] += A[i-1][j];
			if(j > 0) A[i][j] += A[i][j-1];
			if(i > 0 && j > 0) A[i][j] -= A[i-1][j-1];
		}
	}
	int maxSum = INT_MIN;
	for(int f1=0; f1<n; f1++){
		for(int f2=f1; f2<n; f2++){
			for(int c1=0; c1<n; c1++){
				for(int c2=c1; c2<n; c2++){
					int sumAct = A[f2][c2];
					if(f1 > 0) sumAct -= A[f1-1][c2];
					if(c1 > 0) sumAct -= A[f2][c1-1];
					if(f1 > 0 && c1 > 0) sumAct += A[f1-1][c1-1];
					maxSum = max(maxSum,sumAct);
				}
			}
		}
	}
	cout << "Maximum 2D RSQ = " << maxSum << endl;
	return 0;
}
