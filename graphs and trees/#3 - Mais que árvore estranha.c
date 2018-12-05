#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int arvore[1000000][2];

int maximo(int a, int b){
    return a > b ? a : b;
}

int altura(int no){
    if(no == -1) return 0;
    
    return 1 + maximo( altura(arvore[no][0]), altura(arvore[no][1]));
}

int main() {
    int nos, filhos, raiz, i;
    int a, b, c;
    scanf("%d %d %d\n", &nos, &filhos, &raiz);
    
    for(i = 0; i < 1000000; i++){
        arvore[i][0] = -1; arvore[i][1] = -1;
    }
    
    for(i = 0; i < filhos; i++){
        scanf("%d %d %d\n", &a, &b, &c);
        arvore[a][0] = b; arvore[a][1] = c;
    }
    
    printf("%d\n", altura(raiz));
    
	return 0;
}
