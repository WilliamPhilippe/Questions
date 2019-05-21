#include <bits/stdc++.h>
using namespace std;

char matrix[100][100];
int n, m, gameMod, fruits = 0, fruitsEatten = 0;
int lS, cS; 		// linha e coluna de onde a cobra esta
char commands[200];

void readMatrix(){

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			matrix[i][j] = getchar(); getchar();
			if(matrix[i][j] == 'O') fruits++;
			if(matrix[i][j] == '#') {lS = i; cS = j;}
		}
	}

}

void printMatrix(){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if(j == 0) cout << matrix[i][j];
			else cout << " " << matrix[i][j];
		}
		cout << endl;
	}
}

void gameModOne(){

	int commandIndex = 0, final;
	char c;

	while(true){

		if(commands[commandIndex] == 'N'){

			if(lS - 1 < 0 || matrix[lS - 1][cS] == '%'){  	// PERDEU
				printMatrix();
				cout << "\n - GAME OVER - \nNumero de frutas comidas: " << fruitsEatten;
				return;
			}

			if(matrix[lS - 1][cS] == 'O') fruits--, fruitsEatten++;
			matrix[lS][cS] = '.';
			matrix[--lS][cS] = '#';

			if(fruits == 0){
				printMatrix();
				cout << "\nParabens, voce venceu!\nNumero de frutas comidas: " << fruitsEatten;
				return; 
			}

		}
		else if(commands[commandIndex] == 'S'){

			if(lS + 1 >= n || matrix[lS + 1][cS] == '%'){  	// PERDEU
				printMatrix();
				cout << "\n - GAME OVER - \nNumero de frutas comidas: " << fruitsEatten;
				return;
			}

			if(matrix[lS + 1][cS] == 'O') fruits--, fruitsEatten++;
			matrix[lS][cS] = '.';
			matrix[++lS][cS] = '#';

			if(fruits == 0){
				printMatrix();
				cout << "\nParabens, voce venceu!\nNumero de frutas comidas: " << fruitsEatten;
				return; 
			}

		}
		else if(commands[commandIndex] == 'L'){

			if(cS + 1 >= m || matrix[lS][cS + 1] == '%'){  	// PERDEU
				printMatrix();
				cout << "\n - GAME OVER - \nNumero de frutas comidas: " << fruitsEatten;
				return;
			}

			if(matrix[lS][cS + 1] == 'O') fruits--, fruitsEatten++;
			matrix[lS][cS] = '.';
			matrix[lS][++cS] = '#';

			if(fruits == 0){
				printMatrix();
				cout << "\nParabens, voce venceu!\nNumero de frutas comidas: " << fruitsEatten;
				return; 
			}

		}
		else if(commands[commandIndex] == 'O'){

			if(cS - 1 < 0 || matrix[lS][cS - 1] == '%'){  	// PERDEU
				printMatrix();
				cout << "\n - GAME OVER - \nNumero de frutas comidas: " << fruitsEatten;
				return;
			}

			if(matrix[lS][cS - 1] == 'O') fruits--, fruitsEatten++;
			matrix[lS][cS] = '.';
			matrix[lS][--cS] = '#';

			if(fruits == 0){
				printMatrix();
				cout << "\nParabens, voce venceu!\nNumero de frutas comidas: " << fruitsEatten;
				return; 
			}

		}

		++commandIndex;
		if(commandIndex == strlen(commands)){
			printMatrix();
			cout << "\nNumero de frutas comidas: " << fruitsEatten;
			return; // TERMINARAM AS JOGADAS
		}
	}

}

void gameModTwo(){
	int commandIndex = 0, final;
	char c;

	while(true){

		if(commands[commandIndex] == 'N'){

			int newLS;
			lS - 1 < 0 ? newLS = n - 1 : newLS = lS - 1;

			if(matrix[newLS][cS] == '%'){  	// PERDEU
				printMatrix();
				cout << "\n - GAME OVER - \nNumero de frutas comidas: " << fruitsEatten;
				return;
			}

			if (matrix[newLS][cS] == 'O') fruits--, fruitsEatten++;
			matrix[lS][cS] = '.';
			matrix[newLS][cS] = '#';
			lS = newLS;

			if(fruits == 0){
				printMatrix();
				cout << "\nParabens, voce venceu!\nNumero de frutas comidas: " << fruitsEatten;
				return; 
			}

		}
		else if(commands[commandIndex] == 'S'){

			int newLS;
			lS + 1 >= n ? newLS = 0 : newLS = lS + 1;

			if(matrix[newLS][cS] == '%'){  	// PERDEU
				printMatrix();
				cout << "\n - GAME OVER - \nNumero de frutas comidas: " << fruitsEatten;
				return;
			}

			if (matrix[newLS][cS] == 'O') fruits--, fruitsEatten++;
			matrix[lS][cS] = '.';
			matrix[newLS][cS] = '#';
			lS = newLS;

			if(fruits == 0){
				printMatrix();
				cout << "\nParabens, voce venceu!\nNumero de frutas comidas: " << fruitsEatten;
				return; 
			}

		}
		else if(commands[commandIndex] == 'L'){

			int newCS;
			cS + 1 >= m ? newCS = 0 : newCS = cS + 1;

			if(matrix[lS][newCS] == '%'){  	// PERDEU
				printMatrix();
				cout << "\n - GAME OVER - \nNumero de frutas comidas: " << fruitsEatten;
				return;
			}

			if (matrix[lS][newCS] == 'O') fruits--, fruitsEatten++;
			matrix[lS][cS] = '.';
			matrix[lS][newCS] = '#';
			cS = newCS;

			if(fruits == 0){
				printMatrix();
				cout << "\nParabens, voce venceu!\nNumero de frutas comidas: " << fruitsEatten;
				return; 
			}

		}
		else if(commands[commandIndex] == 'O'){

			int newCS;
			cS - 1 < 0 ? newCS = m - 1 : newCS = cS - 1;

			if(matrix[lS][newCS] == '%'){  	// PERDEU
				printMatrix();
				cout << "\n - GAME OVER - \nNumero de frutas comidas: " << fruitsEatten;
				return;
			}

			if (matrix[lS][newCS] == 'O') fruits--, fruitsEatten++;
			matrix[lS][cS] = '.';
			matrix[lS][newCS] = '#';
			cS = newCS;

			if(fruits == 0){
				printMatrix();
				cout << "\nParabens, voce venceu!\nNumero de frutas comidas: " << fruitsEatten;
				return; 
			}

		}

		++commandIndex;
		if(commandIndex == strlen(commands)){
			printMatrix();
			cout << "\nNumero de frutas comidas: " << fruitsEatten;
			return; // TERMINARAM AS JOGADAS
		}
	}
}


int main(){

	cin >> n >> m; getchar();
	readMatrix();
	cin >> gameMod; getchar();
	gets(commands);
	gameMod == 1 ? gameModOne() : gameModTwo();


	// for(int i = 0; i < n; i++) {
	// 	for( int j = 0 ; j < m; j++){
	// 		cout << matrix[i][j];
	// 		cout << " ";
	// 	}
	// 	cout << endl;
	// }

	// for(int i = 0; i < strlen(commands); i++){
	// 	cout << commands[i];
	// }

	return 0;
}