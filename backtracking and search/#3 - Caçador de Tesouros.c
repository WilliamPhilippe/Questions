#include <stdio.h>
#include <string.h>

int l, c;
int maior_valor = 0;
char mapa[11][11], lixo;


int valorizar(char c){

	if(c == 'b') return 1;
	if(c == 'p') return 5;
	if(c == 'o') return 10;
	if(c == 'd') return 50;

	return 0;

}

void construir_candidatos(int caminho[][20], int linha, int col, int *candidatos_linha, int *candidatos_coluna, int *ncandidatos){

		if( col - 1 >= 0 && mapa[linha][col - 1] != '#' && caminho[linha][col - 1] == 0 ){
			candidatos_linha[*ncandidatos] = linha;
			candidatos_coluna[*ncandidatos] = col - 1;
			(*ncandidatos) ++;			
		}

		if( col + 1 < c && mapa[linha][col + 1] != '#' && caminho[linha][col + 1] == 0 ){
			candidatos_linha[*ncandidatos] = linha;
			candidatos_coluna[*ncandidatos] = col + 1;
			(*ncandidatos) ++;			
		}

		if( linha - 1 >= 0 && mapa[linha - 1][col] != '#' && caminho[linha - 1][col] == 0 ){
			candidatos_linha[*ncandidatos] = linha - 1;
			candidatos_coluna[*ncandidatos] = col;
			(*ncandidatos) ++;		
		}

		if( linha + 1 < l && mapa[linha + 1][col] != '#' && caminho[linha + 1][col] == 0 ){
			candidatos_linha[*ncandidatos] = linha + 1;
			candidatos_coluna[*ncandidatos] = col;
			(*ncandidatos) ++;		
		}
}

void backtracking(int caminho[][20], int linha, int col, int valor){

	if(mapa[linha][col] == '#') return;

	int aux[l][20];
	int i, j;

	for(i = 0; i < l; i++){
		for(j = 0; j < c; j++){
			aux[i][j] = caminho[i][j];
		}
	}
	aux[linha][col] = 1; 

	valor += valorizar( mapa[linha][col]);

	int candidatos_linha[4], candidatos_coluna[4];
	int ncandidatos = 0;

	construir_candidatos( aux, linha, col, candidatos_linha, candidatos_coluna, &ncandidatos);

	if(ncandidatos == 0){
		if(valor > maior_valor) maior_valor = valor;
		return;
	}

	for(i = 0; i < ncandidatos; i++){
		backtracking(aux, candidatos_linha[i], candidatos_coluna[i], valor);
	}
	
}

void main(){

	int j, i;

	scanf("%d %d\n", &l, &c);

	int caminho[l][20];

	for(i = 0; i < l; i++){
		for(j = 0; j < c; j++){
			caminho[i][j] = 0;
		}
	}

	for(i = 0; i < l; i++){
		for(j = 0; j < c; j++){
			scanf("%c", &mapa[i][j]);
		}
		scanf("%c", &lixo);
	}

	backtracking(caminho, 0, 0, 0);

	printf("%d\n", maior_valor);


}
