#include <bits/stdc++.h>
using namespace std;

//NAO CONCLUÍDA

typedef tuple <int, int, int> tres;
typedef pair<int, int> par;

vector< par > vizinos[502];
int process[502][3];
int distancia[502][3];

void zerar(int n){
	for(int i = 0; i < n; i++){
		process[i][0] = 0; process[i][1] = 0; process[i][2] = 0;
		distancia[i][0] = INT_MAX; distancia[i][1] = INT_MAX; distancia[i][2] = INT_MAX;
	}
}

void dijkstra(int S){

	queue < tres > fila;
	fila.push( tres(S, distancia[S][0], 0) );

	while(true){

		int act = 1;
		int next, estado;

		while(!fila.empty()){

			tres aux = fila.front(); fila.pop();
			next = get<0>(aux);
			estado = get<2>(aux);

			if(!process[next][estado]){
				act = 0;
				process[next][estado] = 1;
				break;
			}			
		}

		if(act) return;

		for(int i = 0; i < vizinos[next].size(); i++){

			int outro = vizinos[next][i].first;
			int new_dist = distancia[next][estado] + 1;
			int new_est = new_dist%3;
			int time = vizinos[next][i].second;

			if( distancia[outro][new_est] > new_dist ){

				if(time && !new_est ){
					distancia[outro][estado] = new_dist;
					fila.push( tres(outro, new_dist, new_est) );
				}
				else if( !time && new_est){
					distancia[outro][estado] = new_dist;
					fila.push( tres(outro, new_dist, new_est) );
				}

			}


		}


	}


}

int main(){

	int n, e, s, m;

	cin >> n >> e >> s >> m;

	zerar(n + 5);
	distancia[e][0] = -1; distancia[e][1] = -1; distancia[e][2] = -1;

	int a, b, t;

	for(int i = 0; i < m; i++){
		cin >> a >> b >> t;
		vizinos[a].push_back( par(b, t) );
	}

	dijkstra(e);

	cout << distancia[s][0] << endl;
	cout << distancia[s][1] << endl;
	cout << distancia[s][2] << endl;
}