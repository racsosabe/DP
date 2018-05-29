#include<bits/stdc++.h>
using namespace::std;

const int N = 1000005;

int n;
int A[N];

int main(){
	cin >> n;
	for(int i=0; i<n; i++) cin >> A[i];
	int sum = 0, ans = INT_MIN; // Es importante la inicializacion de ans
	for(int i=0; i<n; i++){ // Procesamiento lineal
		sum += A[i]; // Tomamos, de forma greedy, la suma hasta este punto
		ans = max(ans,sum); // Maximizar el valor del RSQ
		if(sum < 0) sum = 0; // Si se torna negativo reiniciamos el valor de sum
	}
	cout << "Maximum 1D RSQ = " << ans << endl;
	return 0;
}
