#include<bits/stdc++.h>
using namespace::std;

const int N = 20;

int len;
bool can;
vector<int> v;
long long ac[N];
bool vis[N][2];
long long memo[N][2];


long long DP(int pos, bool menor){
	if(pos >= (len+1)/2){ 
		// Caso base
		return menor or can;
	}
	if(vis[pos][menor]) return memo[pos][menor];
	long long ans = 0;
	if(menor){
		// Caso 1
		ans += 10*DP(pos+1,1);
	}
	else{
		// Caso 2
		for(int i=0; i<=v[pos]; i++){
			ans += DP(pos+1,i<v[pos]);
		}
	}
	// Marcamos estado como visitado
	vis[pos][menor] = true;
	// Almacenamos y devolvemos respuesta
	return memo[pos][menor] = ans;
}

// Verifica que n sea palindromo
bool check(){
	for(int i=0; i<=len/2; i++){
		if(v[i]!=v[len-1-i]) return 0;
	}
	return true;
}

// Verifica si el prefijo de n
// es menor que el sufijo restante
bool PreffixLess(){
	// Iterador para prefijo
	int pos1 = len/2-1;
	// Iterador para sufijo
	int pos2= len&1?pos1+2:pos1+1;
	while(pos1 >= 0 and pos2 < len and v[pos1] == v[pos2]){
		pos1--;
		pos2++;
	}
	// Minimo lexicografico o devolver falso
	if(pos1 < 0) return false;
	return v[pos1] < v[pos2];
}

long long f(long long n){
	if(n == 0) return 0;
	if(n < 10) return n+1;
	// Transformamos n
	// a vector
	v.clear();
	while(n){
		v.push_back(n%10);
		n /= 10;
	}
	reverse(v.begin(),v.end());
	len = v.size();
	memset(vis,0,sizeof vis);
	// Verificar si el prefijo
	// Revertido es menor que el
	// Sufijo
	can = PreffixLess();
	// Ans inicializado en 
	// ac[len-1] por definicion
	// de ac
	long long ans = ac[len-1];
	// Agregamos los palindromos 
	// que empiecen en i
	// para todo i entre 1 y
	// v[0]
	for(int i=1; i<=v[0]; i++){
		ans += DP(1,i<v[0]);
	}
	// Agregamos a n si es palindromo
	ans += check();
	return ans;
}

void init(){
	ac[0] = 0;
	ac[1] = 9;
	ac[2] = 9;
	// Preprocesamos ac
	// Primer valor ac[i] = Q[i]
	for(int i=3; i<=18; i+=2){
		ac[i] = ac[i+1] = 10LL*ac[i-2];
	}
	// Segundo valor ac[i] = suma de Qs
	for(int i=1; i<=18; i++){
		ac[i] += ac[i-1];
	}
	// Valor final ac[i] = 1 + suma de Qs
	for(int i=1; i<=18; i++){
		ac[i]++;
	}
}

int main(){
	init();
	long long n;
	cin >> n;
	cout << f(n) << endl;
	return 0;
}
