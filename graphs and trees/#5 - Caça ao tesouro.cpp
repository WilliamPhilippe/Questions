#include <bits/stdc++.h>
using namespace std;

typedef vector< tuple<int, int, int> > my_vector;
my_vector pistas;
int n, k;
int mapa[101][101];
int steps[101][101];

void startIt(int sett){ 
	for(int i = 0; i < n; i++){ 
		for(int j = 0; j < n; j++){
			if(sett == 1) mapa[i][j] = 0;
			if(sett == 1 || sett == 2) steps[i][j] = INT_MAX;
		} 
	}
}

void printIt(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << mapa[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;
}

void backtracking( int l, int c, int d, int passos){
	
	if(l >= n || l < 0 || c >= n || c < 0) return;
	if(passos >= steps[l][c]) return;
	else steps[l][c] = passos;
	if(passos > d) return;

	backtracking(l, c - 1, d, passos + 1);
	backtracking(l, c + 1, d, passos + 1);
	backtracking(l - 1, c, d, passos + 1);
	backtracking(l + 1, c, d, passos + 1);
	
}

void setMap(int d){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(steps[i][j] == d) mapa[i][j] ++;
		}
	}
}

void mapear(){
	for(my_vector::const_iterator i = pistas.begin(); i != pistas.end(); ++i){
		backtracking( get<0>(*i), get<1>(*i), get<2>(*i), 0 );
		setMap(get<2>(*i));

		// printIt();
		startIt(2);
	}
}

void verificar(int &linha, int &coluna){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(mapa[i][j] == k && linha == -1) linha = i, coluna = j;
			else if(mapa[i][j] == k){
				linha = -1;
				coluna = -1;
				return;
			}
		}
	}
}

int main(){

	int c, l, d;
	cin >> n >> k;
	startIt(1);

	for(int i = 0; i < k; i++){
		cin >> c >> l >> d;
		pistas.push_back( tuple<int, int, int>(n - 1 - l, c, d) );
	}

	mapear();

	int linha = -1, coluna = -1;
	verificar(linha, coluna);

	if(linha != -1) cout << coluna << " " << n - 1 - linha << endl;
	else cout << "-1 -1\n";

	return 0;	
}


//coluna se mantém, linha >> n - 1 - l é a linha na matriz do C++