#include <stdio.h>

void verificar(int l, int c, int tabuleiro[101][101], int respostas[101][101], int pi, int pj){
	int count = 0;

	if(tabuleiro[pi][pj]){
		respostas[pi][pj] = 9;
		return;
	}

	if(pi - 1 >= 0 && tabuleiro[pi - 1][pj]) count++;
	if(pj - 1 >= 0 && tabuleiro[pi][pj - 1]) count++;
	if(pj + 1 < c && tabuleiro[pi][pj + 1]) count++;
	if(pi + 1 < l && tabuleiro[pi + 1][pj]) count++;

	respostas[pi][pj] = count;
}

void main(){

	int tabuleiro[101][101];
	int respostas[101][101];
	int l, c, i, j;

	while(scanf("%d %d\n", &l, &c) != EOF){

		for(i = 0; i < l; i++){
			for(j = 0; j < c; j++){
				scanf("%d", &tabuleiro[i][j]);
			}
		}

		for(i = 0; i < l; i++){
			for(j = 0; j < c; j++){
				verificar(l, c, tabuleiro, respostas, i, j);
			}
		}

		for(i = 0; i < l; i++){
			for(j = 0; j < c; j++){
				printf("%d", respostas[i][j]);
			}
			printf("\n");
		}

	}

}
