#include <bits/stdc++.h>

using namespace std;

vector<int> viz[5000];
int process[5000] = {0};

void bfs(int ori){

	queue<int> fila;
	fila.push(ori);
	cout << ori;
	process[ori] = 1;

	while(true){

		int emp = 0;
		int next = 0;

		while(!fila.empty()){
			next = fila.front();
			fila.pop();

			if(!process[next]){
				emp = 1;
				break;
			}

		}

		if(!emp) return;

		for(int i = viz[next].size() - 1; i >= 0; i--){
			if( !process[viz[next][i]] ) cout << viz[next][i] << endl;
			if( !process[viz[next][i]] ) fila.push( viz[next][i] );
		}

	}

}

int main(){

	int n, ori;

	cin >> n >> ori;

	int a, b;
	while(cin >> a >> b){

		viz[a].push_back(b);

	}

	bfs(ori);

	
	return 0;	
}
