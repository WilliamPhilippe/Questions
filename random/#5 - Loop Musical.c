#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int loop(int vetor[], int n){
    int sinal, ant, pm, count = 1;
    int i;
    
    ant = vetor[0] - vetor[1];
    if(ant > 0) ant = 1;
    else ant = -1;
    pm = ant;
    
    for(i = 1; i < n; i++){
        if( (vetor[i%n] - vetor[(i + 1)%n]) > 0) sinal = 1;
        else sinal = -1;
        if(sinal != ant) count++;
        ant = sinal;
    }
    if(pm == ant) --count;
    return count;
}

int main() {
    int n, i;
    
    while(1){
        scanf("%d\n", &n);
        if(n == 0) break;
        int vetor[n];
        for(i = 0; i < n; i++) scanf("%d", &vetor[i]);
        printf("%d\n", loop(vetor, n));
    }


	return 0;
}