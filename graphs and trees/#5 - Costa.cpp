#include <bits/stdc++.h>

using namespace std;

int l,c;


int verify(char mapa[1000][1000], int i, int j){
	if(mapa[i][j] == '.') return 0;
	if(i == 0 || j == 0 || j == c - 1 || i == l - 1) return 1;
	if( (i - 1) >= 0 && mapa[i - 1][j] == '.' ) return 1;
	if( (j - 1) >= 0 && mapa[i][j - 1] == '.' ) return 1;
	if( (i + 1) < l && mapa[i + 1][j] == '.' ) return 1;
	if( (j + 1) < c && mapa[i][j + 1] == '.' ) return 1;
	return 0;
}

int main(){

	
	cin >> l >> c;
	char mapa[1000][1000];
	char lixo;
	int count = 0;
	scanf("%c", &lixo);
	vector< pair<int,int> > various;
	for(int i = 0; i < l; i++){
		
		for(int j = 0; j < c; j++){
			scanf("%c", &mapa[i][j]);
			if(mapa[i][j] == '#') various.push_back(make_pair(i, j));
		}
		scanf("%c", &lixo);
	}

	//cout << various[1].first << endl;

	for(int i = 0; i < (int) various.size(); i++){
		count += verify(mapa, various[i].first, various[i].second);
	}

	cout << count;	


	return 0;
}