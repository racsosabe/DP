#include<bits/stdc++.h>
using namespace::std;

const int N = 10000+5;
const int K = 300+5;

int n,t;
int p[K];
int p_length = 0;
int max_times[K];
string primos[K];
bool compuesto[K];
int primos_length = 0;
string memo[K][N][15];

string to_s(int x){ // Funcion para convertir de entero a cadena
	string ans = "";
	while(x){
		ans = ans + char(x%10 + '0');
		x /= 10;
	}
	reverse(ans.begin(),ans.end());
	return ans;
}

int to_i(string s){ // Funcion para convertir de cadena a entero
	int x = 0;
	for(int i=0; i<s.size(); i++){
		x = (x<<1) + (x<<3) + s[i]-'0';
	}
	return x;
}

void criba(){ // Criba para obtener primos y ordenarlos
	for(int i=2; i*i<=K; i++){
		if(!compuesto[i]){
			for(int j=i*i; j<K; j+=i) compuesto[j] = true;
		}
	}
	for(int i=2; i<=300; i++){
		if(!compuesto[i]){
			primos[primos_length++] = to_s(i);
		}
	}
	sort(primos,primos+primos_length);
	for(int i=0; i<primos_length; i++){
		if(primos[i]=="2") max_times[i] = 1;
		else max_times[i] = 2;
		p[p_length++] = to_i(primos[i]);
	}
}

string f(string s, int pos, int times){ // Concatenacion
	if(s == ""){
		s = primos[pos];
		for(int i=0; i<times-1; i++){
			s = s + '+' + primos[pos];
		}
	}
	else{
		for(int i=0; i<times; i++){
			s = s + '+' + primos[pos];
		}
	}
	return s;
}

void init(){
	for(int i=0; i<N; i++){
		for(int j=0; j<15; j++) memo[0][i][j] = "*"; // Imposible por ahora
	}
	memo[0][0][0] = ""; // Caso base
	for(int i=0; i<primos_length; i++){ // Casos triviales, primera aparicion
		for(int times=1; times<=max_times[i]; times++){
			string candidate = primos[i];
			for(int append=0; append<times-1; append++){
				candidate = candidate + '+' + primos[i];
			}
			memo[i][p[i]*times][times] = candidate;
		}
	}
	// Armamos la tabla memo para nuestro DP Iterativo
	for(int pos=1; pos<primos_length; pos++){ // Posicion
		for(int val=0; val<N; val++){ // Valor
			for(int used=0; used<15; used++){ // Cantidad usada
				string act = memo[pos-1][val][used];
				for(int times=1; times<=max_times[pos]; times++){
					// Solo si es posible
					if(times <= used and val >= times*p[pos]){
						int lval = val - times*p[pos];
						int lused = used-times;
						string candidate = memo[pos-1][lval][lused];
						if(candidate != "*"){ // Si es valido
							candidate = f(candidate,pos,times);
							if(act == "*"){
								act = candidate;
							}
							else if(candidate < act){
								act = candidate;
							}
						}
					}
				}
				memo[pos][val][used] = act;
			}
		}
	}
}

int main(){
	criba(); // Inicializamos los datos
	init(); // Armamos la tabla del DP
	int caso = 1;
	while(scanf("%d %d",&n,&t) == 2 and n+t){
		string a = memo[primos_length-1][n][t]; // Consulta en O(1)
		printf("CASE %d:\n",caso++);
		if(a == "*") puts("No Solution.");
		else printf("%s\n",a.c_str());
	}
	return 0;
}