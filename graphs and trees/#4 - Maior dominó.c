#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int visitados[10000];

int visitar(int *vetor, int n, int maior, int pos){
    if(visitados[pos] == 1) return maior;
    
    visitados[pos] = 1;
    
    if(pos > maior) maior = pos;
    if(vetor[pos] > maior) maior = pos;
    
    visitar(vetor, n, maior, vetor[pos]);
}

int main() {
    int n, i;
    scanf("%d", &n);
    int vetor[n + 1];
    
    
    for(i = 1; i <= n; i++) scanf("%d", &vetor[i]);
    
    for(i = 1; i <= n; i++){
        memset(visitados, 0, sizeof(visitados));
        printf("%d\n", visitar(vetor, n, 0, i));
    }
	return 0;
}