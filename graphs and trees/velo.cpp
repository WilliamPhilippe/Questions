#include <bits/stdc++.h>
using namespace std;

//NAO CONCLUÍDA

typedef tuple <int, int, int> tres;
typedef pair<int, int> par;

vector< par > vizinos[502];
int process[602][3];
int distancia[602][3];

void zerar(int n){
	for(int i = 0; i < n + 5; i++){
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

		//cout << "next >" << next << " estado> " << estado << endl;

		for(int i = 0; i < vizinos[next].size(); i++){

			int outro = vizinos[next][i].first;
			int new_est = ( distancia[next][estado] + 1 )%3;
			int new_dist = distancia[next][estado] + 1;
			int time = vizinos[next][i].second;

			if( distancia[outro][new_est] > new_dist ){

				if(time && !estado ){
					//cout << next << " outro:" << outro << " new_est:" << new_est << " new_dist:" << new_dist << " time:" << time << " 1" << endl;
					distancia[outro][new_est] = new_dist;
					fila.push( tres(outro, new_dist, new_est) );
				}
				else if( !time && estado){
					//cout << next << " outro:" << outro << " new_est:" << new_est << " new_dist:" << new_dist << " time:" << time << " 2" << endl;
					distancia[outro][new_est] = new_dist;
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
	distancia[e][0] = 0; distancia[e][1] = 0; distancia[e][2] = 0;

	int a, b, t;

	for(int i = 0; i < m; i++){
		cin >> a >> b >> t;
		vizinos[a].push_back( par(b, t) );
	}

	dijkstra(e);

	cout << min( distancia[s][2], min(distancia[s][1], distancia[s][0])  ) << endl;
}