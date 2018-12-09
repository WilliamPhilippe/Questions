#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> par;
vector<par> ruas[510];
int minutos[510];
int process[510];
int s;

void bfs(int in){

	priority_queue < par, vector<par>, greater<par> > fila;
	minutos[in] = -1;
	fila.push( par(minutos[in], in) );

	while(true){

		int act = 1, next;

		while(!fila.empty()){
			next = fila.top().second;
			fila.pop();

			process[next] = 1;
			act = 0;
		}

		if(act) return;

		for(int i = 0; i < ruas[next].size(); i++){

			int min = minutos[next] + 1;
			int atual = ruas[next][i].first;
			int time = ruas[next][i].second;

			if(minutos[atual] > min || (process[atual] && atual != s) ){
				if(time && (min%3 == 0 || min == 0)){
					minutos[atual] = min;
					fila.push( par(minutos[atual], atual) );
				}
				else if(!time && min%3){
					minutos[atual] = min;
					fila.push( par(minutos[atual], atual) );
				}
			}
		}


	}



}

int main(){

	int n, e, m;
	cin >> n >> e >> s >> m;

	int a, b, t;
	for(int i = 0; i < m; i++){
		cin >> a >> b >> t;
		ruas[a].push_back( par(b, t) );
	}

	for(int i = 0; i < n + 5; i++){
		minutos[i] = INT_MAX;
		process[i] = 0;
	}

	bfs(e);

	cout << minutos[s] + 1;

	return 0;
}