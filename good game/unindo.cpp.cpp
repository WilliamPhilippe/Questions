#include <bits/stdc++.h>
using namespace std;

void unindoCelulas(int *startIt, int n, int q){
	if(q == 0 || n == 0) return;


	int unC; cin >> unC;
	int newA[n - 1];
	int inicioArrayAnterior = 0;

	if(unC == n - 1){
		inicioArrayAnterior++;
		startIt[unC] += startIt[0];

		for(int i = 0; i < (n - 1); i++){
			newA[i] = startIt[inicioArrayAnterior++];
		}
	}
	else{

		for(int i = 0; i < (n - 1); i++){
			if(i == unC){
				newA[i] = startIt[inicioArrayAnterior] + startIt[inicioArrayAnterior + 1];
				inicioArrayAnterior += 2;
			}
			else{
				newA[i] = startIt[inicioArrayAnterior];
				inicioArrayAnterior++;
			}
		}

	}

	// cout << " ---> ";
	// for(int i = 0; i < (n - 1); i++){ 
		// if(i == 0) cout << newA[i]; 
		// else cout << " " << newA[i];
	// } cout << endl;

	int minIndex = 0, finalIt[n - 1];
	for(int i = 0; i < (n - 1); i++) if(newA[i] < newA[minIndex]) minIndex = i;

	for(int i = minIndex, newIndex = 0; i == minIndex || i%(n-1) != minIndex; i++, newIndex++){
		finalIt[newIndex] = newA[i%(n-1)];

		if(i == minIndex) cout << finalIt[newIndex];
		else cout << " " << finalIt[newIndex];
	} cout << endl;

	unindoCelulas(finalIt, n - 1, q - 1);
}

int main(){
	int n, q;
	cin >> n >> q;

	int startIt[n], finalIt[n];
	int minIndex = 0;

	for(int i = 0; i < n; i++){
		cin >> startIt[i];
		if (startIt[i] < startIt[minIndex]) minIndex = i;
	}

	if (n == 1) {cout << startIt[0] << endl; return 0;}


	for (int i = minIndex, newIndex = 0; i == minIndex || i%n != minIndex ; i++, newIndex++){
		finalIt[newIndex] = startIt[i%n];

		if(i == minIndex) cout << finalIt[newIndex];
		else cout << " " << finalIt[newIndex];
	}
	cout << endl;

	unindoCelulas(finalIt, n, q);

	return 0;
}