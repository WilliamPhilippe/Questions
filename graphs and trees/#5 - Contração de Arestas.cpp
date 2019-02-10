#include <bits/stdc++.h>
using namespace std;
	
typedef pair<int, int> par;

int dist[10001];
int process[10001];
vector<par> vizinhos[10001];

int main(){

	int n, m, a, b, o;
	char commmand;
	cin >> n >> m;
	
	for(int i = 0; i < m; i++){
		cin >> a >> b;
		if(a != b){
			vizinhos[a].push_back( par(1, b) );
			vizinhos[b].push_back( par(1, a) );
		}
		else vizinhos[a].push_back( par(0, b) );
	}

	scanf("%d\n", &o);
	for(int i = 0; i < 0; i++){
		scanf("%c %d %d\n", &commmand, &a, &b);

		if(commmand == 'c'){
			
		}
		else if(commmand == 'd'){

		}
		else cout << "error";
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < (int) vizinhos[i].size(); j++) cout << vizinhos[i][j].second << " ";
		cout << endl;
	}	



	return 0;
}