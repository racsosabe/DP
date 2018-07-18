#include<bits/stdc++.h>
using namespace::std;

const int N = 1000005;

int n;
int A[N];
int finalesLIS[N];

int lb(int lo, int hi, int x){
	while(lo < hi){
		int mi = lo + (hi-lo)/2; // Punto medio (Lower bound)
		if(finalesLIS[mi] < x) lo = mi+1; // Transicion de aumento
		else hi = mi; // Transicion de estabilidad
	}
	return lo; // Devolvemos el indice del elemento lower_bound
}

int LIS(){
	int len = 1; // Trivial
	finalesLIS[0] = A[0]; // Trivial
	for(int i=1; i<n; i++){
		if(A[i] < finalesLIS[0]) finalesLIS[0] = A[i]; // Reemplaza el primero
		else if(A[i] > finalesLIS[len-1]) finalesLIS[len++] = A[i]; // Adjuntamos al LIS actual
		else finalesLIS[lb(0,len-1,A[i])] = A[i]; // Reemplaza en el punto
	}
	return len;
}

int main(){
	cin >> n;
	for(int i=0; i<n; i++) cin >> A[i];
	cout << "Longest Increasing Subsequence = " << LIS() << endl;
	return 0;
}
