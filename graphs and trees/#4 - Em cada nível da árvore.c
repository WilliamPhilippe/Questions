#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int arvore[1000000][3];
int valores[1000000][2];
int maiornivel = 0;

void verificar(int no, int nivel){
    if(no == -1) return;
    
    if(arvore[no][0] > valores[nivel][1]) valores[nivel][1] = arvore[no][0];
    if(arvore[no][0] < valores[nivel][0]) valores[nivel][0] = arvore[no][0];
    if(nivel > maiornivel) maiornivel = nivel;
    
    verificar(arvore[no][1], nivel + 1);
    verificar(arvore[no][2], nivel + 1);
}

int main() {
    int n, i;
    scanf("%d", &n);
    
    for(i = 0; i <= (n + 5); i++){
        valores[i][0] = 100000;
        valores[i][1] = -100000;
    }
    
    for(i = 0; i < n; i++){
        scanf("%d %d %d\n", &arvore[i][0], &arvore[i][1], &arvore[i][2]);
    }
    
    verificar(0, 1);
    
    for(i = 1; i <= maiornivel; i++){
        printf("Nivel %d: Maior = %d, Menor = %d\n", i, valores[i][1], valores[i][0]);
    }
	return 0;
}
