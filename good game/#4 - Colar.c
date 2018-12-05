#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n, i, j, ini, count = 1;
    //direita
    int direita = 0, mdireita = 0, posdir = 0;
    //esquerda
    int esquerda = 0, mesquerda = 0, posesq = 0;
    //soma
    int soma = 0, msoma = 0, possoma = 0, ifinal;
    scanf("%d\n", &n);
    char colar[n], posfinal;
    scanf("%s", colar);
    
    for(ini = 0; ini < n; ini++){
        for(i = ini, count = 1; count <= n; i++, count++){
            if(i == n) i = 0;
            if(colar[ini] == colar[i] || colar[i] == 'w'){
                direita++;
                posdir = ini;
                
            }
            else break;
        }
        if(colar[i] == 'b' || colar[i] == 'r') posfinal = colar[i];
        ifinal = i - 1;
        
        for(i = ini - 1, count = 1; count <= n; i--, count++){
            if(i == -1) i = (n - 1);
            if(ini == 0 && count == 1) j = (n - 1);
            else j = ini - 1;
            
            if( ((colar[j] == colar[i] || colar[i] == 'w') && i != ifinal) || (colar[j] == 'w' && i != ifinal && colar[i] == posfinal) ){
                esquerda++;
                posesq = j;
            }
            else break;
        }
        
        soma = esquerda + direita;
        if(soma > msoma){
            msoma = soma;
            possoma = ini;
        }
        
        
        direita = 0;
        esquerda = 0;
    }
    
    
    //printf("%d %d ifinal: %d - %c", possoma, msoma, ifinal, posfinal);
    printf("%d\n", msoma);
	return 0;
}