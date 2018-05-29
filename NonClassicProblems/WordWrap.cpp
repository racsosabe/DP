#include<bits/stdc++.h>
using namespace::std;

const int N = 10000+5;
const long long inf = 1LL<<42; // Representacion de infinito, 2^42

int n,m;
int v[N];
int espacios[N][N];
long long costo_linea[N][N];
long long costo[N];

long long f(int x){
	return 1LL*x*x*x; // A veces se usa el cuadrado
}


int main(){
	cin >> n >> m;
	for(int i=1; i<=n; i++) cin >> v[i];
	for(int i=1; i<=n; i++){
		espacios[i][i] = m - v[i]; // Caso base: solo esta palabra
		for(int j=i+1; j<=n; j++){
			espacios[i][j] = espacios[i][j-1] - v[j] - 1; // Agregamos las palabras de posicion [i..j] y un espacio por cada una
		}
	}
	for(int i=1; i<=n; i++){
		for(int j=i; j<=n; j++){
			if(espacios[i][j] < 0){ // Faltan espacios, asi que no es valido
				costo_linea[i][j] = inf;
			}
			else if(j == n and espacios[i][j] >= 0){
				costo_linea[i][j] = 0; // Es ultima linea y sobran espacios, por condicion del problema no se consideran
			}
			else{
				costo_linea[i][j] = f(espacios[i][j]); // Asignamos el costo de manera directa
			}
		}
	}
	costo[0] = 0;
	for(int j=1; j<=n; j++){
		costo[j] = inf;
		for(int i=1; i<=j; i++){
			if(costo[i-1]!=inf and costo_linea[i][j]!=inf){ // Candidato valido
				costo[j] = min(costo[j],costo[i-1]+costo_linea[i][j]); // Minimizamos el costo hasta la posicion actual
			}
		}
	}
	cout << "El costo minimo es " << costo[n] << endl;
	return 0;
}
