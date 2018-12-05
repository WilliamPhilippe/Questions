#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int j, p;
    scanf("%d %d\n", &j, &p);
    int matriz[j][p];
    int vetor[p], cont1 = 0, cont2 = 0;
    
    int linhas, colunas;
    
    for(linhas = 0; linhas < j; linhas++){
        for(colunas = 0; colunas < p; colunas++){
            scanf("%d", &matriz[linhas][colunas]);
            if(matriz[linhas][colunas] > 0) cont1++;
        }
        if(cont1 == p) cont2++;
        
        cont1 = 0;
    }
    
    printf("%d\n", cont2);
    
    
    
	return 0;
}