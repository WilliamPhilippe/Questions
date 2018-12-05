#include <stdio.h>

int matriz[2][10];
int tam;

int max(int a, int b){
	if(a > b) return a;
	if(b >= a) return b;
}

int backtracking(int col, int valor, int peso){
	if(peso < 0) return 0;
	if(col == tam){
		if(valor) return valor;
		else return 0;
	}

	return max( backtracking(col + 1, valor + matriz[0][col], peso - matriz[1][col]), backtracking(col + 1, valor, peso));
}

void main(){
	int i, j, p;

	scanf("%d %d\n", &tam, &p);

	for(i = 0; i < 2; i++){
		for(j = 0; j < tam; j++){
			scanf("%d", &matriz[i][j]);
		}
	}

	printf("%d\n", backtracking(0, 0, p));
}