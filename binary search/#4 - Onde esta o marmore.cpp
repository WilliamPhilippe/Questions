#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int main(){

	
	int n, m, cases = 0;
	int vetores[10001];

while(1){
    memset(vetores, 0, sizeof(vetores));	
	cin >> n >> m;
	if(n == 0 && m == 0) break;
	cases++;

	int recebe[n];

	int x;
	for(int i = 1; i <= n; i++){
		cin >> recebe[i - 1];
	}

	sort(recebe, recebe + n);
	for(int i = 0; i < n; i++){
		if( vetores[ recebe[i] ] == 0) vetores[ recebe[i] ] = i + 1;
	}

	cout << "CASE# " << cases << ':' << endl;
	for(int i = 0; i < m; i++){
		cin >> x;
		if( vetores[x] ) cout << x << " found at " << vetores[x] << endl;
		else cout << x << " not found" << endl;
	}

}


	return 0;
}