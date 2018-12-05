#include <bits/stdc++.h>

using namespace std;

int busca(int *vetor, int sand, int fatia, int pessoas){

	int i, j, n;

	for(i = (sand - 1), n = 0; i >= 0; i--){

		if(vetor[i]/fatia == 0) return 0;

		n += vetor[i]/fatia;
		if(n >= pessoas) return 1;
	}

	return 0;
}

int main(){

	int pessoas, sand, tot = 0;
	cin >> pessoas >> sand;
	int vetor[sand];

	for(int i = 0; i < sand; i++){
		cin >> vetor[i];
		tot += vetor[i];
	}

	int fatia = tot/pessoas;

	sort(vetor, vetor + sand);

	while( fatia ){

		if( busca(vetor, sand, fatia, pessoas) ){
			cout << fatia << endl;
			return 0;
		}

		fatia --;
	}

	cout << fatia << endl;

	return 0;
}