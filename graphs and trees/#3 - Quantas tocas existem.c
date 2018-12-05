#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n, i;
    scanf("%d\n", &n);
    int vetor[n];
    int indice[10000] = {0};
    for(i = 0; i < n; i++) scanf("%d", &vetor[i]);
    int posini = 0, pos = 0, ciclo = 0;
    
    
    for(i = 0; i < n; i++){
    if(indice[i] == 0){    
        pos = i;
        posini = i;
        while(1){
            indice[pos] = 1;
            pos = vetor[pos];
            indice[pos] = 1;
            if(vetor[pos] == posini){
                ciclo++;
                break;
            }
        }
    }
    } 
    
    printf("%d\n", ciclo);
    
	return 0;
}