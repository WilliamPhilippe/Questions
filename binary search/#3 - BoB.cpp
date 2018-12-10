#include <bits/stdc++.h>
using namespace std;

long int *vetor = (long int *) malloc(263000 * sizeof(long int));

void busca(int inicio, int fim, int &vezes, int element){
	int end = fim + 1;
	int meio;

	while(inicio <= fim){
		meio = (inicio + fim)/2;

		if(vetor[meio] < element){
			inicio = meio + 1;
		}
		else if(vetor[meio] > element){
			fim = meio - 1;
		}
		else{

			vezes++;
			for(int i = meio + 1; i < end; i++){
				if(vetor[i] == element) vezes++;
				else break;
			}
			for(int i = meio - 1; i >= 0; i--){
				if(vetor[i] == element) vezes++;
				else break;
			}

			return;
		}
	}

	return;
}

int main(){

	int t, n, q;
	cin >> t;

	for(int i = 1; i <= t; i++){
		cin >> n >> q;
		for(int j = 0; j < n; j++){
			cin >> vetor[j];
		}

		cout << "caso " << i << ':' << endl;
		for(int j = 0; j < q; j++){
			int vezes = 0, x;
			cin >> x;
			busca(0, n - 1, vezes, x);
			cout << vezes << endl;
		}

	}




	return 0;
}