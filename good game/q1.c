#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

int n, m, k, vezes = 0;
char matrix[105][105];
char string[100];
char caminho[105][105];

void readMatrix(){
	int i, j;

	for (i = 0; i < n; i++){
		for(j = 0; j < m; j++){
			matrix[i][j] = getchar();
		}
		getchar();
	}
}

void limparcaminho(){
	int i, j;
	for(i = 0; i < n; i++){
		for(j = 0; j < m; j++){
			caminho[i][j] = ' ';
		}
	}
}

void runbt(int l, int c, int p){
	if(caminho[l][c] == '#') return;
	if(matrix[l][c] != string[p]) return;
	caminho[l][c] = '#';
	
	if(p + 1 == k && matrix[l][c] == string[p]){
		vezes++;
		return;
	}

	//cima
	if(l - 1 >= 0 && caminho[l - 1][c] != '#'){
		if(matrix[l - 1][c] == string[p + 1]){
			runbt(l - 1, c, p + 1);
			caminho[l - 1][c] = ' ';
		}
	}

	//baixo
	if(l + 1 < n && caminho[l + 1][c] != '#'){
		if(matrix[l + 1][c] == string[p + 1]){
			runbt(l + 1, c, p + 1);
			caminho[l + 1][c] = ' ';
		}
	}

	// esquerda
	if(c - 1 >= 0 && caminho[l][c - 1] != '#'){
		if(matrix[l][c - 1] == string[p + 1]){
			runbt(l, c - 1, p + 1);
			caminho[l][c - 1] = ' ';
		}
	}

	// direita
	if(c + 1 < m && caminho[l][c + 1] != '#'){
		if(matrix[l][c + 1] == string[p + 1]){
			runbt(l, c + 1, p + 1);
			caminho[l][c + 1] = ' ';
		}
	}

}

void iniciar(){
	limparcaminho();
	int l, c;
	int i, j;
	
	for(i = 0; i < n; i++){
		for(j = 0; j < m; j++){
			if(matrix[i][j] == string[0]){
				runbt(i, j, 0);
				limparcaminho();
			}
		}
	}
}

void main(){

	scanf("%d %d %d\n", &n, &m, &k);
	readMatrix();
	gets(string);

	iniciar();
	printf("%d\n", vezes);
}
