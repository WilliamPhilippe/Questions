#include	 <bits/stdc++.h>
using namespace std;

char matrix[26][26];
bool access[26][26];

void startIt(){
	for(int i = 0; i < 26; i++){
		for(int j = 0; j < 26; j++){
			access[i][j] = 0;
		}
	}
}

void bt(int l, int c, int n){
	if(access[l][c] || matrix[l][c] == '0') return;
	if(l < 0 || c < 0 || l >= n || c >= n) return;

	access[l][c] = 1;

	bt(l - 1, c, n);
	bt(l + 1, c, n);
	bt(l, c - 1, n);
	bt(l, c + 1, n);
	bt(l - 1, c - 1, n);
	bt(l - 1, c + 1, n);
	bt(l + 1, c - 1, n);
	bt(l + 1, c + 1, n);
}

int main(){

	int n, x = 0, eagles;

	while(cin >> n){
		getchar();
		startIt();
		int eagles = 0, xx;

		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
			getchar();
		}

		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if( !access[i][j] && matrix[i][j] == '1' ){
					bt(i, j, n);
					eagles++;
				}
			}
		}

		// for(int i = 0; i < n; i++){
		// 	for(int j = 0; j < n; j++){
		// 		cout << access[i][j];
		// 	}
		// 	cout << endl;
		// }

		cout << "Image number " << ++x << " contains " << eagles << " war eagles.\n"; 
	}



	return 0;
}