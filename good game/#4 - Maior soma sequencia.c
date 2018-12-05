#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int i = 0, cresc = 0, count = 0, maior = -10000000, negativo = 0;
    int q, ini, menor = 0;
    scanf("%d\n", &q);
    int v[q];
    
    for(i=0; i < q; i++){
        scanf("%d\n", &v[i]);
        if(v[i] < 0) negativo++;
    }
if(negativo == q){
    for(i = 0; i < q; i++){
        
        if(v[i] > maior) maior = v[i];
    }
}    
else{
    for(ini = 0; ini < q; ini++){
        cresc = 0;
        for(i = ini, count = 0; count < q; i++, count++){
            if(i == q) i = 0;
            
            if(v[i] <= menor){
                menor = v[i];
                if(maior < cresc) maior = cresc;
                cresc = 0;
            }
            else{
                cresc += v[i];
                if(maior < cresc) maior = cresc;
            }
        }
    }        
       
}
    if(q == 1) printf("%d\n", v[0]);
    else
    printf("%d\n", maior);

    
	return 0;
}