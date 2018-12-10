#include <bits/stdc++.h>
using namespace std;

bool f (char i, char j) { return (i>j); }

int main(){

	int t;
	scanf("%d\n", &t);

	for(int i = 1; i <= t; i++){
		char vetor[102];
		for(int i = 0; i < 102; i++){
			vetor[i] = 0;
		}
		char x; int j;
		j = 0;

		gets(vetor);
		j = strlen(vetor);

		sort(vetor, vetor + j, f);

		cout << "Caso " << i << ": ";
		for(int h = 0; h < j; h++){
			cout << vetor[h];
		}
		cout << endl;

	}

	return 0;
}