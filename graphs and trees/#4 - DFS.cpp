#include <bits/stdc++.h>

using namespace std;

vector<int> viz[5000];
int process[5000] = {0};
int visitado[5000] = {0};

void dfs(int ori){

	if( visitado[ori] ) return;

	visitado[ori] = 1;
	int ha = 1;
	for(int i = viz[ori].size() - 1; i >= 0; i--){
		int atual = viz[ori][i];

		if( !visitado[atual] ){
			ha = 0;
		
			dfs(atual);
			visitado[atual] = 0;
		}

	}

	if(process[ori] == 0){
		process[ori] = 1;
		cout << ori << endl;
	}

}

int main(){

	int n, ori;

	cin >> n >> ori;

	int a, b;
	while(cin >> a >> b){

		viz[a].push_back(b);

	}

	dfs(ori);

	
	return 0;	
}