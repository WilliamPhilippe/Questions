#include <stdio.h>

int pa(int vetor[], int n){
	int i, pa = 1, ant, value;
	value = 0;
	ant = vetor[1] - vetor[0];

	for(i = 1; i < n; i++){
		if((vetor[i] - vetor[i - 1]) != ant && value == 0){
			pa++;
			value = 1;
		}
		else if(value){
			ant = vetor[i] - vetor[i - 1];
			value = 0;
		}
	}

	return pa;
}


void main(){
	int n, i;
	scanf("%d\n", &n);
	int vetor[n];

	for(i = 0; i < n; i++) scanf("%d", &vetor[i]);

	printf("%d\n", pa(vetor, n));
}
