#include <bits/stdc++.h>
using namespace std;

char matrix[100][100];
int n, m, gameMod, fruits = 0, fruitsEatten = 0;
char commands[200];

void readMatrix(){

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			matrix[i][j] = getchar(); getchar();
			if(matrix[i][j] == 'O') fruits++;
		}
	}

}

int main(){

	cin >> n >> m; getchar();
	readMatrix();
	cin >> gameMod; getchar();
	gets(commands);

	for(int i = 0; i < n; i++) {
		for( int j = 0 ; j < m; j++){
			cout << matrix[i][j];
			cout << " ";
		}
		cout << endl;
	}

	for(int i = 0; i < strlen(commands); i++){
		cout << commands[i];
	}

	return 0;
}