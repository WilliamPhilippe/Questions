#include <stdio.h>


void build_candidates(int *vetor, int col, int n, int *candidatos, int *ncandidatos){

	int i, j, value = 1;
	(*ncandidatos) = 0;

	for( i = 1; i <= n; i++ ){

		for(j = 1, value = 1; j < col && value; j++){
			if( vetor[j] == i ){
				value = 0;
			}
		}

		if(value){
			candidatos[ *ncandidatos ] = i;
			(*ncandidatos)++;
		}
	}
}

void backtracking(int *vetor, int col, int n){

	if(col == n + 1){
		int i;
		for(i = 1; i <= n; i++){
			printf("%d", vetor[i]);
		}
		printf("\n");
	}

	int candidatos[n];
	int ncandidatos;
	int i;

	build_candidates(vetor, col, n, candidatos, &ncandidatos);



	for(i = 0; i < ncandidatos; i++){

		vetor[col] = candidatos[i];
		backtracking(vetor, col + 1, n);
	}

}

void main(){
	
	int n, i;
	scanf("%d\n", &n);
	int vetor[n + 1];

	backtracking(vetor, 1, n);

}