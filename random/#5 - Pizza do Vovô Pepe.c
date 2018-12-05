#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int varrer(int *indice, int c, int ini, int pedaco, int n){
    int i, pro, boole = 1, quant = 0;
    int count = 0;
    for(i = ini; count < n; count++){
        pro = (i + pedaco - 1)%c;
        while(1){
            i = i%c;
            quant += indice[i];
            if(i == pro) break;
            ++i;
        }
        if(quant != 1){
            return boole = 0;
        }
        
        ini += pedaco;
        i = ini;
        i = i%c;
        quant = 0;
    }
    
    //printf("%d", ini);
    return boole;
}


int main() {
    int c, n, i, x, pedaco, boole = 0;
    int indice[100000] = {0};
    scanf("%d %d\n", &c, &n);
    for(i = 0; i < n; i++){
        scanf("%d", &x);
        indice[x] = 1;
    }
    
    pedaco = c/n;
    for(i = 0; i < c; i++){
        boole = varrer(indice, c, i, pedaco, n);
        if(boole == 1){
            printf("S\n");
            return 0;
        }
    }
    
    printf("N\n");
    return 0;
}