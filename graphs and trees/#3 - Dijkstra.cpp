#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> par;

int distancia[15000];
int processado[15000];

vector< par > vizinhos[15000];

void bfs(int x){
    
    distancia[x] = 0;

    priority_queue< par, vector<par>, greater<par> > fila;
    fila.push(par(distancia[x], x));

    while(true){

        int davez = -1;

        while(!fila.empty()){

            int atual = fila.top().second;
            fila.pop();

            if( !processado[atual] ){
                davez = atual;
                break;
            }

        }

        if(davez == -1) return;

        for(int i = 0; i < (int) vizinhos[davez].size(); i++){

            int dist = vizinhos[davez][i].first;
            int atual = vizinhos[davez][i].second;

            if( distancia[atual] > distancia[davez] + dist ){

                distancia[atual] = distancia[davez] + dist;
                fila.push( par( distancia[atual], atual ) );

            }
        }

    }


}

int main(){

    int t = 1;
    
    

    int n, m, u, v, d;
    cin >> n >> m;
        
    for(int i = 0; i <= n + 5; i++){
        distancia[i] = INT_MAX;
        processado[i] = 0;
    }

    for(int i = 0; i < m; i++){
        cin >> u >> v >> d;
            
        vizinhos[u].push_back( par(d, v) );
        vizinhos[v].push_back( par(d, u) );
    }

    bfs(1);      

    cout << distancia[n] << endl;

    return 0;
}