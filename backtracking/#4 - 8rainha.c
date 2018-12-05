#include <stdio.h>
#include <string.h>

int jo, io, solucao;

int faabs(int a){
	if(a >= 0) return a;
	return -a;
}

void printar(int *tabuleiro){
	
	int i;

	if(solucao < 10){
		printf(" %d     ", solucao);
		for(i = 1; i < 9; i++){
			printf(" %d", tabuleiro[i]);
		}
		printf("\n");
	}
	else{

		printf("%d     ", solucao);
		for(i = 1; i < 9; i++){
			printf(" %d", tabuleiro[i]);
		}
		printf("\n");

	}


}

void construir_candidatos(int *tabuleiro, int *candidatos, int *ncandidatos, int col){
	int i, j, value;
	(*ncandidatos) = 0;

	for(i = 1; i < 9; i++){

		value = 1;
		if( faabs(io - i) == faabs(col - jo) ){
			value = 0;
		}

		if(i == io) value = 0;

		for(j = 1; j < col && value; j++){
			if(tabuleiro[j] == i){
				value = 0;
			}
			if( faabs(j - col) == faabs(tabuleiro[j] - i)){
				value = 0;
			}
		}

		if( value == 1 ){
			candidatos[ *ncandidatos ] = i;
			(*ncandidatos) ++;
		}

	}
}

void backtracking(int *tabuleiro, int col){

	int j;
	int candidatos[8];
	int ncandidatos, i;

	if(col == jo) col++;

	if(col == 9){
		solucao++;
		printar(tabuleiro);
		return;
	}

	construir_candidatos(tabuleiro, candidatos, &ncandidatos, col);

	for(i = 0; i < ncandidatos; i++){

		tabuleiro[col] = candidatos[i];
		backtracking(tabuleiro, col + 1);
	}

}

void main(){

	int test;
	scanf("%d\n", &test);

	while(test--){
		int tabuleiro[9] = {0};
		scanf("%d %d\n", &io, &jo);
		tabuleiro[jo] = io;
		solucao = 0;

		printf("SOLN       COLUMN\n");
		printf(" #      1 2 3 4 5 6 7 8\n\n");

		backtracking(tabuleiro, 1);
		printf("\n");

	}
}
