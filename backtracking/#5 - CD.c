#include <stdio.h>
#include <string.h>

int solucao[20] = {0};
int music[20] = {0};
int fita, cd, tam_atual = -1, sum_final;

void processar_solucao(int *solucao_atual, int col, int sum_atual){
	int i;

	if(sum_atual > sum_final){
		for(i = 0; i < col; i++){
			solucao[i] = solucao_atual[i];
		}
		tam_atual = col;
		sum_final = sum_atual;
		return;
	}

	if(col > tam_atual && sum_final <= sum_atual){
		for(i = 0; i < col; i++){
			solucao[i] = solucao_atual[i];
		}
		tam_atual = col;
		sum_final = sum_atual;
	}
}

void formar_candidatos(int *solucao_atual, int col, int sum_atual, int *candidatos, int *ncandidatos){
	int i, j, value;

	for(i = col; i < cd; i++){
		if( music[i] + sum_atual <= fita ){

			value = 1;
			for(j = 0; j < col && value; j++){
				if(solucao_atual[j] == music[i])
					value = 0;
			}

			if(value){
				candidatos[*ncandidatos] = music[i];
	 			( *ncandidatos ) ++;
	 		}
		}
	}

}

void backtracking(int *solucao_atual, int col, int sum_atual){

	int candidatos[cd];
	int ncandidatos = 0, i;

	formar_candidatos(solucao_atual, col, sum_atual, candidatos, &ncandidatos);

	if(ncandidatos == 0){
		processar_solucao(solucao_atual, col, sum_atual);
		return;
	}

	for(i = 0; i < ncandidatos; i++){
		solucao_atual[col] = candidatos[i];
		backtracking(solucao_atual, col + 1, sum_atual + candidatos[i]);
	}
}

void main(){

	int i;

	while( scanf("%d", &fita) != EOF ){
		scanf("%d", &cd);

		int solucao_atual[cd];
		int verificar_soma = 0;
		tam_atual = -1; sum_final = -1;

		for(i = 0; i < cd; i++){
			scanf("%d", &music[i]);
			verificar_soma += music[i];
		}

		if(verificar_soma <= fita){
			for(i = 0; i < cd; i++){
				printf("%d ", music[i]);
			}
			printf("sum:%d\n", verificar_soma);
		}
		else{
			backtracking(solucao_atual, 0, 0);

			for(i = 0; i < tam_atual; i++){
			 	printf("%d ", solucao[i]);
			}
			printf("sum:%d\n", sum_final);
		}

	}

}
