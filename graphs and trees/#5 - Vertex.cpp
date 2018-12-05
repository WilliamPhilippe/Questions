#include <bits/stdc++.h>

using namespace std;

vector< vector<int> > grafo;
vector<int> visitados;

void visitar(int consu){
	
	

	for(int i = 0; i < grafo[consu].size(); i++){
		if( visitados[ grafo[consu][i] ] == 1) continue;
		visitados[ grafo[consu][i] ] = 1;

		visitar( grafo[consu][i] );
	}
}

int main(){

while(1){

	int n_vertex;
	cin >> n_vertex;
	if(n_vertex == 0) break;

	int v_ini, vs;
	grafo.clear();
	grafo.resize(n_vertex + 1);

	while(1){
		cin >> v_ini; if(v_ini == 0) break;
		while(1){
			cin >> vs; if(vs == 0) break;
			grafo[v_ini].push_back(vs);
		}
	}

	int n_c, consu;
	cin >> n_c;
	int n_desable;
	while(n_c--){
		cin >> consu;

		visitados.assign(n_vertex + 1, 0);

		visitar(consu);

		n_desable = n_vertex;

		for(int i = 1; i < visitados.size(); i++){
			if(visitados[i]) --n_desable;
		}
		cout << n_desable;
		
		for(int i = 1; i < visitados.size(); i++){
			if( !visitados[i] ) cout << ' ' << i;
		}
		cout << endl;
	}

}

	return 0;
}
