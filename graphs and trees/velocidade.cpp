#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> par;

vector<par> vertex[500];

int sol = INT_MAX;

void dfs(int no, int s, int min){

	if(no == s){
		if(sol > min) sol = min;
		return;
	}

	for(int i = 0; i < vertex[no].size(); i++){

		if( vertex[no][i].second == 0 ){
			if(min%3) dfs( vertex[no][i].first, s,  min + 1);
		}
		else{
			if(min == 0 || min%3 == 0){
				dfs( vertex[no][i].first, s,  min + 1);
			}
		}

	}


}

int main(){

	int n, e, s, m;
	cin >> n >> e >> s >> m;

	for(int i = 0; i < m; i++){
		int a, b, t;
		cin >> a >> b >> t;

		vertex[a].push_back( par(b, t) );
	}

	dfs(e, s, 0);

	cout << sol << endl;



	return 0;
}