#include <stdio.h>
#include <string.h>

struct dados
{
		int tamanho;
		char lado;
		int visitado;
};

int verificar(struct dados *botas, int n, int ini){

	int i, j;

	for(i = ini; i < n; i++){
		if( (botas + i)->visitado == 0 ){
			if( (botas + i)->lado != (botas + ini)->lado && (botas + i)->tamanho == (botas + ini)->tamanho ){
				(botas + i)->visitado = 1;
				return 1;
			}
		}
	}

	return 0;
}

void main(){
	

	int n, i, count;

	while(1){
		scanf("%d\n", &n);
		if(n == -1) break;
		struct dados botas[10000];

		for(i = 0; i < n; i++){
			scanf("%d %c\n", &botas[i].tamanho, &botas[i].lado);
			botas[i].visitado = 0;
		}

		count = 0;

		for(i = 0; i < n; i++){
			if(botas[i].visitado == 0){
				botas[i].visitado = 1;
				count += verificar(botas, n, i);
			}
		}

		printf("%d\n", count);
	}
}